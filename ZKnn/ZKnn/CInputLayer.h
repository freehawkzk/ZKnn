#pragma once
#include "CLayer.h"
class CInputLayer :
    public CLayer
{
public:
    CInputLayer(int nNeuronNum);
    virtual ~CInputLayer();

    virtual void Run();
};

