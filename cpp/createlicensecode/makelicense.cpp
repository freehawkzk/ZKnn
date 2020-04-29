#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
#include "MD5.h"
#include "MakeLicenseDll.h"

bool g_logSwitch = false;

std::string _ConverStrUpper(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] + 'A' - 'a';
        }
    }
    return str;
}

int EMP_MakeLicenseShowLog(bool bShow)
{
    g_logSwitch = bShow;
    return EMPLIC_OK;
}

int EMP_MakeLicense(char* pSrc, char* pDst)
{
    if (pSrc == nullptr)
    {
        return EMPLIC_INPUT_ERROR;
    }

    if (pDst == nullptr)
    {
        return EMPLIC_OUTPUT_BUFFER_NULL;
    }
    std::string machinecode(pSrc);
    if(g_logSwitch)
        std::cout << "MakeLicense dll LOG: Input machine code is: " << machinecode << std::endl;

    machinecode = _ConverStrUpper(machinecode);
    machinecode = machinecode.substr(0, 6) + machinecode.substr(0, 2) + \
        machinecode.substr(6, 5) + machinecode.substr(2, 7) + \
        machinecode.substr(11, 3) + machinecode.substr(9, 6) + \
        machinecode.substr(14, 2) + machinecode.substr(15, 1);
    //std::cout << machinecode << std::endl;
    MD5 md5;
    md5.update(machinecode.c_str());
    machinecode = md5.toString();
    std::string temp;
    for (int i = 0; i < machinecode.length(); i += 2)
    {
        temp = temp + machinecode.substr(i, 1);
    }
    
    temp = _ConverStrUpper(temp);
    if (pDst != nullptr)
    {
        //memcpy_s(pDst, 16, temp.c_str(), temp.length());
        strcpy(pDst, temp.c_str());
        pDst[16] = '\0';
    }

    if(g_logSwitch)
        std::cout << "MakeLicense dll LOG: Output license code is: " << pDst << std::endl;
    return EMPLIC_OK;
}