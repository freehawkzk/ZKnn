#include "InterFuncs.h"
#include <math.h>

float Func_Sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

float Func_Sigmoid_Prime(float x)
{
    auto v = Func_Sigmoid(x);
    return v * (1 - v);
}

float Func_Step(float x)
{
    return x >= 0 ? 1 : 0;
}