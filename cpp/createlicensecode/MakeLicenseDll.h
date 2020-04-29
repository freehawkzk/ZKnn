#pragma once
#ifndef _MAKE_LICENSE_DLL_H_
#define _MAKE_LICENSE_DLL_H_

#define EMPLIC_OK 0
#define EMPLIC_ERROR -1000
#define EMPLIC_INPUT_ERROR (EMPLIC_ERROR - 1) 
#define EMPLIC_OUTPUT_BUFFER_NULL (EMPLIC_ERROR - 2)

#ifdef __cplusplus
extern "C"
{
#endif

    int EMP_MakeLicense(char* pSrc, char* pDst);

    int EMP_MakeLicenseShowLog(bool bShow);

#ifdef __cplusplus
}
#endif
#endif