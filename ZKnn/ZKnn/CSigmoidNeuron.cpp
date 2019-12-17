#include "CSigmoidNeuron.h"
#include "InterFuncs.h"
#include <iostream>

CSigmoidNeuron::CSigmoidNeuron()
{
    fBias = rand()*1.0f / RAND_MAX;
}


CSigmoidNeuron::~CSigmoidNeuron()
{
}

float CSigmoidNeuron::Run()
{
    std::cout << "Neuron " << nNeuronID << " Run" << std::endl;

    float fsum = 0;
    for (int i=0;i< vpBottom.size();i++)
    {
        fsum += (vpBottom[i]->fOutput * vWeights[i]);
    }
    fsum += fBias;
    fOutput = Func_Sigmoid(fsum);
    return fOutput;
}