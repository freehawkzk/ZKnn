#pragma once
#pragma once

#include <vector>
#include <memory>
#include <string.h>
//@brief 图像像素格式枚举类
enum EPIXTYPE
{
    EBGR = 0, //B-G-R格式排列
    ERGBA = 1,//R-G-B-A格式排列
    ENV21 = 2,//YUV-NV21格式排列
    EFILENAME = 3,//指定文件名，从文件中读取图片
    EFILEBUFFER = 4//通过文件内容缓冲区，从中解码图片
};

//@brief 图像旋转角度枚举
enum EROTATETYPE
{
    ECLOCKWISE0 = 0,// 不旋转
    ECLOCKWISE90 = 1,// 顺时针旋转90度
    ECLOCKWISE180 = 2,// 顺时针旋转180度
    ECLOCKWISE270 = 3// 顺时针旋转270度
};

//@brief 人脸检测器类型
enum EDetectorType
{
    EULTRADETECTOR = 0
};

//@brief 人脸关键点检测器类型
enum ELandmarkerType
{
    EXDLANDMARKER = 0
};

//@brief 人脸识别器类型
enum ERecognizerType
{
    EXDRECOGNIZER = 0
};

//@brief 尺寸，
struct EMPSIZE_C
{
    float fw;// 宽
    float fh;// 高
};

//@brief 二维点
struct EMPPT2D_C
{
    float fx;// X 坐标
    float fy;//Y 坐标
};

//@brief 三维点
struct EMPPT3D_C
{
    float fx;
    float fy;
    float fz;
};

//@brief 矩形区域
struct EMPRECT_C
{
    float fx;// 左上角 X 坐标
    float fy;// 左上角 Y 坐标
    float fw;// 矩形宽度
    float fh;// 矩形高度
};

//@brief 图像
struct EMPIMG2_C
{
    int nw; // 宽度
    int nh; // 高度
    int nc; // 通道数
    unsigned char* pData;// 图像数据
};

struct EMPFace2_C
{
    long long llFrameID;
    long long llFaceID;
    EMPRECT_C rFaceRT;
    int nKeyPtNum;
    EMPPT2D_C* pvkeyPts;
    EMPIMG2_C* pFaceImg;
    float fscore;
    float fmaskscore;
};

struct EMPDetectResult_C
{
    int nSize;
    EMPFace2_C* pFaces;
};

//@brief 人脸区域
struct EMPFaceLocation
{
public:
    EMPRECT_C location_;// 人脸位置区域
    float     score_;// 人脸置信度
};

//@brief 关键点定位结果
struct EMPFaceLandmarks
{
public:
    int count_;// 关键点数目
    EMPPT2D_C pts_[106];// 人脸关键点位置
};

//@brief 人脸检测结果
struct EMPFaceDetectResult
{
public:
    int nSize;// 人脸数目
    EMPFaceLocation* pLocations;// 每个人脸的位置
};

//@brief 从人脸底库中查找的结果
struct SQueryResult
{
    int nID = 0;// 最相似的记录 ID
    float fSim = -0.0f;// 相似度
    char  sName[128] = { 0 };// 最相似的人脸名称
};

typedef void* XDHandle; // 对象 handle 

struct SObjWarper
{
    XDHandle hDetector;
    XDHandle hLandmarker;
    XDHandle hAligner;
};


struct SRecordData
{
    int nRecordID;
    //int nPersonID;
    char sName[128];
    float vFeat[256];
    //int nW;
    //int nH;
    //unsigned char vImgData[3 * 256 * 256];
    SRecordData() :nRecordID(0)
    {
        memset(sName, 0, 128);
        memset(vFeat, 0, 256 * sizeof(float));
    }
};

struct EMPFaceEngineConfig
{
    char licensePath[256];
    char modelPath[256];
    char localGroupStorePath[256];
    char localGroupName[256];
    EPIXTYPE    ePixelType;
    EROTATETYPE eRotateType;
    float       fSimThresh;
    int nTheradNum;
    bool bDetectMask;
};