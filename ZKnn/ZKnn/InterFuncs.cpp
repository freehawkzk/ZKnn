#include "InterFuncs.h"
#include <math.h>

float Func_Sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

float Func_Step(float x)
{
    return x >= 0 ? 1 : 0;
}