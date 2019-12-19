#include "Layer.h"
#include <iostream>

long CLayer::slLayerCount = 0;


CLayer::CLayer():m_lID(CLayer::slLayerCount++)\
,m_pTop(nullptr)\
,m_pBottom(nullptr)
{
    m_vpNeurons.clear();
}

CLayer::~CLayer()
{
    for (int i=0;i<m_vpNeurons.size();i++)
    {
        delete m_vpNeurons[i];
        m_vpNeurons[i] = nullptr;
    }
    m_vpNeurons.clear();
    std::cout << "Destory Layer " << m_lID << std::endl;
}

CLayer* CLayer::Create(int nNum)
{
    auto p = new CLayer();
    for (int i=0;i<nNum;i++)
    {
        p->m_vpNeurons.push_back(CNeuron::Create());
    }
    std::cout << "Create Layer " << p->m_lID  << std::endl;
    return p;
}

void CLayer::SetActivationFunc(ActivationFunc* pFunc)
{
    for (int i=0;i<m_vpNeurons.size(); i++)
    {
        m_vpNeurons[i]->SetActivationFunc(pFunc);
    }
}

void CLayer::SetActivationPrimeFunc(ActivationPrimeFunc* pFunc)
{
    for (int i=0;i<m_vpNeurons.size();i++)
    {
        m_vpNeurons[i]->SetActivationPrimeFunc(pFunc);
    }
}

void CLayer::SetTopLayer(CLayer* p)
{
    m_pTop = p;
    for (int i=0;i<m_vpNeurons.size();i++)
    {
        for (int j = 0; j< p->m_vpNeurons.size();j++)
        {
            m_vpNeurons[i]->m_mTopLink[p->m_vpNeurons[j]->m_lID] = GetRandValue();
            p->m_vpNeurons[j]->m_mBottomLink[m_vpNeurons[i]->m_lID] = GetRandValue();
        }
    }
}

void CLayer::SetBottomLayer(CLayer* p)
{
    m_pBottom = p;
    for (int i=0;i<m_vpNeurons.size();i++)
    {
        for (int j = 0;j<p->m_vpNeurons.size();j++)
        {
            m_vpNeurons[i]->m_mBottomLink[p->m_vpNeurons[j]->m_lID] = GetRandValue();
            p->m_vpNeurons[j]->m_mTopLink[m_vpNeurons[i]->m_lID] = GetRandValue();
        }
    }
}

void CLayer::Forward()
{
    for (int i=0;i<m_vpNeurons.size();i++)
    {
        m_vpNeurons[i]->Forward();
    }
}

void CLayer::Backward()
{
    for (int i=0;i<m_vpNeurons.size();i++)
    {
        m_vpNeurons[i]->Backward();
    }
}

void CLayer::UpdateBias(float lr)
{
    for (int i = 0; i < m_vpNeurons.size(); i++)
    {
        m_vpNeurons[i]->UpdateBias(lr);
    }
}
void CLayer::UpdateWeights(float lr)
{
    for (int i=0;i<m_vpNeurons.size();i++)
    {
        m_vpNeurons[i]->UpdateWeights(lr);
    }
}