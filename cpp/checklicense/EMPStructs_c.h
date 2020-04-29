#pragma once
#pragma once

#include <vector>
#include <memory>
#include <string.h>
//@brief ͼ�����ظ�ʽö����
enum EPIXTYPE
{
    EBGR = 0, //B-G-R��ʽ����
    ERGBA = 1,//R-G-B-A��ʽ����
    ENV21 = 2,//YUV-NV21��ʽ����
    EFILENAME = 3,//ָ���ļ��������ļ��ж�ȡͼƬ
    EFILEBUFFER = 4//ͨ���ļ����ݻ����������н���ͼƬ
};

//@brief ͼ����ת�Ƕ�ö��
enum EROTATETYPE
{
    ECLOCKWISE0 = 0,// ����ת
    ECLOCKWISE90 = 1,// ˳ʱ����ת90��
    ECLOCKWISE180 = 2,// ˳ʱ����ת180��
    ECLOCKWISE270 = 3// ˳ʱ����ת270��
};

//@brief �������������
enum EDetectorType
{
    EULTRADETECTOR = 0
};

//@brief �����ؼ�����������
enum ELandmarkerType
{
    EXDLANDMARKER = 0
};

//@brief ����ʶ��������
enum ERecognizerType
{
    EXDRECOGNIZER = 0
};

//@brief �ߴ磬
struct EMPSIZE_C
{
    float fw;// ��
    float fh;// ��
};

//@brief ��ά��
struct EMPPT2D_C
{
    float fx;// X ����
    float fy;//Y ����
};

//@brief ��ά��
struct EMPPT3D_C
{
    float fx;
    float fy;
    float fz;
};

//@brief ��������
struct EMPRECT_C
{
    float fx;// ���Ͻ� X ����
    float fy;// ���Ͻ� Y ����
    float fw;// ���ο��
    float fh;// ���θ߶�
};

//@brief ͼ��
struct EMPIMG2_C
{
    int nw; // ���
    int nh; // �߶�
    int nc; // ͨ����
    unsigned char* pData;// ͼ������
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

//@brief ��������
struct EMPFaceLocation
{
public:
    EMPRECT_C location_;// ����λ������
    float     score_;// �������Ŷ�
};

//@brief �ؼ��㶨λ���
struct EMPFaceLandmarks
{
public:
    int count_;// �ؼ�����Ŀ
    EMPPT2D_C pts_[106];// �����ؼ���λ��
};

//@brief ���������
struct EMPFaceDetectResult
{
public:
    int nSize;// ������Ŀ
    EMPFaceLocation* pLocations;// ÿ��������λ��
};

//@brief �������׿��в��ҵĽ��
struct SQueryResult
{
    int nID = 0;// �����Ƶļ�¼ ID
    float fSim = -0.0f;// ���ƶ�
    char  sName[128] = { 0 };// �����Ƶ���������
};

typedef void* XDHandle; // ���� handle 

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