#include <string>
#include <iostream>
#include "EMPCInterface.h"

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout<<"Please use this program as this commond line"<<std::endl;
        std::cout<<"program machine_code_string license_code_string"<<std::endl;
        return 0;
    }

    std::string machineCode(argv[1]);
    if(machineCode.length()!= 16)
    {
        std::cout<<"machine code should have 16 charters"<<std::endl;
        return 0;
    }    
    std::string licenseCode(argv[2]);
    if(licenseCode.length()!=16)
    {
        std::cout<<"license code should have 16 charters"<<std::endl;
        return 0;
    }
    
    auto hr = XDAuthCheck2(machineCode.c_str(),licenseCode.c_str(),nullptr);
    std::cout<<"Right check result: "<<hr<<std::endl;

    auto status = XDAuthGetStatus();
    if(status)
        std::cout<<machineCode <<" and "<<licenseCode<<" is matched"<<std::endl;    
    else
        std::cout<<machineCode <<" and "<<licenseCode<<" is not matched"<<std::endl;    
    return 0;
}