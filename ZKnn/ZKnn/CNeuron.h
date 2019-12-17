#pragma once
#include <vector>
class CNeuron
{
public:
    CNeuron();
    virtual ~CNeuron();
    static int snNeuronCount;
    int nNeuronID;
    std::vector<float> vInputs;// input value of this neuron
    std::vector<float> vWeights;// weights of this neuron
    float fBias;// bias value
    float fOutput;//output of this neuron
    
    std::vector<CNeuron*> vpBottom;//use those neuron's output as input for this neuron
    std::vector<CNeuron*> vpTop;//neurons that use this neuron's output as input

    virtual float Run() = 0;
};

