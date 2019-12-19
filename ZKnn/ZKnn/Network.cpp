#include "Network.h"
#include "Common.h"


CNetwork::CNetwork():m_fLearnRate(0.001)
{
}


CNetwork::~CNetwork()
{
}

void CNetwork::Release()
{
    for (int i=0;i<m_vpLayers.size();i++)
    {
        delete m_vpLayers[i];
        m_vpLayers[i] = nullptr;
    }
    m_vpLayers.clear();
}

void CNetwork::SetLearnRate(float lr)
{
    m_fLearnRate = lr;
}

void CNetwork::AddInputLayer(int nNum)
{
    Release();
    auto lay = CLayer::Create(nNum);
    m_vpLayers.push_back(lay);
}
void CNetwork::AddHiddenLayer(int nNum)
{
    auto lay1 = CLayer::Create(nNum);
    lay1->SetActivationFunc((ActivationFunc*)&Func_sigmoid);
    lay1->SetActivationPrimeFunc((ActivationPrimeFunc*)&Func_sigmoid_prime);
    
    auto lay0 = m_vpLayers[m_vpLayers.size() - 1];
    lay0->SetTopLayer(lay1);
    lay1->SetBottomLayer(lay0);
    m_vpLayers.push_back(lay1);
}

void CNetwork::AddOutputLayer(int nNum)
{
    auto lay1 = CLayer::Create(nNum);
    lay1->SetActivationFunc((ActivationFunc*)&Func_sigmoid);
    lay1->SetActivationPrimeFunc((ActivationPrimeFunc*)&Func_sigmoid_prime);
    
    auto lay0 = m_vpLayers[m_vpLayers.size() - 1];
    lay0->SetTopLayer(lay1);
    lay1->SetBottomLayer(lay0);
    m_vpLayers.push_back(lay1);
}

void CNetwork::InitilizeAllWeightAndBias()
{
    for (int i=0;i<m_vpLayers.size();i++)
    {
        auto lay = m_vpLayers[i];
        for (int j=0;j<lay->m_vpNeurons.size();j++)
        {
            lay->m_vpNeurons[j]->m_fB = GetRandValue();
        }
    }
}
void CNetwork::OutputNetworkStruct()
{

}

void CNetwork::Forward(std::vector<float>& input)
{
    SetInput(input);
    for (int i=1;i<m_vpLayers.size();i++)
    {
        m_vpLayers[i]->Forward();
    }
}

void CNetwork::Backward(std::vector<float>& lable)
{
    CalcDeltaOfOutputLayer(lable);
    for (int i = m_vpLayers.size()-2; i>0;i--)
    {
        m_vpLayers[i]->Backward();
    }
}

void CNetwork::SetInput(std::vector<float>& input)
{
    auto layin = m_vpLayers[0];
    for (int i = 0; i < layin->m_vpNeurons.size(); i++)
    {
        layin->m_vpNeurons[i]->m_fA = input[i];
    }
}

void CNetwork::CalcDeltaOfOutputLayer(std::vector<float>& lable)
{
    auto layout = m_vpLayers[m_vpLayers.size() - 1];
    for (int i=0;i<layout->m_vpNeurons.size();i++)
    {
        layout->m_vpNeurons[i]->m_fDelta = (layout->m_vpNeurons[i]->m_fA - lable[i])*layout->m_vpNeurons[i]->m_fActPrimeZ;
    }
}

void CNetwork::UpdateBias()
{
    for (int i = m_vpLayers.size()-2;i >0;i--)
    {
        m_vpLayers[i]->UpdateBias(m_fLearnRate);
    }
}

void CNetwork::UpdateWeights()
{
    for (int i = m_vpLayers.size() - 2; i > 0; i--)
    {
        m_vpLayers[i]->UpdateWeights(m_fLearnRate);
    }
}

float CNetwork::Loss(std::vector<float>& lable)
{
    auto outlay = m_vpLayers[m_vpLayers.size() - 1];
    float fsum = 0;
    for (int i=0;i<outlay->m_vpNeurons.size();i++)
    {
        fsum += ((outlay->m_vpNeurons[i]->m_fA - lable[i])*(outlay->m_vpNeurons[i]->m_fA - lable[i]));
    }
    fsum /= 2.0;
    return fsum;
}

std::vector<float> CNetwork::GetOutput()
{
    auto outlay = m_vpLayers[m_vpLayers.size() - 1];
    std::vector<float> res;
    float fsum = 0;
    for (int i = 0; i < outlay->m_vpNeurons.size(); i++)
    {
        res.push_back(outlay->m_vpNeurons[i]->m_fA);
    }
    return std::move(res);
}

std::vector<float> CNetwork::Test(std::vector<float>& input)
{
    Forward(input);
    auto res = GetOutput();
    return std::move(res);
}
void CNetwork::Train(std::vector<float>&input, std::vector<float>&lable)
{
    Forward(input);
    Backward(lable);
    UpdateBias();
    UpdateWeights();
}