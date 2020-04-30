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
        MNN_PRINT("program model_path imgpath.\n");
        return 0;
    }

    std::cout<<"program started"<<std::endl;
    std::string imgpath(argv[2]);
    std::cout<<"you want to inference: "<< imgpath<<std::endl;
    

    // create net from model file
    std::shared_ptr<Interpreter> net(Interpreter::createFromFile(argv[1]));
    
    // configure network backend
    ScheduleConfig config;
    config.type  = MNN_FORWARD_CPU;
    auto session = net->createSession(config);

    // get the network's input tensor in the device.
    auto input = net->getSessionInput(session, NULL);
    auto shape = input->shape();
    shape[0]   = 1;
    net->resizeTensor(input, shape);
    net->resizeSession(session);
    
    // get a pointer to the output tensor
    auto output = net->getSessionOutput(session, NULL);
    
    {
        auto dims    = input->shape();
        int inputDim = 0;
        int size_w   = 0;
        int size_h   = 0;
        int bpp      = 0;
        bpp          = input->channel();
        size_h       = input->height();
        size_w       = input->width();
        if (bpp == 0)
            bpp = 1;
        if (size_h == 0)
            size_h = 1;
        if (size_w == 0)
            size_w = 1;
        MNN_PRINT("input: w:%d , h:%d, bpp: %d\n", size_w, size_h, bpp);

        auto inputPatch = argv[2];
        int width, height, channel;
        auto img = cv::imread(imgpath.c_str(),cv::IMREAD_COLOR);
        if (img.empty()) {
            MNN_ERROR("Can't open %s\n", inputPatch);
            return 0;
        }
        // cv::resize(img,img,cv::Size(28,28));
        cv::cvtColor(img,img,cv::COLOR_BGR2GRAY);
        img = 255-img;
        width = img.cols;
        height = img.rows;
        channel = img.channels();
        MNN_PRINT("origin size: %d, %d\n", width, height);
        Matrix trans;
        // Set transform, from dst scale to src, the ways below are both ok
#ifdef USE_MAP_POINT
        float srcPoints[] = {
            0.0f, 0.0f,
            0.0f, (float)(height-1),
            (float)(width-1), 0.0f,
            (float)(width-1), (float)(height-1),
        };
        float dstPoints[] = {
            0.0f, 0.0f,
            0.0f, (float)(size_h-1),
            (float)(size_w-1), 0.0f,
            (float)(size_w-1), (float)(size_h-1),
        };
        trans.setPolyToPoly((Point*)dstPoints, (Point*)srcPoints, 4);
#else
        trans.setScale((float)(width-1) / (size_w-1), (float)(height-1) / (size_h-1));
#endif
        ImageProcess::Config config;
        config.filterType = BILINEAR;
         float mean[1]     = {0.0f};
         float normals[1] = {1/255.0f};
         ::memcpy(config.mean, mean, sizeof(mean));
         ::memcpy(config.normal, normals, sizeof(normals));
        config.sourceFormat = GRAY;
        config.destFormat   = GRAY;

        std::shared_ptr<ImageProcess> pretreat(ImageProcess::create(config));
        pretreat->setMatrix(trans);
        pretreat->convert((uint8_t*)img.data, width, height, 0, input);
    }
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
        float maxv = -1000000.0f;
        if (type.code == halide_type_float) {
            auto values = outputUser->host<float>();
            for (int i = 0; i < size; ++i) {
                tempValues[i] = std::make_pair(i, values[i]);
                // std::cout<<tempValues[i].first<<" "<<tempValues[i].second<<std::endl;
                if(maxv < tempValues[i].second)
                    maxv = tempValues[i].second;
            }
            // std::cout<<maxv<<std::endl;

            float fsum =0;
            for (size_t i = 0; i < size; i++)
            {
                tempValues[i].second = tempValues[i].second - maxv;
                fsum += exp(tempValues[i].second);
                tempValues[i].second = exp(tempValues[i].second);
            }
            
            for (size_t i = 0; i < size; i++)
            {
                tempValues[i].second /= fsum;
                // std::cout<<i<<" "<<tempValues[i].second<<std::endl;
            }

            int index = 0;
            maxv = tempValues[0].second;
            for (size_t i = 0; i < size; i++)
            {
                if(maxv < tempValues[i].second)
                {
                    index = i;
                    maxv = tempValues[i].second;
                }
            }
            
            std::cout<<"result: "<<index<<" sim is "<<maxv<<std::endl;

        }

    }
    return 0;
}
