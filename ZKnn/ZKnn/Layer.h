#pragma once
#include <vector>
#include "Common.h"
#include "Neuron.h"
#include "opencv2/opencv.hpp"
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
    //void Backward();
    void UpdateBias(float lr);
    void UpdateWeights(float lr);

    void SetBatchSize(int nSize);
    void Forward(int index);
    void Backward(int index);
private:
    CLayer();

public:
    cv::Mat m_matW;
    cv::Mat m_matB;
    cv::Mat m_matZ;
    cv::Mat m_matPrimeZ;
    cv::Mat m_matA;
public:
    void ForwardMat();
};

