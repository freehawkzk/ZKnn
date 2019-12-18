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
    int nNeuronID;//神经元ID
    float fBias;//偏置
    float fOutput;//神经元的输出
    float fZValue;//神经元的加权输入
    float fDelta;//神经元的误差
    float fActivate_prime_func_value;//激活函数的导数在本神经元的值
    float fLable;//神经元的标签值
    std::vector<float> vWeights;//神经元的输入权值
    std::vector<std::pair<CNeuron*,float*> > vpBottom;//神经元的输入神经元，以及对应的输入权值指针，指向本身的vWeights中的元素
    std::vector<std::pair<CNeuron*,float*> > vpTop;//神经元的输出神经元，以及对应的输出权值指针，指向目标神经元的vWeights中的元素
    ActivateFunc* pActivateFunc = nullptr;//神经元的激活函数
    ActivatePrimeFunc* pActivatePrimeFunc = nullptr;//神经元的激活函数的导数

    void SetActivateFunc(ActivateFunc* pFunc);//设置激活函数指针
    void SetActivatePrimeFunc(ActivatePrimeFunc* pFunc);//设置激活函数的导数的函数指针
    virtual float Forward();//前向推理
    virtual float Backward();//反向传播

    void AdjustBias();//调整偏置
    void AdjustWeight();//调整权值
    void CalcDelta();//计算神经元的误差
};

