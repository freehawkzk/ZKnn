#include <iostream>
#include "Network.h"
int main()
{
    CNetwork net;
    net.SetLearnRate(0.1);
    net.AddInputLayer(3);
    net.AddHiddenLayer(16);
    net.AddOutputLayer(3);
    net.InitilizeAllWeightAndBias();

    std::vector<float> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(1);

    std::vector<float> lable;
    lable.push_back(0);
    lable.push_back(1);
    lable.push_back(0);
    int nTotal = 10000000;
    for (int i=0;i<nTotal;i++)
    {
        net.Train(input, lable);
    }
    std::vector<float> ti{ 0.9,0.1,0.9 };
    auto res = net.Test(ti);
    for (int i=0;i<res.size();i++)
    {
        std::cout << res[i] << std::endl;
    }
    return 0;
}