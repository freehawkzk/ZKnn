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
    //所有层的数目计数
    static long slLayerCount;
    long m_lID;

    std::vector<CNeuron*> m_vpNeurons;//当前层所包含的神经元

    CLayer* m_pTop;//当前层的输出层
    CLayer* m_pBottom;//当前层的输入层

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

