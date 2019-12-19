#pragma once
#include <vector>
#include "Common.h"
#include "Neuron.h"

class CLayer
{
public:
    virtual ~CLayer();
    
    static CLayer* Create(int nNum);
    //////////////////////////////////////////////////////////////////////////
    //���в����Ŀ����
    static long slLayerCount;
    long m_lID;

    std::vector<CNeuron*> m_vpNeurons;//��ǰ������������Ԫ

    CLayer* m_pTop;//��ǰ��������
    CLayer* m_pBottom;//��ǰ��������

    void SetActivationFunc(ActivationFunc* pFunc);
    void SetActivationPrimeFunc(ActivationPrimeFunc* pFunc);

    void SetTopLayer(CLayer* p);
    void SetBottomLayer(CLayer* p);

    void Forward();
    void Backward();
    void UpdateBias(float lr);
    void UpdateWeights(float lr);
private:
    CLayer();
};

