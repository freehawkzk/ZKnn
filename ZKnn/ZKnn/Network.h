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
    //void Backward(std::vector<float>& lable);
    void UpdateBias();
    void UpdateWeights();
    void Release();
    float Loss(std::vector<float>& lable);
    std::vector<float> GetOutput();

    std::vector<float> Test(std::vector<float>& input);
    //void Train(std::vector<float>&input, std::vector<float>&lable);

    void Forward(std::vector < std::vector<float>>& inputs);
    void Backward(std::vector < std::vector<float>>& lables);
    void SetBatchSize(int nSize);
    //std::vector<float> Test(std::vector < std::vector<float>>& input);
    void Train(std::vector < std::vector<float>>&input, std::vector < std::vector<float>>&lable);
private:
    void SetInput(std::vector<float>& input);
    void SetInput(std::vector < std::vector<float>>& inputs);
    //void CalcDeltaOfOutputLayer(std::vector<float>& lable);
    void CalcDeltaOfOutputLayer(std::vector<std::vector<float>>& lables,int index);
};

