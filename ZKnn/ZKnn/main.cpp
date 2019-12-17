#include <iostream>
#include "CPerceptron.h"

int main()
{
    CPerceptron p;
    p.vInputs.push_back(true); p.vWeights.push_back(-2);
    p.vInputs.push_back(true); p.vWeights.push_back(-2);
    p.fThresh = 3;
    bool bhr = p.Computer();
    std::cout << bhr << std::endl;

    return 0;
}