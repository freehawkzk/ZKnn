#include "CNeuron.h"
#include <iostream>
int CNeuron::snNeuronCount = 0;

CNeuron::CNeuron():nNeuronID(snNeuronCount++)
{
    std::cout << "Construct " << nNeuronID << " neuron" << std::endl;
}


CNeuron::~CNeuron()
{
    std::cout << "destruct " << nNeuronID << " neuron" << std::endl;
}
