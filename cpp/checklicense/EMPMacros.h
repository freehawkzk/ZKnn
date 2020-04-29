#pragma once
//ͼ���ļ����������������У��������ص����ظ�ʽ
#define EMP_PIXTYPE_BGR  1  //24λ3ͨ��B-G-R����
#define EMP_PIXTYPE_RGB  2  //24λ3ͨ��R-G-B����
#define EMP_PIXTYPE_BGRA 3  //32λ4ͨ��B-G-R-A����
#define EMP_PIXTYPE_RGBA 4  //32λ4ͨ��R-G-B-A����
#define EMP_PIXTYPE_ABGR 5  //32λ4ͨ��A-B-G-R����
#define EMP_PIXTYPE_ARGB 6  //32λ4ͨ��A-R-G-B����
#define EMP_PIXTYPE_GRAY 7  //��ͨ���Ҷ�ͼ
#define EMP_PIXTYPE_YUV420_NV21 8 //����YUV420��ʽ���е�ͼ������
#define EMP_PIXTYPE_DECODE_FROM_MEMORY 9 //���ڴ��н���

#define EMP_ROTATE_CLOCKWISE_0                             0      //˳ʱ����ת0��
#define EMP_ROTATE_CLOCKWISE_90                            1      //˳ʱ����ת90��
#define EMP_ROTATE_CLOCKWISE_180                           2      //˳ʱ����ת180��
#define EMP_ROTATE_CLOCKWISE_270                           3      //˳ʱ����ת270��
#define EMP_ROTATE_CLOCKWISE_360                           4      //˳ʱ����ת360��
#define EMP_ROTATE_COUNTER_CLOCKWISE_0   EMP_ROTATE_CLOCKWISE_360 //��ʱ����ת0�ȣ��ȼ���˳ʱ����ת0��
#define EMP_ROTATE_COUNTER_CLOCKWISE_90  EMP_ROTATE_CLOCKWISE_270 //��ʱ����ת90�ȣ��ȼ���˳ʱ����ת270��
#define EMP_ROTATE_COUNTER_CLOCKWISE_180 EMP_ROTATE_CLOCKWISE_180 //��ʱ����ת180�ȣ��ȼ���˳ʱ����ת180��
#define EMP_ROTATE_COUNTER_CLOCKWISE_270 EMP_ROTATE_CLOCKWISE_90  //��ʱ����ת270�ȣ��ȼ���˳ʱ����ת90��
#define EMP_ROTATE_COUNTER_CLOCKWISE_360 EMP_ROTATE_CLOCKWISE_0  //��ʱ����ת270�ȣ��ȼ���˳ʱ����ת90��


