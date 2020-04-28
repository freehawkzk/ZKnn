
#include <stdio.h>
#include <MNN/ImageProcess.hpp>
#include <MNN/Interpreter.hpp>
#include <MNN/Tensor.hpp>
#define MNN_OPEN_TIME_TRACE
#include <algorithm>
#include <fstream>
#include <functional>
#include <memory>
#include <sstream>
#include <vector>
#include <MNN/AutoTime.hpp>
#include "opencv2/opencv.hpp"
using namespace MNN;
using namespace MNN::CV;

int main(int argc, const char* argv[]) 
{
    if(argc < 3)
    {
        MNN_PRINT("please use program like this commond line.\n");
        MNN_PRINT("program model_path value.\n");
        return 0;
    }

    std::cout<<"program started"<<std::endl;
    std::string sval(argv[2]); //path to model file
    float fval = atof(sval.c_str()); // input value
    std::cout<<"you want to inference: "<< fval<<std::endl;

    // create net from model file
    std::shared_ptr<Interpreter> net(Interpreter::createFromFile(argv[1]));
    
    // configure network backend
    ScheduleConfig config;
    config.type  = MNN_FORWARD_CPU;
    auto session = net->createSession(config);

    // create a host tensor to convert the input value into a tensor
    std::vector<int> shape_{1,1};
    std::shared_ptr<MNN::Tensor> input_( MNN::Tensor::create<float>(shape_,&fval,MNN::Tensor::CAFFE));
    
    // get the network's input tensor in the device.
    auto input = net->getSessionInput(session, NULL);
    auto shape = input->shape();
    shape[0]   = 1;
    net->resizeTensor(input, shape);
    net->resizeSession(session);
    
    // get a pointer to the output tensor
    auto output = net->getSessionOutput(session, NULL);
    
    // copy data form host tensor to device tensor
    input->copyFromHostTensor(input_.get());

    // run net
    net->runSession(session);
    {

        auto dimType = output->getDimensionType();
        if (output->getType().code != halide_type_float) {
            dimType = Tensor::TENSORFLOW;
        }
        
        // copy data from device tensor to host tensor
        std::shared_ptr<Tensor> outputUser(new Tensor(output, dimType));
        MNN_PRINT("output size:%d\n", outputUser->elementSize());
        output->copyToHostTensor(outputUser.get());
        auto type = outputUser->getType();
        auto size = outputUser->elementSize();

        // get the out value
        std::vector<std::pair<int, float>> tempValues(size);
        if (type.code == halide_type_float) {
            auto values = outputUser->host<float>();
            for (int i = 0; i < size; ++i) {
                tempValues[i] = std::make_pair(i, values[i]);
            }
        }

        // output the result.
        std::cout<<"input value: "<<fval<<" output value: "<<tempValues[0].second<<std::endl;
    }
    return 0;
}
