#include "CPerceptron.h"



CPerceptron::CPerceptron()
{
}


CPerceptron::~CPerceptron()
{
}

bool CPerceptron::Computer()
{
    float fsum = 0;
    for (int i=0;i<vInputs.size(); i++)
    {
        fsum += (vInputs[i] * vWeights[i]);
    }
    if (fsum > fThresh)
        bOutput = true;
    else
        bOutput = false;
    return bOutput;
}
