#include <iostream>
#include "CLayer.h"
#include "CInputLayer.h"
#include "COutputLayer.h"

int main()
{
    CInputLayer inputLayer(10);
    CLayer hiddenLayer(100);
    COutputLayer outputlayer(10);

    inputLayer.SetTopLayer(&hiddenLayer);
    hiddenLayer.SetBottomLayer(&inputLayer);
    hiddenLayer.SetTopLayer(&outputlayer);
    outputlayer.SetBottomLayer(&hiddenLayer);

    inputLayer.Run();
    hiddenLayer.Run();
    outputlayer.Run();
    for (int i = 0; i < outputlayer.vpNeurons.size(); i++)
    {
        std::cout <<i<<" "<< outputlayer.vpNeurons[i]->fOutput << std::endl;
    }
    return 0;
}