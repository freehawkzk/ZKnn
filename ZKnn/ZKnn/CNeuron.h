#pragma once
#include <vector>
class CNeuron
{
public:
    CNeuron();
    virtual ~CNeuron();

    std::vector<float> vInputs;
    std::vector<float> vWeights;
    float fBias;
    float fOutput;

    virtual float Compute() = 0;
};

