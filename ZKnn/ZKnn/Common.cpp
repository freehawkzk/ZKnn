#include "Common.h"
#include <math.h>
#include <stdlib.h>
double Func_sigmoid(double x)
{
    return 1 / (1 + exp(x));
}

double Func_sigmoid_prime(double x)
{
    return Func_sigmoid(x)*(1 - Func_sigmoid(x));
}

float GetRandValue()
{
    float v = rand()*1.0f / RAND_MAX;
    return v * 2.0 - 1;
}