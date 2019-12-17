#pragma once
#include "CNeuron.h"
/*
    output = 1, if sum(input[i]*vWeight[i]) + fBias > 0
    output = 1, if sum(input[i]*vWeight[i]) + fBias < 0
*/
class CPerceptron:public CNeuron
{
public:
    CPerceptron();
    ~CPerceptron();

    float Compute();
};

