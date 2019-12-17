#pragma once
#include "CNeuron.h"
class CSigmoidNeuron :
    public CNeuron
{
public:
    CSigmoidNeuron();
    virtual ~CSigmoidNeuron();
    virtual float Compute();
};

