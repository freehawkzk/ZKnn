#pragma once
typedef double(*ActivationFunc)(double);
typedef double(*ActivationPrimeFunc)(double);

double Func_sigmoid(double);
double Func_sigmoid_prime(double);
float GetRandValue();