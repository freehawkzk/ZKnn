#include "CPerceptron.h"



CPerceptron::CPerceptron()
{
}


CPerceptron::~CPerceptron()
{
}

float CPerceptron::Run()
{
    float fsum = 0;
    for (int i=0;i<vInputs.size(); i++)
    {
        fsum += (vInputs[i] * vWeights[i]);
    }
    fsum += fBias;
    if (fsum > 0)
        fOutput = 1;
    else
        fOutput = 0;
    return fOutput;
}
