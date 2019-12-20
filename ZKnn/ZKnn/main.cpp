#include <iostream>
#include "Network.h"
int main()
{
    CNetwork net;
    net.SetLearnRate(0.05);
    net.AddInputLayer(3);
    net.AddHiddenLayer(128);
    net.AddOutputLayer(2);
    net.InitilizeAllWeightAndBias();

    std::vector<std::vector<float>> inputs;
    std::vector<float> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(1);
    inputs.push_back(input);
    std::vector<std::vector<float>> lables;
    std::vector<float> lable;
    lable.push_back(1); lable.push_back(0);  lables.push_back(lable);
    for (int i=0;i<100;i++)
    {
        input[0] =  rand()*1.0 / RAND_MAX ;
        input[1] = rand()*1.0 / RAND_MAX ;
        input[2] =  rand()*1.0 / RAND_MAX ;
        lable[0] =( input[0]+input[1]+input[2])>1? 1:0; lable[1] = 1-lable[0]; 
        inputs.push_back(input);
        lables.push_back(lable);
    }
    

    int nTotal = 10000000;
    std::vector<float> ti{ 0.9,0.1,0.9 };
    std::vector<std::vector<float>> tis;
    tis.push_back(ti);
    for (int i=0;i<nTotal;i++)
    {
        //std::cout << i << std::endl;
        net.Train(inputs, lables);
        if (i % 100000 == 0)
        {
            auto res = net.Test(ti);
            std::cout << i;
            
            for (int j = 0; j < res.size(); j++)
            {
                std::cout << "\t\t" << res[j];
            }
            std::cout << std::endl;
        }
    }

    //std::vector<float> ti1{ 0.9,0.1,0.9 };
    //std::vector<std::vector<float>> tis1;
    //tis1.push_back(ti1);
    //auto res1 = net.Test(tis1);
    //for (int i = 0; i < res1.size(); i++)
    //{
    //    std::cout << res1[i] << std::endl;
    //}
    return 0;
}