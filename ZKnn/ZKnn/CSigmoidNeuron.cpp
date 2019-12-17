#include "CSigmoidNeuron.h"
#include "InterFuncs.h"
#include <iostream>

CSigmoidNeuron::CSigmoidNeuron()
{
    fBias = rand()*1.0f / RAND_MAX;
    fBias = 2 * fBias - 1;
}


CSigmoidNeuron::~CSigmoidNeuron()
{
}

float CSigmoidNeuron::Run()
{
    

    float fsum = 0;
    for (int i=0;i< vpBottom.size();i++)
    {
        fsum += (vpBottom[i]->fOutput * vWeights[i]);
    }
    fsum += fBias;
    fOutput = Func_Sigmoid(fsum);
    std::cout << "Neuron " << nNeuronID << " Run,output " <<fOutput<< std::endl;
    return fOutput;
}