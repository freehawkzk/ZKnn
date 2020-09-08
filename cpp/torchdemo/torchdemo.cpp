#include <torch/torch.h>
#include <iostream>

int main() 
{
    torch::Tensor tensor = torch::eye(3);
    std::cout << tensor << std::endl;

    // check whether cuda is available or not.
    // result is decided by graphic card drive, cuda, libtorch version.
    auto hascuda = torch::cuda::is_available();
    std::cout<<"cuda is_available:  "<<hascuda<<std::endl;

    
    return 0;
}
