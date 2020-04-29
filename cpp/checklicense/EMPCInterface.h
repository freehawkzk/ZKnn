#pragma once

#include "EMPStructs_c.h"

#ifdef __cplusplus
extern "C"
{
#endif
    const char* XDGetVersion();

    void XDEnableLog(bool bEnable = true);

    //////////////////////////////////////////////////////////////////////////
    /*                  授权验证                                             */
    //////////////////////////////////////////////////////////////////////////
    //@brief 使用指定的授权文件保存目录进行授权验证
    //@param const char* pPath: 授权文件所在的目录
    //@param int* pErrorCode:输出参数，用于返回转换过程的错误码。
    //@return 授权验证结果，true表示授权成功，false表示授权失败
    bool XDAuthCheck1(const char* pPath, int* pErrorCode = nullptr);

    //@brief 使用指定的授权文件保存目录进行授权验证
    //@param const char* pCode: 机器码字符串
    //@param const char* pLicense: 授权码字符串
    //@param int* pErrorCode:输出参数，用于返回转换过程的错误码。
    //@return 授权验证结果，true表示授权成功，false表示授权失败
    bool XDAuthCheck2(const char* pCode, const char* pLicense, int* pErrorCode = nullptr);

    //@brief 获取当前的授权验证状态
    //@return 授权验证结果，true表示授权成功，false表示授权失败
    bool XDAuthGetStatus();

    //////////////////////////////////////////////////////////////////////////
    /*                  输入缓冲区处理                                       */
    //////////////////////////////////////////////////////////////////////////
    //@brief 输入数据转换接口，将输入的多种像素格式的缓冲区转换成BGR的缓冲区。注意，
    // C++核心内部只处理BGR格式的图像数据，且接口输出的图像数据都是BGR格式。
    // 通过此接口生成的图像数据，必须通过XDReleaseImg接口释放，否则会发生内存泄露。
    //@param const unsigned char* pData:图像数据缓冲区，内部只检查该缓冲区是否为空
    //@param int nw, int nh: 图像宽，高。内部检查该参数是否<0。
    //@param EPIXTYPE eType: 图像像素格式，
    //           EBGR --- BGR排列， opencv读取图像后的默认排序
    //           ERGBA--- RGBA排列，android加载图像后的默认格式排列
    //           ENV21--- YUV-NV21排列，android从相机中获取的图像buffer的数据格式。
    //           EFILENAME--从指定文件名的文件中读取文件，pData保存文件名
    //           EFILEBUFFER--从文件缓冲区buffer中解码图像，pData是缓冲区指针，nw表示缓冲区长度。
    //@param EROTATETYPE eRotateType:图像旋转角度，顺时针90°，180°，270°以及0°旋转。
    // 具体数值参见EMPStructs_c.h中的enum EROTATETYPE的申明。
    //@param int* pErrorCode:输出参数，用于返回转换过程的错误码。
    //return EMPIMG2_C*:使用输入缓冲区进行解码，旋转之后的图像指针，3通道，BGR排列。
    //如果转换失败，返回nullptr,通过pErrorCode表示失败原因
    EMPIMG2_C* XDCreateImg(const unsigned char* pData, int nw, int nh, \
        EPIXTYPE eType, EROTATETYPE eRotateType,int* pErrorCode = nullptr);

    //@brief 释放XDCreateImg接口生成的图像缓冲区。
    //@param EMPIMG2_C* pImg:准备释放的图像缓冲区指针。
    //@note 本接口只能用于释放EMPIMG2_C*类型的图像缓冲区，内部只进行了指针非空判断。
    //使用这个接口释放其他类型的指针，后果是未知的，可能导致程序崩溃。
    void       XDReleaseImg(EMPIMG2_C* pImg);

    //////////////////////////////////////////////////////////////////////////
    /*                        人脸检测                                       */
    //////////////////////////////////////////////////////////////////////////
    //@brief 创建人脸检测器对象，通过指定目录下的模型文件进行初始化，返回对象handle
    //@param const char* pModelPath:模型文件所在目录
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 创建并初始化成功的人脸检测器对象handle。
    // 创建失败时，返回nullptr.
    //@note 创建的对象handle必须通过XDReleaseDetector接口释放。
    XDHandle XDCreateDetector1(const char* pModelPath, int* pErrorCode = nullptr);

    //@brief 创建人脸检测器对象，通过输入的模型缓冲区初始化，返回对象handle
    //@param const char* pBuf:模型缓冲区
    //@param int nBufLen: 缓冲区长度
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 创建并初始化成功的人脸检测器对象handle。
    // 创建失败时，返回nullptr.
    //@note 创建的对象handle必须通过XDReleaseDetector接口释放。
    XDHandle XDCreateDetector2(const char* pBuf, int nBufLen, int* pErrorCode = nullptr);

    //@brief 使用指定的人脸检测器，对指定的输入缓冲区，进行人脸检测，返回人脸数目和人脸位置
    //@param XDHandle handle: 人脸检测器对象handle.
    //@param unsigned char* pData, int nw, int nh,EPIXTYPE eType,
    // EROTATETYPE eRotateType : 输入图像缓冲区，参数的定义参见XDCreateImg说明。接口内部
    // 调用XDCreateImg对输入缓冲区进行了转换。
    //@param int* pErrorCode: 输出参数，用于返回检测过程中的错误码。
    //@return EMPFaceDetectResult*:检测结果，参见EMPStructs_c.h中的定义。检测失败时返回nullptr.
    //@note 返回的指针必须通过XDReleaseDetectResult接口释放。
    EMPFaceDetectResult* XDDetectFace1(XDHandle handle, unsigned char* pData, int nw, \
        int nh,EPIXTYPE eType, EROTATETYPE eRotateType, int* pErrorCode = nullptr);

    //@brief 使用指定的人脸检测器，对指定的输入缓冲区，进行人脸检测，返回人脸数目和人脸位置
    //@param XDHandle handle: 人脸检测器对象handle.
    //@param EMPIMG2_C* pImg: BGR格式的输入缓冲区。
    //@param int* pErrorCode: 输出参数，用于返回检测过程中的错误码。
    //@return EMPFaceDetectResult*:检测结果，参见EMPStructs_c.h中的定义。检测失败时返回nullptr.
    //@note 返回的指针必须通过XDReleaseDetectResult接口释放。
    EMPFaceDetectResult* XDDetectFace2(XDHandle handle, EMPIMG2_C* pImg,\
        int* pErrorCode = nullptr);

    //@brief 释放人脸检测的结果
    void     XDReleaseDetectResult(EMPFaceDetectResult* pRes);

    //@brief 释放人脸检测器对象
    void     XDReleaseDetector(XDHandle handle);


    //////////////////////////////////////////////////////////////////////////
    /*                       人脸关键点定位                                  */
    //////////////////////////////////////////////////////////////////////////
    //@brief 创建人脸关键点定位器，通过指定目录下的模型文件进行初始化，返回对象handle
    //@param const char* pModelPath:模型文件所在目录
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 创建并初始化成功的人脸关键点定位器对象handle。
    // 创建失败时，返回nullptr.
    //@note 创建的对象handle必须通过XDReleaseLandmarker接口释放
    XDHandle XDCreateLandmarker1(const char* pModelPath, int* pErrorCode = nullptr);

    //@brief 创建人脸关键点定位器，通过输入的模型缓冲区初始化，返回对象handle
    //@param const char* pBuf:模型缓冲区
    //@param int nBufLen: 缓冲区长度
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 创建并初始化成功的人脸关键点定位器对象handle。
    // 创建失败时，返回nullptr.
    //@note 创建的对象handle必须通过XDReleaseLandmarker接口释放。
    XDHandle XDCreateLandmarker2(const char* pBuf, int nBufLen, int* pErrorCode = nullptr);

    //@brief 使用指定的人脸关键点定位器对象，对输入图像上的指定人脸，进行关键第定位
    //@param XDHandle handle: 关键点定位器对象handle
    //@param EMPIMG2_C* pImg: 输入图像
    //@param EMPFaceLocation* pLoc: 指定人脸位置
    //@param int* pErrorCode: 输出参数，用于返回过程中的错误码。
    //@return EMPFaceLandmarks*: 成功则返回指定人脸的landmark点坐标，否则返回空指针。
    EMPFaceLandmarks* XDExtractKeypoints(XDHandle handle, EMPIMG2_C* pImg, EMPFaceLocation* pLoc, int* pErrorCode = nullptr);

    //@brief 释放XDExtractKeypoints返回的人脸关键点检测结果
    void XDReleaseKeypoints(EMPFaceLandmarks* plms);

    //@brief 释放人脸关键点检测器对象
    void XDReleaseLandmarker(XDHandle handle);

    //////////////////////////////////////////////////////////////////////////
    /*                      人脸对齐                                         */
    //////////////////////////////////////////////////////////////////////////
    //@brief 创建人脸对齐对象
    //@return 人脸对齐对象handle
    XDHandle XDCreateAligner();

    //@brief 使用指定的人脸对齐对象，对输入图像上指定人脸使用其landmark点进行对齐
    //@param XDHandle handle: 人脸对齐对象handle
    //@param EMPIMG2_C* pSrc: 输入图像，只接受3通道B-G-R格式输入。
    //@param EMPFaceLandmarks* pLms: 人脸landmark点位置
    //@param int* pErrorCode: 输出参数，用于返回过程中的错误码。
    //@return EMPIMG2_C*: 经过对齐的人脸图像，失败则返回nullptr。
    //@note 返回的结果图像需要使用XDReleaseAlignedFace接口或XDReleaseImg接口释放。
    // 返回的对齐图像是按照B-G-R格式排列的3通道图像。
    EMPIMG2_C* XDAlginFace(XDHandle handle, EMPIMG2_C* pSrc, EMPFaceLandmarks* pLms, int* pErrorCode = nullptr);

    //@brief 释放XDAlginFace接口返回的对齐图像。
    void XDReleaseAlignedFace(EMPIMG2_C* pImg);

    //@brief 释放人脸对齐对象
    void XDReleaseAligner(XDHandle handle);

    //////////////////////////////////////////////////////////////////////////
    /*                      人脸特征提取                                     */
    //////////////////////////////////////////////////////////////////////////
    //@brief 创建人脸识别器，通过指定目录下的模型文件进行初始化，返回对象handle
    //@param const char* pModelPath:模型文件所在目录
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 创建并初始化成功的人脸识别器对象handle。
    // 创建失败时，返回nullptr.
    //@note 创建的对象handle必须通过XDReleaseRecognizer接口释放
    XDHandle XDCreateRecognizer1(const char* pModelPath, int* pErrorCode = nullptr);

    //@brief 创建人脸识别器，通过输入的模型缓冲区初始化，返回对象handle
    //@param const char* pBuf:模型缓冲区
    //@param int nBufLen: 缓冲区长度
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 创建并初始化成功的人脸识别器对象handle。
    // 创建失败时，返回nullptr.
    //@note 创建的对象handle必须通过XDReleaseRecognizer接口释放。
    XDHandle XDCreateRecognizer2(const char* pBuf, int nBufLen, int* pErrorCode = nullptr);

    //@brief 获取人脸识别器使用的float特征的长度。
    //@return float特征长度，当前返回256.
    int XDGetFloatFeatureLength();

    //@brief 获取人脸识别器使用的unsigned char 特征的长度
    //@return unsigned char 特征长度，当前返回264.
    int XDGetUCFeatureLength();

    //@brief 使用指定的人脸识别器，对输入的经过对齐的人脸进行特征提取。
    //@param XDHandle handle: 人脸识别器对象handle
    //@param EMPIMG2_C* pFace: 经过人脸对齐对象对齐的人脸图像，3通道，B-G-R格式,112*112大小
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return float*: 提取的float特征数组，长度通过XDGetFloatFeatureLength()接口确定。提取失败时返回nullptr.
    //@note 返回的特征数组内存由库维护，需要使用XDReleaseFloatFeature接口释放。
    float* XDExtractFloatFeature(XDHandle handle, EMPIMG2_C* pFace, int* pErrorCode = nullptr);

    //@brief 释放XDExtractFloatFeature返回的float特征指针。
    void XDReleaseFloatFeature(float* pFeat);

    //@brief 使用指定的人脸识别器，对输入的经过对齐的人脸进行特征提取。
    //@param XDHandle handle: 人脸识别器对象handle
    //@param EMPIMG2_C* pFace: 经过人脸对齐对象对齐的人脸图像，3通道，B-G-R格式,112*112大小
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return unsigned char*: 提取的unsigned char特征数组，长度通过XDGetUCFeatureLength()接口确定。提取失败时返回nullptr.
    //@note 返回的特征数组内存由库维护，需要使用XDRealeaseUCFeature接口释放。
    unsigned char* XDExtractUCFeature(XDHandle handle, EMPIMG2_C* pFace, int* pErrorCode = nullptr);

    //@brief 释放XDExtractUCFeature返回的unsigned char特征指针。
    void XDRealeaseUCFeature(unsigned char* pFeat);

    //@brief 释放人脸识别器对象
    void XDReleaseRecognizer(XDHandle handle);

    //@brief 计算两组float类型的特征的相似度
    //@param const float* pFeat1: 第一组float特征
    //@param const float* pFeat2: 第二组float特征
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return float: 两组特征的相似度，取值范围为-1.0f~1.0f
    //@note 接口内部假定输入的float指针指向的是一个长度至少包含XDGetFloatFeatureLength()个float数据的缓冲区。
    // 接口内部只检查输入指针是否为空，计算过程中会读取XDGetFloatFeatureLength()个float用于计算。
    // 在输入检测不合法时，设置错误码之后，返回-1.0f.
    float XDCalcSim1(const float* pFeat1, const float* pFeat2, int* pErrorCode = nullptr);

    //@brief 计算一组float特征与一组unsigned char特征的相似度
    //@param const float* pFeat1: 第一组float特征
    //@param const unsigned char* pucFeat2: 第二组unsigned char特征
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return float: 两组特征的相似度，取值范围为-1.0f~1.0f
    //@note 接口内部假定输入的float指针指向的是一个长度至少包含XDGetFloatFeatureLength()个float数据的缓冲区。
    // 接口内部假定输入的unsigned char指针指向的是一个长度至少包含XDGetUCFeatureLength()个unsigned char数据的缓冲区。
    // 接口内部只检查输入指针是否为空，计算过程中会读取XDGetFloatFeatureLength()个float用于计算。
    // 对于unsigned char特征，会读取XDGetUCFeatureLength()个unsigned char数据用于计算。
    // 在输入检测不合法时，设置错误码之后，返回-1.0f.
    float XDCalcSim2(const float* pFeat1, const unsigned char* pucFeat2, int* pErrorCode = nullptr);

    //@brief 计算两组unsigned char类型的特征的相似度
    //@param const unsigned char* pFeat1: 第一组unsigned char特征
    //@param const unsigned char* pFeat2: 第二组unsigned char特征
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return float: 两组特征的相似度，取值范围为-1.0f~1.0f
    //@note 接口内部假定输入的unsigned char指针指向的是一个长度至少包含XDGetFloatFeatureLength()个unsigned char数据的缓冲区。
    // 接口内部只检查输入指针是否为空，计算过程中会读取XDGetUCFeatureLength()个unsigned char用于计算。
    // 在输入检测不合法时，设置错误码之后，返回-1.0f.
    float XDCalcSim3(const unsigned char* pucFeat1, const unsigned char* pucFeat2, int* pErrorCode = nullptr);

    //////////////////////////////////////////////////////////////////////////
    /*                      人脸特征后处理                                   */
    //////////////////////////////////////////////////////////////////////////
    //@brief 将一组float类型的特征编码成unsigned char类型的特征
    //@param const float* pFeat: 输入的float特征，接口假定该指针指向的是长度不小于XDGetFloatFeatureLength()
    // 的缓冲区，接口内部检测指针是否为空之后，会读取XDGetFloatFeatureLength()个float用于处理。
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return 成功则返回编码后的unsigned char类型的特征指针，长度为XDGetUCFeatureLength()指定。
    // 否则返回nullptr
    //@note 返回的特征值指针，必须通过XDRealeaseUCFeature释放。
    unsigned char* XDEncodeFeature(const float* pFeat,int* pErrorCode = nullptr);

    //@brief 将一组unsigned char类型的特征解码成float类型的特征
    //@param const unsigned char* pFeat: 输入的unsigned char特征，接口假定该指针指向的是长度不小于XDGetUCFeatureLength()
    // 的缓冲区，接口内部检测指针是否为空之后，会读取XDGetUCFeatureLength()个unsigned char用于处理。
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return 成功则返回解码后的float类型的特征指针，长度为XDGetFloatFeatureLength()指定。
    // 否则返回nullptr
    //@note 返回的特征值指针，必须通过XDRealeaseFloatFeature释放。
    float* XDDecodeFeature(const unsigned char* pFeat, int* pErrorCode = nullptr);

    //////////////////////////////////////////////////////////////////////////
    /*                      人脸底库操作                                     */
    //////////////////////////////////////////////////////////////////////////
    //@brief 创建人脸底库
    //@return 人脸底库对象handle
    XDHandle XDCreateDB();

    //@brief 打开指定路径下的人脸底库文件
    //@param XDHandle handle: 操作的人脸底库对象handle
    //@param const char* pDBPath: 人脸底库文件路径，包括底库文件名。
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 加载成功时的人脸数据库底库handle。
    //@note 如果数据库文件不存在，接口会创建底库文件。接口成功执行时，会在底库数据文件中
    // 创建人脸信息结构的一个数据表。
    XDHandle XDOpenDB(XDHandle handle,const char* pDBPath, int* pErrorCode = nullptr);
    
    //@brief 关闭指定的人脸底库。
    XDHandle XDCloseDB(XDHandle handle,int* pErrorCode = nullptr);
    
    //@brief 释放人脸底库对象
    void XDReleaseDB(XDHandle handle);
    
    //@brief 向指定的人脸底库对象中，添加一个名称为pName, 特征值维pFeat的一个人脸。
    //@param XDHanle handle: 人脸底库对象handle
    //@param const char* pName: 待添加的人脸名称
    //@param float* pFeat: 待添加的人脸特征值缓冲区
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return XDHandle: 人脸底库对象handle。
    XDHandle XDAddToDB(XDHandle handle, const char* pName, float* pFeat, int* pErrorCode = nullptr);
    
    //@brief 在指定的人脸底库中，查找与指定特征最相似的人脸的名称，记录ID以及相似度
    //@param XDHandle handle: 人脸底库对象handle
    //@param float* pFeat: 待查找的人脸特征
    //@param int* pErrorCode: 输出参数，用于返回创建过程中的错误码。
    //@return SQueryResult*: 返回底库中与指定特征最相似的人脸名称，记录ID以及相似度，失败返回nullptr
    //@note 结果必须通过XDReleaseQueryResult释放
    SQueryResult* XDQueryTop(XDHandle handle, float* pFeat, int* pErrorCode = nullptr);
    
    //@brief 释放人脸底库的搜索结果
    void XDReleaseQueryResult(SQueryResult* pQueryResult);


#ifdef __cplusplus
}
#endif