#include <iostream>
#include "CNetwork.h"
int main()
{
    CNetwork net;
    net.AddInputLayer(784);//�����784����ô�����������Ҫ����Ϊ784��1�е����ݣ�N������ʱ����784*N
    net.AddHiddenLayer(15);//������15
    net.AddOutputLayer(10);//�����10
    net.InitilizeWeightBias();
    net.OutputNetworkStruct();
    return 0;
}