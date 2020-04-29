#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <arpa/inet.h>
#include <string>
#include <fstream>
 
static bool get_cpu_id_by_asm(std::string & cpu_id)
{
    cpu_id.clear();
 
    unsigned int s1 = 0;
    unsigned int s2 = 0;
    asm volatile
    (
        "movl $0x01, %%eax; \n\t"
        "xorl %%edx, %%edx; \n\t"
        "cpuid; \n\t"
        "movl %%edx, %0; \n\t"
        "movl %%eax, %1; \n\t"
        : "=m"(s1), "=m"(s2)
    );
    if (0 == s1 && 0 == s2)
    {
        return(false);
    }
    char cpu[32] = { 0 };
    snprintf(cpu, sizeof(cpu), "%08X%08X", htonl(s2), htonl(s1));
    std::string(cpu).swap(cpu_id);
    return(true);
}

static bool get_cpu_id(std::string & cpu_id)
{
    if (get_cpu_id_by_asm(cpu_id))
    {
        return(true);
    }
    
    return(false);
}
static void test_1()
{
    std::string cpu_id;
    if (get_cpu_id(cpu_id))
    {
        printf("machine code is : %s\n", cpu_id.c_str());
    }
    else
    {
        printf("can not get machine code\n");
    }
}

int main(int argc, char* argv[])
{
    test_1();
    return(0);
}