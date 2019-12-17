#include "CLayer.h"
#include "CSigmoidNeuron.h"
#include <iostream>

int CLayer::snLayCount = 0;
CLayer::CLayer(int nNeuronNum) :nLayerID(snLayCount++), nTopLayerID(0), nBottomLayerID(0)
{
    std::cout << "Construct " << nLayerID << " layer" << std::endl;
    if (nNeuronNum > 0)
    {
        for (int i = 0;i< nNeuronNum; i++)
        {
            CNeuron* pNeuron = new CSigmoidNeuron();
            vpNeurons.push_back(pNeuron);
        }
    }
}


CLayer::~CLayer()
{
    for (int i = 0;i < vpNeurons.size(); i++)
    {
        delete vpNeurons[i];
        vpNeurons[i] = nullptr;
    }
    vpNeurons.clear();
    std::cout << "destruct " << nLayerID << " layer" << std::endl;
}

void CLayer::SetTopLayer(CLayer* pTopLayer)
{
    nTopLayerID = pTopLayer->nLayerID;
    for (int i = 0;i < vpNeurons.size(); i++)
    {
        vpNeurons[i]->vpTop.clear();
        for (int j = 0; j< pTopLayer->vpNeurons.size() ;j ++)
        {
            vpNeurons[i]->vpTop.push_back(pTopLayer->vpNeurons[j]);
        }
    }
    for (int j = 0;j< pTopLayer->vpNeurons.size(); j++)
    {
        pTopLayer->vpNeurons[j]->vpBottom.clear();
        for (int i = 0;i< vpNeurons.size(); i++)
        {
            pTopLayer->vpNeurons[j]->vpBottom.push_back(vpNeurons[i]);
        }
    }
}

void CLayer::SetBottomLayer(CLayer* pBottomLayer)
{
    nBottomLayerID = pBottomLayer->nLayerID;
    for (int i =0;i<vpNeurons.size(); i++)
    {
        vpNeurons[i]->vpBottom.clear();
        for (int j = 0; j< pBottomLayer->vpNeurons.size(); j++)
        {
            vpNeurons[i]->vpBottom.push_back(pBottomLayer->vpNeurons[j]);
        }
        vpNeurons[i]->vWeights.clear();
        for (int k = 0; k < vpNeurons[i]->vpBottom.size(); k++)
        {
            float fw = rand() *1.0f / RAND_MAX;
            vpNeurons[i]->vWeights.push_back(2*fw-1);
        }
    }
    for (int j = 0;j<pBottomLayer->vpNeurons.size(); j++)
    {
        pBottomLayer->vpNeurons[j]->vpTop.clear();
        for (int i=0;i < vpNeurons.size();i++)
        {
            pBottomLayer->vpNeurons[j]->vpTop.push_back(vpNeurons[i]);
        }
    }
}

void CLayer::Run()
{
    std::cout << "Layer " << nLayerID << " Run" << std::endl;
    for (int i=0;i<vpNeurons.size();i++)
    {
        vpNeurons[i]->Run();
    }
}