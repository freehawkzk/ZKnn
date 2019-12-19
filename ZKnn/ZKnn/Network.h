#pragma once
#include "Layer.h"
class CNetwork
{
public:
    CNetwork();
    ~CNetwork();

    std::vector<CLayer*> m_vpLayers;
    float m_fLearnRate;

    void SetLearnRate(float lr);
    void AddInputLayer(int nNum);
    void AddHiddenLayer(int nNum);
    void AddOutputLayer(int nNum);

    void InitilizeAllWeightAndBias();
    void OutputNetworkStruct();

    void Forward(std::vector<float>& input);
    void Backward(std::vector<float>& lable);
    void UpdateBias();
    void UpdateWeights();
    void Release();
    float Loss(std::vector<float>& lable);
    std::vector<float> GetOutput();

    std::vector<float> Test(std::vector<float>& input);
    void Train(std::vector<float>&input, std::vector<float>&lable);
private:
    void SetInput(std::vector<float>& input);
    void CalcDeltaOfOutputLayer(std::vector<float>& lable);
};

