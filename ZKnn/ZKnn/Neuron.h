#pragma once
#include <vector>
#include <map>
#include "Common.h"

//��Ԫģ��
class CNeuron
{
public:
    
    virtual ~CNeuron();
    //////////////////////////////////////////////////////////////////////////
    //������Ԫϸ������������
    static long slNeuronCount;
    static std::map<long, CNeuron*> smNeuron;

    static CNeuron* Create();
    static CNeuron* GetNeuronByID(long id);

    //////////////////////////////////////////////////////////////////////////
    //��Ԫ��������ݣ�ֻ����Ԫ�����й�
    long  m_lID;//��ǰ��Ԫ��ID
    float m_fB;//ƫ��
    int m_nBatchSize;//batch size
    std::vector<float> m_vA;
    float m_fA;//��Ԫ��������Ǽ���������Ȩ�����Ľ������������Ԫ�޹�

    //////////////////////////////////////////////////////////////////////////
    //��Ԫά�����������²���Ԫ�йص�����
    float m_fZ;//��Ԫ�ļ�Ȩ���룬����һ���������Լ�����Ȩֵ�й�
    std::vector<float> m_vZ;
    float m_fActPrimeZ;//������ĵ����ڼ�Ȩ���봦��ֵ
    std::vector<float> m_vActPrimeZ;
    float m_fDelta;//��Ԫ����ʧ������һ�����ʧֵ���Լ�����һ�������Ȩֵ�й�
    std::vector<float> m_vDelta;
    std::map<long, float> m_mBottomLink;//����Ԫ������������ԪID����Ȩֵ
    std::map<long, float> m_mTopLink;//����Ԫ�����������ԪID����Ȩֵ

    //////////////////////////////////////////////////////////////////////////
    ActivationFunc* m_pActivationFunc;//�����
    ActivationPrimeFunc* m_pActivationPrimeFunc;//������ĵ���

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

