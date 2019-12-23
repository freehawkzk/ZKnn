#pragma once
#include "Network.h"
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"
class CMnistNet :
    public CNetwork
{
public:
    CMnistNet();
    virtual ~CMnistNet();

    std::vector<std::string> m_vTrainList;
    std::vector<std::string> m_vTestList;
    
};

