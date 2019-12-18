#include <iostream>
#include "CNetwork.h"
int main()
{
    CNetwork net;
    net.AddInputLayer(784);//输入层784，那么输入的样本需要整理为784行1列的数据，N个样本时，是784*N
    net.AddHiddenLayer(15);//隐含层15
    net.AddOutputLayer(10);//输出层10
    net.InitilizeWeightBias();
    net.OutputNetworkStruct();
    return 0;
}