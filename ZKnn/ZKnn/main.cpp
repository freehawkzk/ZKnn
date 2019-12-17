#include <iostream>
#include "CPerceptron.h"
#include "CSigmoidNeuron.h"
int main()
{
    CPerceptron p;
    p.vInputs.push_back(false); p.vWeights.push_back(-2);
    p.vInputs.push_back(false); p.vWeights.push_back(-2);
    p.fBias = 3;
    float bhr = p.Compute();
    std::cout << bhr << std::endl;

    CSigmoidNeuron s;
    s.vInputs.push_back(0); s.vWeights.push_back(-2);
    s.vInputs.push_back(0); s.vWeights.push_back(-2);
    s.fBias = 3;
    std::cout << s.Compute() << std::endl;
    return 0;
}