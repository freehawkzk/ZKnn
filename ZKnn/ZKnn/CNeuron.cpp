#include "CNeuron.h"
#include <iostream>
int CNeuron::snNeuronCount = 0;

CNeuron::CNeuron():nNeuronID(snNeuronCount++)
{
    std::cout << "Construct " << nNeuronID << " neuron" << std::endl;
}


CNeuron::~CNeuron()
{
    std::cout << "destruct " << nNeuronID << " neuron" << std::endl;
}

float CNeuron::Forward()
{
    float fwightedsum = 0;
    for (auto it = vpBottom.begin(); it!=vpBottom.end();it++)
    {
        fwightedsum += it->first->fOutput * (*(it->second));
    }
    fwightedsum += fBias;
    fZValue = fwightedsum;
    if (pActivateFunc != nullptr)
        fOutput = (*pActivateFunc)(fZValue);
    else
        fOutput = fZValue;
    return fOutput;
}
float CNeuron::Backward()
{
    if (vpTop.size() == 0)
    {

    }
    return 0;
}

void CNeuron::CalcDelta()
{
    if (vpTop.size() == 0)
    {
        fDelta = (fOutput - fLable)*((*pActivatePrimeFunc)(fZValue));
    }
    else
    {
        fDelta = 0;
        for (auto it = vpTop.begin();it!=vpTop.end();it++)
        {
            fDelta += it->first->fDelta*(*(it->second));
        }
        fDelta *= (*pActivatePrimeFunc)(fZValue);
    }
}

void CNeuron::AdjustBias()
{
    //fBias += fDelta;
}

void CNeuron::AdjustWeight()
{
    //for (auto it = vpBottom.begin(); it!= vpBottom.end(); it++)
    //{
    //    *(it->second) += it->first->fOutput*fDelta;
    //}
}

void CNeuron::SetActivateFunc(ActivateFunc* pFunc)
{
    pActivateFunc = pFunc;
}
void CNeuron::SetActivatePrimeFunc(ActivatePrimeFunc* pFunc)
{
    pActivatePrimeFunc = pFunc;
}