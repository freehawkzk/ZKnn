#include "InterFuncs.h"
#include <math.h>

float Func_Sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}