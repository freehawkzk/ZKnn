#pragma once
#include "CLayer.h"
class COutputLayer :
    public CLayer
{
public:
    COutputLayer(int nNeuronNum);
    virtual ~COutputLayer();

    virtual void Run();
};

