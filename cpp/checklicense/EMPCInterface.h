#pragma once

#include "EMPStructs_c.h"

#ifdef __cplusplus
extern "C"
{
#endif
    const char* XDGetVersion();

    void XDEnableLog(bool bEnable = true);

    //////////////////////////////////////////////////////////////////////////
    /*                  ��Ȩ��֤                                             */
    //////////////////////////////////////////////////////////////////////////
    //@brief ʹ��ָ������Ȩ�ļ�����Ŀ¼������Ȩ��֤
    //@param const char* pPath: ��Ȩ�ļ����ڵ�Ŀ¼
    //@param int* pErrorCode:������������ڷ���ת�����̵Ĵ����롣
    //@return ��Ȩ��֤�����true��ʾ��Ȩ�ɹ���false��ʾ��Ȩʧ��
    bool XDAuthCheck1(const char* pPath, int* pErrorCode = nullptr);

    //@brief ʹ��ָ������Ȩ�ļ�����Ŀ¼������Ȩ��֤
    //@param const char* pCode: �������ַ���
    //@param const char* pLicense: ��Ȩ���ַ���
    //@param int* pErrorCode:������������ڷ���ת�����̵Ĵ����롣
    //@return ��Ȩ��֤�����true��ʾ��Ȩ�ɹ���false��ʾ��Ȩʧ��
    bool XDAuthCheck2(const char* pCode, const char* pLicense, int* pErrorCode = nullptr);

    //@brief ��ȡ��ǰ����Ȩ��֤״̬
    //@return ��Ȩ��֤�����true��ʾ��Ȩ�ɹ���false��ʾ��Ȩʧ��
    bool XDAuthGetStatus();

    //////////////////////////////////////////////////////////////////////////
    /*                  ���뻺��������                                       */
    //////////////////////////////////////////////////////////////////////////
    //@brief ��������ת���ӿڣ�������Ķ������ظ�ʽ�Ļ�����ת����BGR�Ļ�������ע�⣬
    // C++�����ڲ�ֻ����BGR��ʽ��ͼ�����ݣ��ҽӿ������ͼ�����ݶ���BGR��ʽ��
    // ͨ���˽ӿ����ɵ�ͼ�����ݣ�����ͨ��XDReleaseImg�ӿ��ͷţ�����ᷢ���ڴ�й¶��
    //@param const unsigned char* pData:ͼ�����ݻ��������ڲ�ֻ���û������Ƿ�Ϊ��
    //@param int nw, int nh: ͼ����ߡ��ڲ����ò����Ƿ�<0��
    //@param EPIXTYPE eType: ͼ�����ظ�ʽ��
    //           EBGR --- BGR���У� opencv��ȡͼ����Ĭ������
    //           ERGBA--- RGBA���У�android����ͼ����Ĭ�ϸ�ʽ����
    //           ENV21--- YUV-NV21���У�android������л�ȡ��ͼ��buffer�����ݸ�ʽ��
    //           EFILENAME--��ָ���ļ������ļ��ж�ȡ�ļ���pData�����ļ���
    //           EFILEBUFFER--���ļ�������buffer�н���ͼ��pData�ǻ�����ָ�룬nw��ʾ���������ȡ�
    //@param EROTATETYPE eRotateType:ͼ����ת�Ƕȣ�˳ʱ��90�㣬180�㣬270���Լ�0����ת��
    // ������ֵ�μ�EMPStructs_c.h�е�enum EROTATETYPE��������
    //@param int* pErrorCode:������������ڷ���ת�����̵Ĵ����롣
    //return EMPIMG2_C*:ʹ�����뻺�������н��룬��ת֮���ͼ��ָ�룬3ͨ����BGR���С�
    //���ת��ʧ�ܣ�����nullptr,ͨ��pErrorCode��ʾʧ��ԭ��
    EMPIMG2_C* XDCreateImg(const unsigned char* pData, int nw, int nh, \
        EPIXTYPE eType, EROTATETYPE eRotateType,int* pErrorCode = nullptr);

    //@brief �ͷ�XDCreateImg�ӿ����ɵ�ͼ�񻺳�����
    //@param EMPIMG2_C* pImg:׼���ͷŵ�ͼ�񻺳���ָ�롣
    //@note ���ӿ�ֻ�������ͷ�EMPIMG2_C*���͵�ͼ�񻺳������ڲ�ֻ������ָ��ǿ��жϡ�
    //ʹ������ӿ��ͷ��������͵�ָ�룬�����δ֪�ģ����ܵ��³��������
    void       XDReleaseImg(EMPIMG2_C* pImg);

    //////////////////////////////////////////////////////////////////////////
    /*                        �������                                       */
    //////////////////////////////////////////////////////////////////////////
    //@brief �����������������ͨ��ָ��Ŀ¼�µ�ģ���ļ����г�ʼ�������ض���handle
    //@param const char* pModelPath:ģ���ļ�����Ŀ¼
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: ��������ʼ���ɹ����������������handle��
    // ����ʧ��ʱ������nullptr.
    //@note �����Ķ���handle����ͨ��XDReleaseDetector�ӿ��ͷš�
    XDHandle XDCreateDetector1(const char* pModelPath, int* pErrorCode = nullptr);

    //@brief �����������������ͨ�������ģ�ͻ�������ʼ�������ض���handle
    //@param const char* pBuf:ģ�ͻ�����
    //@param int nBufLen: ����������
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: ��������ʼ���ɹ����������������handle��
    // ����ʧ��ʱ������nullptr.
    //@note �����Ķ���handle����ͨ��XDReleaseDetector�ӿ��ͷš�
    XDHandle XDCreateDetector2(const char* pBuf, int nBufLen, int* pErrorCode = nullptr);

    //@brief ʹ��ָ�����������������ָ�������뻺����������������⣬����������Ŀ������λ��
    //@param XDHandle handle: �������������handle.
    //@param unsigned char* pData, int nw, int nh,EPIXTYPE eType,
    // EROTATETYPE eRotateType : ����ͼ�񻺳����������Ķ���μ�XDCreateImg˵�����ӿ��ڲ�
    // ����XDCreateImg�����뻺����������ת����
    //@param int* pErrorCode: ������������ڷ��ؼ������еĴ����롣
    //@return EMPFaceDetectResult*:��������μ�EMPStructs_c.h�еĶ��塣���ʧ��ʱ����nullptr.
    //@note ���ص�ָ�����ͨ��XDReleaseDetectResult�ӿ��ͷš�
    EMPFaceDetectResult* XDDetectFace1(XDHandle handle, unsigned char* pData, int nw, \
        int nh,EPIXTYPE eType, EROTATETYPE eRotateType, int* pErrorCode = nullptr);

    //@brief ʹ��ָ�����������������ָ�������뻺����������������⣬����������Ŀ������λ��
    //@param XDHandle handle: �������������handle.
    //@param EMPIMG2_C* pImg: BGR��ʽ�����뻺������
    //@param int* pErrorCode: ������������ڷ��ؼ������еĴ����롣
    //@return EMPFaceDetectResult*:��������μ�EMPStructs_c.h�еĶ��塣���ʧ��ʱ����nullptr.
    //@note ���ص�ָ�����ͨ��XDReleaseDetectResult�ӿ��ͷš�
    EMPFaceDetectResult* XDDetectFace2(XDHandle handle, EMPIMG2_C* pImg,\
        int* pErrorCode = nullptr);

    //@brief �ͷ��������Ľ��
    void     XDReleaseDetectResult(EMPFaceDetectResult* pRes);

    //@brief �ͷ��������������
    void     XDReleaseDetector(XDHandle handle);


    //////////////////////////////////////////////////////////////////////////
    /*                       �����ؼ��㶨λ                                  */
    //////////////////////////////////////////////////////////////////////////
    //@brief ���������ؼ��㶨λ����ͨ��ָ��Ŀ¼�µ�ģ���ļ����г�ʼ�������ض���handle
    //@param const char* pModelPath:ģ���ļ�����Ŀ¼
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: ��������ʼ���ɹ��������ؼ��㶨λ������handle��
    // ����ʧ��ʱ������nullptr.
    //@note �����Ķ���handle����ͨ��XDReleaseLandmarker�ӿ��ͷ�
    XDHandle XDCreateLandmarker1(const char* pModelPath, int* pErrorCode = nullptr);

    //@brief ���������ؼ��㶨λ����ͨ�������ģ�ͻ�������ʼ�������ض���handle
    //@param const char* pBuf:ģ�ͻ�����
    //@param int nBufLen: ����������
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: ��������ʼ���ɹ��������ؼ��㶨λ������handle��
    // ����ʧ��ʱ������nullptr.
    //@note �����Ķ���handle����ͨ��XDReleaseLandmarker�ӿ��ͷš�
    XDHandle XDCreateLandmarker2(const char* pBuf, int nBufLen, int* pErrorCode = nullptr);

    //@brief ʹ��ָ���������ؼ��㶨λ�����󣬶�����ͼ���ϵ�ָ�����������йؼ��ڶ�λ
    //@param XDHandle handle: �ؼ��㶨λ������handle
    //@param EMPIMG2_C* pImg: ����ͼ��
    //@param EMPFaceLocation* pLoc: ָ������λ��
    //@param int* pErrorCode: ������������ڷ��ع����еĴ����롣
    //@return EMPFaceLandmarks*: �ɹ��򷵻�ָ��������landmark�����꣬���򷵻ؿ�ָ�롣
    EMPFaceLandmarks* XDExtractKeypoints(XDHandle handle, EMPIMG2_C* pImg, EMPFaceLocation* pLoc, int* pErrorCode = nullptr);

    //@brief �ͷ�XDExtractKeypoints���ص������ؼ�������
    void XDReleaseKeypoints(EMPFaceLandmarks* plms);

    //@brief �ͷ������ؼ�����������
    void XDReleaseLandmarker(XDHandle handle);

    //////////////////////////////////////////////////////////////////////////
    /*                      ��������                                         */
    //////////////////////////////////////////////////////////////////////////
    //@brief ���������������
    //@return �����������handle
    XDHandle XDCreateAligner();

    //@brief ʹ��ָ��������������󣬶�����ͼ����ָ������ʹ����landmark����ж���
    //@param XDHandle handle: �����������handle
    //@param EMPIMG2_C* pSrc: ����ͼ��ֻ����3ͨ��B-G-R��ʽ���롣
    //@param EMPFaceLandmarks* pLms: ����landmark��λ��
    //@param int* pErrorCode: ������������ڷ��ع����еĴ����롣
    //@return EMPIMG2_C*: �������������ͼ��ʧ���򷵻�nullptr��
    //@note ���صĽ��ͼ����Ҫʹ��XDReleaseAlignedFace�ӿڻ�XDReleaseImg�ӿ��ͷš�
    // ���صĶ���ͼ���ǰ���B-G-R��ʽ���е�3ͨ��ͼ��
    EMPIMG2_C* XDAlginFace(XDHandle handle, EMPIMG2_C* pSrc, EMPFaceLandmarks* pLms, int* pErrorCode = nullptr);

    //@brief �ͷ�XDAlginFace�ӿڷ��صĶ���ͼ��
    void XDReleaseAlignedFace(EMPIMG2_C* pImg);

    //@brief �ͷ������������
    void XDReleaseAligner(XDHandle handle);

    //////////////////////////////////////////////////////////////////////////
    /*                      ����������ȡ                                     */
    //////////////////////////////////////////////////////////////////////////
    //@brief ��������ʶ������ͨ��ָ��Ŀ¼�µ�ģ���ļ����г�ʼ�������ض���handle
    //@param const char* pModelPath:ģ���ļ�����Ŀ¼
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: ��������ʼ���ɹ�������ʶ��������handle��
    // ����ʧ��ʱ������nullptr.
    //@note �����Ķ���handle����ͨ��XDReleaseRecognizer�ӿ��ͷ�
    XDHandle XDCreateRecognizer1(const char* pModelPath, int* pErrorCode = nullptr);

    //@brief ��������ʶ������ͨ�������ģ�ͻ�������ʼ�������ض���handle
    //@param const char* pBuf:ģ�ͻ�����
    //@param int nBufLen: ����������
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: ��������ʼ���ɹ�������ʶ��������handle��
    // ����ʧ��ʱ������nullptr.
    //@note �����Ķ���handle����ͨ��XDReleaseRecognizer�ӿ��ͷš�
    XDHandle XDCreateRecognizer2(const char* pBuf, int nBufLen, int* pErrorCode = nullptr);

    //@brief ��ȡ����ʶ����ʹ�õ�float�����ĳ��ȡ�
    //@return float�������ȣ���ǰ����256.
    int XDGetFloatFeatureLength();

    //@brief ��ȡ����ʶ����ʹ�õ�unsigned char �����ĳ���
    //@return unsigned char �������ȣ���ǰ����264.
    int XDGetUCFeatureLength();

    //@brief ʹ��ָ��������ʶ������������ľ����������������������ȡ��
    //@param XDHandle handle: ����ʶ��������handle
    //@param EMPIMG2_C* pFace: �����������������������ͼ��3ͨ����B-G-R��ʽ,112*112��С
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return float*: ��ȡ��float�������飬����ͨ��XDGetFloatFeatureLength()�ӿ�ȷ������ȡʧ��ʱ����nullptr.
    //@note ���ص����������ڴ��ɿ�ά������Ҫʹ��XDReleaseFloatFeature�ӿ��ͷš�
    float* XDExtractFloatFeature(XDHandle handle, EMPIMG2_C* pFace, int* pErrorCode = nullptr);

    //@brief �ͷ�XDExtractFloatFeature���ص�float����ָ�롣
    void XDReleaseFloatFeature(float* pFeat);

    //@brief ʹ��ָ��������ʶ������������ľ����������������������ȡ��
    //@param XDHandle handle: ����ʶ��������handle
    //@param EMPIMG2_C* pFace: �����������������������ͼ��3ͨ����B-G-R��ʽ,112*112��С
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return unsigned char*: ��ȡ��unsigned char�������飬����ͨ��XDGetUCFeatureLength()�ӿ�ȷ������ȡʧ��ʱ����nullptr.
    //@note ���ص����������ڴ��ɿ�ά������Ҫʹ��XDRealeaseUCFeature�ӿ��ͷš�
    unsigned char* XDExtractUCFeature(XDHandle handle, EMPIMG2_C* pFace, int* pErrorCode = nullptr);

    //@brief �ͷ�XDExtractUCFeature���ص�unsigned char����ָ�롣
    void XDRealeaseUCFeature(unsigned char* pFeat);

    //@brief �ͷ�����ʶ��������
    void XDReleaseRecognizer(XDHandle handle);

    //@brief ��������float���͵����������ƶ�
    //@param const float* pFeat1: ��һ��float����
    //@param const float* pFeat2: �ڶ���float����
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return float: �������������ƶȣ�ȡֵ��ΧΪ-1.0f~1.0f
    //@note �ӿ��ڲ��ٶ������floatָ��ָ�����һ���������ٰ���XDGetFloatFeatureLength()��float���ݵĻ�������
    // �ӿ��ڲ�ֻ�������ָ���Ƿ�Ϊ�գ���������л��ȡXDGetFloatFeatureLength()��float���ڼ��㡣
    // �������ⲻ�Ϸ�ʱ�����ô�����֮�󣬷���-1.0f.
    float XDCalcSim1(const float* pFeat1, const float* pFeat2, int* pErrorCode = nullptr);

    //@brief ����һ��float������һ��unsigned char���������ƶ�
    //@param const float* pFeat1: ��һ��float����
    //@param const unsigned char* pucFeat2: �ڶ���unsigned char����
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return float: �������������ƶȣ�ȡֵ��ΧΪ-1.0f~1.0f
    //@note �ӿ��ڲ��ٶ������floatָ��ָ�����һ���������ٰ���XDGetFloatFeatureLength()��float���ݵĻ�������
    // �ӿ��ڲ��ٶ������unsigned charָ��ָ�����һ���������ٰ���XDGetUCFeatureLength()��unsigned char���ݵĻ�������
    // �ӿ��ڲ�ֻ�������ָ���Ƿ�Ϊ�գ���������л��ȡXDGetFloatFeatureLength()��float���ڼ��㡣
    // ����unsigned char���������ȡXDGetUCFeatureLength()��unsigned char�������ڼ��㡣
    // �������ⲻ�Ϸ�ʱ�����ô�����֮�󣬷���-1.0f.
    float XDCalcSim2(const float* pFeat1, const unsigned char* pucFeat2, int* pErrorCode = nullptr);

    //@brief ��������unsigned char���͵����������ƶ�
    //@param const unsigned char* pFeat1: ��һ��unsigned char����
    //@param const unsigned char* pFeat2: �ڶ���unsigned char����
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return float: �������������ƶȣ�ȡֵ��ΧΪ-1.0f~1.0f
    //@note �ӿ��ڲ��ٶ������unsigned charָ��ָ�����һ���������ٰ���XDGetFloatFeatureLength()��unsigned char���ݵĻ�������
    // �ӿ��ڲ�ֻ�������ָ���Ƿ�Ϊ�գ���������л��ȡXDGetUCFeatureLength()��unsigned char���ڼ��㡣
    // �������ⲻ�Ϸ�ʱ�����ô�����֮�󣬷���-1.0f.
    float XDCalcSim3(const unsigned char* pucFeat1, const unsigned char* pucFeat2, int* pErrorCode = nullptr);

    //////////////////////////////////////////////////////////////////////////
    /*                      ������������                                   */
    //////////////////////////////////////////////////////////////////////////
    //@brief ��һ��float���͵����������unsigned char���͵�����
    //@param const float* pFeat: �����float�������ӿڼٶ���ָ��ָ����ǳ��Ȳ�С��XDGetFloatFeatureLength()
    // �Ļ��������ӿ��ڲ����ָ���Ƿ�Ϊ��֮�󣬻��ȡXDGetFloatFeatureLength()��float���ڴ���
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return �ɹ��򷵻ر�����unsigned char���͵�����ָ�룬����ΪXDGetUCFeatureLength()ָ����
    // ���򷵻�nullptr
    //@note ���ص�����ֵָ�룬����ͨ��XDRealeaseUCFeature�ͷš�
    unsigned char* XDEncodeFeature(const float* pFeat,int* pErrorCode = nullptr);

    //@brief ��һ��unsigned char���͵����������float���͵�����
    //@param const unsigned char* pFeat: �����unsigned char�������ӿڼٶ���ָ��ָ����ǳ��Ȳ�С��XDGetUCFeatureLength()
    // �Ļ��������ӿ��ڲ����ָ���Ƿ�Ϊ��֮�󣬻��ȡXDGetUCFeatureLength()��unsigned char���ڴ���
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return �ɹ��򷵻ؽ�����float���͵�����ָ�룬����ΪXDGetFloatFeatureLength()ָ����
    // ���򷵻�nullptr
    //@note ���ص�����ֵָ�룬����ͨ��XDRealeaseFloatFeature�ͷš�
    float* XDDecodeFeature(const unsigned char* pFeat, int* pErrorCode = nullptr);

    //////////////////////////////////////////////////////////////////////////
    /*                      �����׿����                                     */
    //////////////////////////////////////////////////////////////////////////
    //@brief ���������׿�
    //@return �����׿����handle
    XDHandle XDCreateDB();

    //@brief ��ָ��·���µ������׿��ļ�
    //@param XDHandle handle: �����������׿����handle
    //@param const char* pDBPath: �����׿��ļ�·���������׿��ļ�����
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: ���سɹ�ʱ���������ݿ�׿�handle��
    //@note ������ݿ��ļ������ڣ��ӿڻᴴ���׿��ļ����ӿڳɹ�ִ��ʱ�����ڵ׿������ļ���
    // ����������Ϣ�ṹ��һ�����ݱ�
    XDHandle XDOpenDB(XDHandle handle,const char* pDBPath, int* pErrorCode = nullptr);
    
    //@brief �ر�ָ���������׿⡣
    XDHandle XDCloseDB(XDHandle handle,int* pErrorCode = nullptr);
    
    //@brief �ͷ������׿����
    void XDReleaseDB(XDHandle handle);
    
    //@brief ��ָ���������׿�����У����һ������ΪpName, ����ֵάpFeat��һ��������
    //@param XDHanle handle: �����׿����handle
    //@param const char* pName: ����ӵ���������
    //@param float* pFeat: ����ӵ���������ֵ������
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return XDHandle: �����׿����handle��
    XDHandle XDAddToDB(XDHandle handle, const char* pName, float* pFeat, int* pErrorCode = nullptr);
    
    //@brief ��ָ���������׿��У�������ָ�����������Ƶ����������ƣ���¼ID�Լ����ƶ�
    //@param XDHandle handle: �����׿����handle
    //@param float* pFeat: �����ҵ���������
    //@param int* pErrorCode: ������������ڷ��ش��������еĴ����롣
    //@return SQueryResult*: ���ص׿�����ָ�����������Ƶ��������ƣ���¼ID�Լ����ƶȣ�ʧ�ܷ���nullptr
    //@note �������ͨ��XDReleaseQueryResult�ͷ�
    SQueryResult* XDQueryTop(XDHandle handle, float* pFeat, int* pErrorCode = nullptr);
    
    //@brief �ͷ������׿���������
    void XDReleaseQueryResult(SQueryResult* pQueryResult);


#ifdef __cplusplus
}
#endif