#define EMP_OK                                      0           //ִ�гɹ�
#define EMP_FAIL                                 -100           //ִ��ʧ��
#define EMP_PARAMERROR                           (EMP_FAIL -  1)//�ӿڲ�������
#define EMP_GETMODELMGRFAILED                    (EMP_FAIL -  2)//��ȡģ�͹�����ʧ��
#define EMP_GETMODELFAILED                       (EMP_FAIL -  3)//��ȡģ��ʧ��
#define EMP_ERROR_NO_FACE                        (EMP_FAIL -  4)//δ��⵽����
#define EMP_FEATEXTRACEERROR                     (EMP_FAIL -  5)//����������ȡʧ��
#define EMP_ERROR_MACHINE_CODE_FILE_NOT_EXIST    (EMP_FAIL -  6)//��ȡ������ʧ��
#define EMP_ERROR_LICENSE_NOT_EXIST              (EMP_FAIL -  7)//��Ȩ�ļ�������
#define EMP_ERROR_MACHINE_CODE_NOT_MATCH_LISENCE (EMP_FAIL -  8)//��Ȩ�ļ�������벻ƥ��
#define EMP_ERROR_JNI_INPUT_STRING_LENGTH_ERROR  (EMP_FAIL -  9)//JNI �����ַ������ȴ���
#define EMP_ERROR_JNI_GET_CACHE_ROOT_PATH_ERROR  (EMP_FAIL - 10)//JNI ��ȡ������ⲿ�洢��Ŀ¼�ַ�������ʧ��
#define EMP_ERROR_JNI_GET_MACHINE_CODE_ERROR     (EMP_FAIL - 11)//JNI ��ȡ����Ļ������ַ�������ʧ��
#define EMP_ERROR_JNI_GET_LICENSE_PATH_ERROR     (EMP_FAIL - 12)//JNI ��ȡ�������Ȩ�ļ�·���ַ�������ʧ��
#define EMP_ERROR_NULL_CACHE_ROOT                (EMP_FAIL - 13)//C++ �ⲿ�洢·��Ϊ��
#define EMP_ERROR_NULL_MACHINE_CODE              (EMP_FAIL - 14)//C++ ������Ϊ��
#define EMP_ERROR_NULL_LICENSE_PATH              (EMP_FAIL - 15)//C++ ��Ȩ�ļ�·��Ϊ��
#define EMP_ERROR_MACHINE_CODE_MISMATCH_MACHINE  (EMP_FAIL - 16)//C++ �������������ƥ��
#define EMP_ERROR_MACHINE_CODE_MISMATCH_LICENSE  (EMP_FAIL - 17)//C++ ����������Ȩ�ļ���ƥ��
#define EMP_ERROR_NULL_HANDLE                    (EMP_FAIL - 18)//C++ ���������handlΪ��
#define EMP_ERROR_UNSUPPORT_PIXEL_FORMAT         (EMP_FAIL - 19)//C++ ��֧�ֵ��������и�ʽ
#define EMP_ERROR_INTERNAL_ERROR                 (EMP_FAIL - 20)//C++ �ڲ�����
#define EMP_ERROR_NULL_IMAGE_DATA                (EMP_FAIL - 21)//C++ ͼ������Ϊ��
#define EMP_ERROR_IMAGE_WIDTH_HEIGHT_ERROR       (EMP_FAIL - 22)//C++ ͼ���ߴ���
#define EMP_ERROR_NULL_OUTPUT_BUFFER             (EMP_FAIL - 23)//C++ ���������ָ��Ϊ��
#define EMP_ERROR_OUTPUT_BUFFER_SIZE_ERROR       (EMP_FAIL - 24)//C++ �����������С����
#define EMP_ERROR_IMGDATALENGTH_ERROR            (EMP_FAIL - 25)//C++ ͼ�����ݳ��ȳ���
#define EMP_ERROR_GETIMGDATA_ERROR               (EMP_FAIL - 26)//C++ ��ȡͼ�����ݳ���
#define EMP_ERROR_LOADMODELERROR                 (EMP_FAIL - 27)//C++ ����ģ��ʧ��
#define EMP_ERROR_MAX_OUTPUT_SIZE_ERROR          (EMP_FAIL - 28)//C++ ��������������
#define EMP_ERROR_NULL_MAX_OUTPUT_SIZE           (EMP_FAIL - 29)//C++ ����������ָ��Ϊ��
#define EMP_ERROR_CONVERT_INPUT_IMAGE_ERROR      (EMP_FAIL - 30)//C++ ����ͼ��ת����ʽʧ��
#define EMP_ERROR_PREDICT_LANDMARK_FAILED        (EMP_FAIL - 31)//C++ Ԥ������������λ��ʧ��
#define EMP_ERROR_MODELNOTEXIST                  (EMP_FAIL - 32)//C++ ָ����ģ��·���²�������Ҫ��ģ���ļ�
#define EMP_ERROR_LICENSE_TIME_OUT               (EMP_FAIL - 33)//C++ ������Ȩʱ��
#define EMP_ERROR_NULL_INPUT_BUFFER              (EMP_FAIL - 34)//C++ ���뻺����Ϊ��
#define EMP_ERROR_INPUT_BUFFER_SIZE_ERROR        (EMP_FAIL - 35)//C++ ���뻺�������ȴ���
#define EMP_ERROR_INPUT_DATA_NOT_USABLE          (EMP_FAIL - 36)//C++ ��������ݲ��Ϸ�
#define EMP_ERROR_PREDICT_FACE_LANDMARK_ERROR    (EMP_FAIL - 37)//C++ ����landmark��Ԥ��ʧ��
#define EMP_ERROR_LICENSE_CHECK_FAILED           (EMP_FAIL - 38)//C++ ��Ȩ��֤ʧ��
#define EMP_ERROR_FEATURE_ENCODE_ERROR           (EMP_FAIL - 39)//C++ ��������ʧ��
#define EMP_ERROR_FEATURE_DECODE_ERROR           (EMP_FAIL - 40)//C++ ��������ʧ��
#define EMP_ERROR_NULL_INPUT_IMG                 (EMP_FAIL - 41)//C++ ����ͼ��Ϊ��
#define EMP_ERROR_MACHINECODEFILESIZE            (EMP_FAIL - 42)//C++ �������ļ���С����
#define EMP_ERROR_LICENSEFILESIZE                (EMP_FAIL - 43)//C++ ��Ȩ�ļ���С����
#define EMP_ERROR_BIND_PORT_ERROR                (EMP_FAIL - 44)//C++ �󶨶˿ڳ���
#define EMP_ERROR_CREATE_UDP                     (EMP_FAIL - 45)//C++ ����UDPͨ���׽��ֳ���
#define EMP_ERROR_PROCESS_TIME_OUT               (EMP_FAIL - 46)//C++ ������̳�ʱ
#define EMP_ERROR_NULL_SOCKET                    (EMP_FAIL - 47)//C++ socketΪ��
#define EMP_ERROR_NULL_FACE_RANGE_DATA           (EMP_FAIL - 48)//C++ �������򻺳���Ϊ��
#define EMP_ERROR_UNSUPPORT_ROTATE_ANGLE         (EMP_FAIL - 49)//C++ ��֧�ֵ�ͼ����ת�Ƕ�
#define EMP_ERROR_FACE_ID_NOT_EXIST              (EMP_FAIL - 50)//C++ ָ����face id������
#define EMP_ERROR_CONVERT_JAVA_EMPIMG_TO_CEMPIMG (EMP_FAIL - 51)//JNI ��java�е�EMPIMGת����C�е�EMPIMGʧ��
#define EMP_ERROR_NEW_OPERATE_FAILED             (EMP_FAIL - 52)//new operate failed
#define EMP_ERROR_IMREAD_FAILED                  (EMP_FAIL - 53)//��ȡͼ���ļ�ʧ��
#define EMP_ERROR_IMDECODE_FAILED                (EMP_FAIL - 54)//����ͼ��ʧ��
#define EMP_ERROR_LOCAL_GROUP_NAME_EMPTY         (EMP_FAIL - 55)//�����������ݿ�����Ϊ��
#define EMP_ERROR_EMPTY_FACE_NAME                (EMP_FAIL - 56)//��������Ϊ��
#define EMP_ERROR_STORE_LOCAL_GROUP_FAILED       (EMP_FAIL - 57)//���汾���������ݿ�ʧ��
#define EMP_ERROR_DELETE_LOCAL_GROUP_FAILED      (EMP_FAIL - 58)//ɾ�������������ݿ�ʧ��
#define EMP_ERROR_RESTORE_LOCAL_GROUP_FAILED     (EMP_FAIL - 59)//���ر����������ݿ�ʧ��
#define EMP_ERROR_NOT_CONFIGED                   (EMP_FAIL - 60)//����δ����
#define EMP_ERROR_NOT_INITED                     (EMP_FAIL - 61)//����δ��ʼ��
#define EMP_ERROR_CREATE_TABLE_FAILED            (EMP_FAIL - 62)//�ڱ����������ݿ��д������ݱ�ʧ��
#define EMP_ERROR_SQL_ERROR                      (EMP_FAIL - 63)//sqlite3ִ��sql���ʧ��
#define EMP_ERROR_CREATE_FACE_DB_FAILED          (EMP_FAIL - 64)//�����������ݿ�ʧ��
#define EMP_ERROR_TABLE_NOT_EXIST                (EMP_FAIL - 65)//�������ݿ��в�����ָ�������ݿ��
#define EMP_ERROR_OPEN_LOCAL_GROUP_FAILED        (EMP_FAIL - 66)//�򿪱����������ݿ�ʧ��
#define EMP_ERROR_ALIGN_FACE_FAILED              (EMP_FAIL - 67)//��������ʧ��


#define EMP_MAX_PROCESS_TIME                     (30000)//����ͼ�������ʱ�䣬��λ������
#ifdef _MSC_VER
#ifdef EMP_EXPORTS
#define EMP_API __declspec(dllexport)
#else
#define EMP_API __declspec(dllimport)
#endif
#else
#define EMP_API __attribute__ ((visibility("default")))
#endif


#define CHECK(hr) if (hr!=EMP_OK){return hr;}

//���ô�����
#define SetErrorCode(pErrorCode,errorcode) do \
{\
    if(pErrorCode!=nullptr)\
    {\
        *pErrorCode = errorcode;\
    }\
} while (0);


#ifndef empmax
#define empmax(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef empmin
#define empmin(a,b)            (((a) < (b)) ? (a) : (b))
#endif

