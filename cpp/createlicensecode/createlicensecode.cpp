#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <arpa/inet.h>
#include <string>
#include <fstream>
#include <iostream>
#include "MakeLicenseDll.h"

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout<<"Please use this program as this commond line"<<std::endl;
        std::cout<<"program machine_code_string"<<std::endl;
        return 0;
    }

    std::string machineCode(argv[1]);
    if(machineCode.length()!= 16)
    {
        std::cout<<"machine code should have 16 charters"<<std::endl;
        return 0;
    }    
    char buf[512]={0};
    auto hr = EMP_MakeLicense((char*)machineCode.c_str(), (char*)buf);
    if(hr != EMPLIC_OK)
    {
        std::cout<<"make license failed, error code is "<<hr<<std::endl;
        return 0;
    }
    else
    {
        std::cout<<"license code is: "<<buf<<std::endl;
    }
    
    return 0;
}