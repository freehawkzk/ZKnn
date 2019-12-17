#pragma once
#include <vector>
/*
    output = 1, if sum(input[i]*vWeight[i]) + fBias > 0
    output = 1, if sum(input[i]*vWeight[i]) + fBias < 0
*/
class CPerceptron
{
public:
    CPerceptron();
    ~CPerceptron();

    std::vector<bool> vInputs;
    std::vector<float> vWeights;
    float fBias;
    bool bOutput;

    bool Computer();
};

