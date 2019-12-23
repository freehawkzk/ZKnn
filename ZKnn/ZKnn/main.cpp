#include <iostream>
#include "Network.h"
#include "opencv2/opencv.hpp"
#include <fstream>
int main()
{
    CNetwork net;
    net.SetLearnRate(0.1);
    net.AddInputLayer(3);
    net.AddHiddenLayer(3);
    //net.AddHiddenLayer(16);
    //net.AddHiddenLayer(128);
    //net.AddHiddenLayer(16);
    net.AddOutputLayer(1);
    net.InitilizeAllWeightAndBias();

    std::vector<std::vector<float>> inputs;
    std::vector<float> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(1);
    inputs.push_back(input);
    std::vector<std::vector<float>> lables;
    std::vector<float> lable;
    lable.push_back(2); /*lable.push_back(0);*/  lables.push_back(lable);
    for (int i=0;i<1024;i++)
    {
        input[0] =  rand()*1.0 / RAND_MAX ;
        input[1] = rand()*1.0 / RAND_MAX ;
        input[2] =  rand()*1.0 / RAND_MAX ;
        lable[0] = (input[0] + input[1] + input[2]);// > 1 ? 1 : 0; 
        //lable[1] = 3 - lable[0];
        inputs.push_back(input);
        lables.push_back(lable);
    }
    

    int nTotal = 10000000;
    std::vector<float> ti{ 0.9,0.1,0.9 };
    std::vector<std::vector<float>> tis;
    tis.push_back(ti);
    std::ofstream of("log.log", std::ios::out);
    for (int i=0;i<nTotal;i++)
    {
        net.Train(inputs, lables);
        if (i % 10000 == 0)
        {
            auto res = net.Test(ti);
            std::cout << i;
            of << i;
            for (int j = 0; j < res.size(); j++)
            {
                std::cout << "\t\t" << res[j];
                //of << "\t\t" << res[j];
            }
            std::cout<< "\t\t" << net.m_fBatchLoss;
            of << "\t\t" << net.m_fBatchLoss;
            std::cout << std::endl;
            of << std::endl;
        }
    }
    of.close();
    return 0;
}