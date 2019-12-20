#pragma once
#include <vector>
#include <map>
#include "Common.h"

//神经元模型
class CNeuron
{
public:
    
    virtual ~CNeuron();
    //////////////////////////////////////////////////////////////////////////
    //所有神经元细胞的数量计数
    static long slNeuronCount;
    static std::map<long, CNeuron*> smNeuron;

    static CNeuron* Create();
    static CNeuron* GetNeuronByID(long id);

    //////////////////////////////////////////////////////////////////////////
    //神经元自身的数据，只与神经元自身有关
    long  m_lID;//当前神经元的ID
    float m_fB;//偏置
    int m_nBatchSize;//batch size
    std::vector<float> m_vA;
    float m_fA;//神经元的输出，是激活函数处理加权输入后的结果，与其他神经元无关

    //////////////////////////////////////////////////////////////////////////
    //神经元维护，但与上下层神经元有关的数据
    float m_fZ;//神经元的加权输入，与上一层的输出，以及连接权值有关
    std::vector<float> m_vZ;
    float m_fActPrimeZ;//激活函数的导数在加权输入处的值
    std::vector<float> m_vActPrimeZ;
    float m_fDelta;//神经元的损失，与下一层的损失值，以及与下一层的连接权值有关
    std::vector<float> m_vDelta;
    std::map<long, float> m_mBottomLink;//本神经元的输入连接神经元ID及其权值
    std::map<long, float> m_mTopLink;//本神经元的输出连接神经元ID及其权值

    //////////////////////////////////////////////////////////////////////////
    ActivationFunc* m_pActivationFunc;//激活函数
    ActivationPrimeFunc* m_pActivationPrimeFunc;//激活函数的导数

    void SetActivationFunc(ActivationFunc* pFunc);
    void SetActivationPrimeFunc(ActivationPrimeFunc* pFunc);

    void Forward();
    //void Backward();
    void UpdateBias(float lr);
    void UpdateWeights(float lr);

    void SetBatchSize(int nSize);
    void Forward(int index);
    void Backward(int index);
private:
    CNeuron();
};

