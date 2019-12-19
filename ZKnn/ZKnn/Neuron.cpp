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
,m_fB(0)\
,m_fA(0)\
,m_fActPrimeZ(0)\
,m_fDelta(0)\
,m_fZ(0)\
,m_pActivationFunc(nullptr)\
,m_pActivationPrimeFunc(nullptr)
{
    m_mBottomLink.clear();
    m_mTopLink.clear();
    std::cout << "Neuron: " << m_lID << " Constructed" << std::endl;
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
    for (auto it = m_mBottomLink.begin(); it!= m_mBottomLink.end();it++)
    {
        auto p = CNeuron::GetNeuronByID(it->first);
        fsum += (p->m_fA*it->second);
    }
    m_fZ = fsum + m_fB;
    m_fA = Func_sigmoid(m_fZ);
    m_fActPrimeZ = Func_sigmoid_prime(m_fZ);
}

void CNeuron::Backward()
{
    float fsum = 0;
    for (auto it = m_mTopLink.begin(); it!= m_mTopLink.end();it++)
    {
        auto p = CNeuron::GetNeuronByID(it->first);
        fsum += ((p->m_fDelta * it->second)*m_fActPrimeZ);
    }
    m_fDelta = fsum;
}

void CNeuron::UpdateBias(float lr)
{
    m_fB = m_fB - lr * m_fDelta;
}

void CNeuron::UpdateWeights(float lr)
{
    for (auto it = m_mBottomLink.begin(); it!= m_mBottomLink.end();it++)
    {
        auto p = CNeuron::GetNeuronByID(it->first);
        it->second = it->second - lr * m_fDelta*p->m_fA;
        p->m_mTopLink[m_lID] = it->second;
    }
}