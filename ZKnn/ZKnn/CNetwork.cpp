#include "CNetwork.h"
#include "CInputLayer.h"
#include "CLayer.h"
#include "COutputLayer.h"
#include <iostream>

CNetwork::CNetwork()
{
}


CNetwork::~CNetwork()
{
    for (int i=0;i<m_pvLayers.size();i++)
    {
        delete m_pvLayers[i];
        m_pvLayers[i] = nullptr;
    }
    m_pvLayers.clear();
}

void CNetwork::AddInputLayer(int nNum)
{
    auto p = new CInputLayer(nNum);
    m_pvLayers.push_back(p);
    cv::Mat bias = cv::Mat::zeros(p->nNeuronCount, 1, CV_32FC1);
    m_vBiases.push_back(bias);
}
void CNetwork::AddHiddenLayer(int nNum)
{
    auto p = m_pvLayers[m_pvLayers.size() - 1];
    int nCol = p->nNeuronCount;
    auto p1 = new CLayer(nNum);
    m_pvLayers.push_back(p1);
    int nRow = p1->nNeuronCount;
    cv::Mat mWeights = cv::Mat::zeros(nRow, nCol, CV_32FC1);
    m_vWeights.push_back(mWeights);
    auto bias = cv::Mat::zeros(p1->nNeuronCount, 1, CV_32FC1);
    m_vBiases.push_back(bias);
}

void CNetwork::AddOutputLayer(int nNum)
{
    auto p = m_pvLayers[m_pvLayers.size() - 1];
    int nCol = p->nNeuronCount;
    auto p1 = new COutputLayer(nNum);
    m_pvLayers.push_back(p1);
    int nRow = p1->nNeuronCount;
    cv::Mat mWeights = cv::Mat::zeros(nRow, nCol, CV_32FC1);
    m_vWeights.push_back(mWeights);
    auto bias = cv::Mat::zeros(p1->nNeuronCount, 1, CV_32FC1);
    m_vBiases.push_back(bias);
}

void CNetwork::InitilizeWeightBias()
{
    for (auto it = m_vWeights.begin(); it!=m_vWeights.end();it++)
    {
        for (int r = 0;r < it->rows; r++)
        {
            for (int c =0; c < it->cols; c++)
            {
                it->at<float>(r, c) = (rand()*1.0f / RAND_MAX);
            }
        }
    }
    for (auto it = m_vBiases.begin(); it != m_vBiases.end(); it++)
    {
        for (int r = 0; r < it->rows; r++)
        {
            for (int c = 0; c < it->cols; c++)
            {
                it->at<float>(r, c) = (rand()*1.0f / RAND_MAX);
            }
        }
    }
}

void CNetwork::OutputNetworkStruct()
{
    for (auto it = m_pvLayers.begin(); it!= m_pvLayers.end(); it++)
    {
        auto p = *it;
        std::cout << "Layer id: " << p->nLayerID << " have "<<p->nNeuronCount<<" neurons"<<std::endl;
    }
    std::cout << "There are " << m_vWeights.size() << " weights" << std::endl;
    for (int i = 0;i<m_vWeights.size();i++)
    {
        std::cout << "weight \t" << i << "\trows:\t" << m_vWeights[i].rows << "\tcols\t" << m_vWeights[i].cols << std::endl;
    }
    std::cout << "There are " << m_vBiases.size() << " biases" << std::endl;
    for (int i = 0; i < m_vBiases.size(); i++)
    {
        std::cout << "bias \t" << i << "\trows:\t" << m_vBiases[i].rows << "\tcols\t" << m_vBiases[i].cols << std::endl;
    }
}

void CNetwork::SetInput(cv::Mat& input)
{
    m_input = input.clone();
    m_nSampleNum = m_input.cols;
    m_vZvalue.clear();
    m_vOutputs.clear();

}

void CNetwork::Forward()
{
}