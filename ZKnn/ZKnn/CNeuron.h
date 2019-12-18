#pragma once
#include <vector>
typedef float(*ActivateFunc)(float);
typedef float(*ActivatePrimeFunc)(float);
class CNeuron
{
public:
    CNeuron();
    virtual ~CNeuron();
    static int snNeuronCount;
    int nNeuronID;//��ԪID
    float fBias;//ƫ��
    float fOutput;//��Ԫ�����
    float fZValue;//��Ԫ�ļ�Ȩ����
    float fDelta;//��Ԫ�����
    float fActivate_prime_func_value;//������ĵ����ڱ���Ԫ��ֵ
    float fLable;//��Ԫ�ı�ǩֵ
    std::vector<float> vWeights;//��Ԫ������Ȩֵ
    std::vector<std::pair<CNeuron*,float*> > vpBottom;//��Ԫ��������Ԫ���Լ���Ӧ������Ȩֵָ�룬ָ�����vWeights�е�Ԫ��
    std::vector<std::pair<CNeuron*,float*> > vpTop;//��Ԫ�������Ԫ���Լ���Ӧ�����Ȩֵָ�룬ָ��Ŀ����Ԫ��vWeights�е�Ԫ��
    ActivateFunc* pActivateFunc = nullptr;//��Ԫ�ļ����
    ActivatePrimeFunc* pActivatePrimeFunc = nullptr;//��Ԫ�ļ�����ĵ���

    void SetActivateFunc(ActivateFunc* pFunc);//���ü����ָ��
    void SetActivatePrimeFunc(ActivatePrimeFunc* pFunc);//���ü�����ĵ����ĺ���ָ��
    virtual float Forward();//ǰ������
    virtual float Backward();//���򴫲�

    void AdjustBias();//����ƫ��
    void AdjustWeight();//����Ȩֵ
    void CalcDelta();//������Ԫ�����
};

