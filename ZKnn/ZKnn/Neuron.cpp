#include "Neuron.h"
#include <iostream>

long CNeuron::slNeuronCount = 0;
std::map<long, CNeuron*> CNeuron::smNeuron;

CNeuron* CNeuron::Create()
{
    auto p=  new CNeuron();
    CNeuron::smNeuron.insert(std::pair<long, CNeuron*>(p->m_lID, p));
    return p;
}
CNeuron* CNeuron::GetNeuronByID(long id)
{
    auto it = CNeuron::smNeuron.find(id);
    if (it != CNeuron::smNeuron.end())
        return it->second;
    else
        return nullptr;
    return nullptr;
}


CNeuron::CNeuron():m_lID(CNeuron::slNeuronCount++)\
//,m_fB(0)\
//,m_fA(0)\
//,m_fActPrimeZ(0)\
//,m_fDelta(0)\
//,m_fZ(0)\
,m_pActivationFunc(nullptr)\
,m_pActivationPrimeFunc(nullptr)\
,m_nBatchSize(1)
{
    m_mBottomLink.clear();
    m_mTopLink.clear();
    //std::cout << "Neuron: " << m_lID << " Constructed" << std::endl;
}


CNeuron::~CNeuron()
{
    std::cout << "Neuron: " << m_lID << " destructed" << std::endl;
}

void CNeuron::SetActivationFunc(ActivationFunc* pFunc)
{
    m_pActivationFunc = pFunc;
}

void CNeuron::SetActivationPrimeFunc(ActivationPrimeFunc* pFunc)
{
    m_pActivationPrimeFunc = pFunc;
}

void CNeuron::Forward()
{
    float fsum = 0;
    for (auto it = m_mBottomLink.begin(); it != m_mBottomLink.end(); it++)
    {
        auto p = CNeuron::GetNeuronByID(it->first);
        fsum += (p->m_fA*it->second);
    }
    m_fZ = fsum + m_fB;
    m_fA = Func_sigmoid(m_fZ);
    m_fActPrimeZ = Func_sigmoid_prime(m_fZ);
}

//void CNeuron::Backward()
//{
//    float fsum = 0;
//    for (auto it = m_mTopLink.begin(); it!= m_mTopLink.end();it++)
//    {
//        auto p = CNeuron::GetNeuronByID(it->first);
//        fsum += ((p->m_fDelta * it->second)*m_fActPrimeZ);
//    }
//    m_fDelta = fsum;
//}

void CNeuron::UpdateBias(float lr)
{
    //m_fB = m_fB - lr * m_fDelta;
    float fsum = 0;
    for (int i=0;i<m_vDelta.size();i++)
    {
        fsum += m_vDelta[i];
    }
    m_fB = m_fB - lr * fsum / m_nBatchSize;
}

void CNeuron::UpdateWeights(float lr)
{
    //for (auto it = m_mBottomLink.begin(); it!= m_mBottomLink.end();it++)
    //{
    //    auto p = CNeuron::GetNeuronByID(it->first);
    //    it->second = it->second - lr * m_fDelta*p->m_fA;
    //    p->m_mTopLink[m_lID] = it->second;
    //}
    float fsum = 0;
    for (int i=0;i<m_vDelta.size();i++)
    {
        fsum += (m_vDelta[i] * m_vA[i]);
    }
    fsum /= m_nBatchSize;
    for (auto it = m_mBottomLink.begin(); it != m_mBottomLink.end(); it++)
    {
        auto p = CNeuron::GetNeuronByID(it->first);
        it->second = it->second - lr *fsum;
        p->m_mTopLink[m_lID] = it->second;
    }
}

void CNeuron::SetBatchSize(int nSize)
{
    m_vA.clear();
    m_vA.resize(nSize);
    m_vActPrimeZ.clear();
    m_vActPrimeZ.resize(nSize);
    m_vDelta.clear();
    m_vDelta.resize(nSize);
    m_vZ.clear();
    m_vZ.resize(nSize);
    m_nBatchSize = nSize;
}

void CNeuron::Forward(int index)
{
    float fsum = 0;
    for (auto it = m_mBottomLink.begin(); it != m_mBottomLink.end(); it++)
    {
        auto p = CNeuron::GetNeuronByID(it->first);
        fsum += (p->m_vA[index]*it->second);
    }
    m_vZ[index] = fsum + m_fB;
    m_vA[index] = Func_sigmoid(m_vZ[index]);
    m_vActPrimeZ[index] = Func_sigmoid_prime(m_vZ[index]);
}

void CNeuron::Backward(int index)
{
    float fsum = 0;
    for (auto it = m_mTopLink.begin(); it != m_mTopLink.end(); it++)
    {
        auto p = CNeuron::GetNeuronByID(it->first);
        fsum += ((p->m_vDelta[index] * it->second)*m_vActPrimeZ[index]);
    }
    m_vDelta[index] = fsum;
}