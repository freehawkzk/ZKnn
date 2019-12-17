#pragma once
#include <vector>
#include "CNeuron.h"
class CLayer
{
public:
    CLayer(int nNeuronNum);
    virtual ~CLayer();
    static int snLayCount;
    int nLayerID;
    int nBottomLayerID;
    int nTopLayerID;
    std::vector<CNeuron*> vpNeurons;
    void SetTopLayer(CLayer* pTopLayer);
    void SetBottomLayer(CLayer* pBottomLayer);

    virtual void Run();
};

