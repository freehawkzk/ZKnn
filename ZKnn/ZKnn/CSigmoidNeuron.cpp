#include "CSigmoidNeuron.h"
#include "InterFuncs.h"


CSigmoidNeuron::CSigmoidNeuron()
{
}


CSigmoidNeuron::~CSigmoidNeuron()
{
}

float CSigmoidNeuron::Compute()
{
    float fsum = 0;
    for (int i=0;i<vInputs.size();i++)
    {
        fsum += (vInputs[i] * vWeights[i]);
    }
    fsum += fBias;
    fOutput = Func_Sigmoid(fsum);
    return fOutput;
}