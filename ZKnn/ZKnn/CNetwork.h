#pragma once
#include <vector>
#include "opencv2/core.hpp"
class CLayer;
class CNetwork
{
public:
    CNetwork();
    ~CNetwork();

    std::vector<CLayer*> m_pvLayers;
    std::vector<cv::Mat> m_vWeights;
    std::vector<cv::Mat> m_vBiases;
    std::vector<cv::Mat> m_vZvalue;
    std::vector<cv::Mat> m_vOutputs;
    cv::Mat m_input;
    int m_nSampleNum=0;
    void AddInputLayer(int nNum);
    void AddHiddenLayer(int nNum);
    void AddOutputLayer(int nNum);

    void InitilizeWeightBias();

    void OutputNetworkStruct();

    void SetInput(cv::Mat& input);
    void Forward();
};

