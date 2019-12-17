#pragma once
#include <vector>
class CPerceptron
{
public:
    CPerceptron();
    ~CPerceptron();

    std::vector<bool> vInputs;
    std::vector<float> vWeights;
    float fThresh;
    bool bOutput;

    bool Computer();
};

