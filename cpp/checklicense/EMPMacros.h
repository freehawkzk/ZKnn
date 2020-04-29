#pragma once
//图像文件经过解码后的数据中，单个像素的像素格式
#define EMP_PIXTYPE_BGR  1  //24位3通道B-G-R排列
#define EMP_PIXTYPE_RGB  2  //24位3通道R-G-B排列
#define EMP_PIXTYPE_BGRA 3  //32位4通道B-G-R-A排列
#define EMP_PIXTYPE_RGBA 4  //32位4通道R-G-B-A排列
#define EMP_PIXTYPE_ABGR 5  //32位4通道A-B-G-R排列
#define EMP_PIXTYPE_ARGB 6  //32位4通道A-R-G-B排列
#define EMP_PIXTYPE_GRAY 7  //单通道灰度图
#define EMP_PIXTYPE_YUV420_NV21 8 //按照YUV420格式排列的图像数据
#define EMP_PIXTYPE_DECODE_FROM_MEMORY 9 //从内存中解码

#define EMP_ROTATE_CLOCKWISE_0                             0      //顺时针旋转0度
#define EMP_ROTATE_CLOCKWISE_90                            1      //顺时针旋转90度
#define EMP_ROTATE_CLOCKWISE_180                           2      //顺时针旋转180度
#define EMP_ROTATE_CLOCKWISE_270                           3      //顺时针旋转270度
#define EMP_ROTATE_CLOCKWISE_360                           4      //顺时针旋转360度
#define EMP_ROTATE_COUNTER_CLOCKWISE_0   EMP_ROTATE_CLOCKWISE_360 //逆时针旋转0度，等价于顺时针旋转0度
#define EMP_ROTATE_COUNTER_CLOCKWISE_90  EMP_ROTATE_CLOCKWISE_270 //逆时针旋转90度，等价于顺时针旋转270度
#define EMP_ROTATE_COUNTER_CLOCKWISE_180 EMP_ROTATE_CLOCKWISE_180 //逆时针旋转180度，等价于顺时针旋转180度
#define EMP_ROTATE_COUNTER_CLOCKWISE_270 EMP_ROTATE_CLOCKWISE_90  //逆时针旋转270度，等价于顺时针旋转90度
#define EMP_ROTATE_COUNTER_CLOCKWISE_360 EMP_ROTATE_CLOCKWISE_0  //逆时针旋转270度，等价于顺时针旋转90度


#define EMP_OK                                      0           //执行成功
#define EMP_FAIL                                 -100           //执行失败
#define EMP_PARAMERROR                           (EMP_FAIL -  1)//接口参数错误
#define EMP_GETMODELMGRFAILED                    (EMP_FAIL -  2)//获取模型管理器失败
#define EMP_GETMODELFAILED                       (EMP_FAIL -  3)//获取模型失败
#define EMP_ERROR_NO_FACE                        (EMP_FAIL -  4)//未检测到人脸
#define EMP_FEATEXTRACEERROR                     (EMP_FAIL -  5)//人脸特征提取失败
#define EMP_ERROR_MACHINE_CODE_FILE_NOT_EXIST    (EMP_FAIL -  6)//获取机器码失败
#define EMP_ERROR_LICENSE_NOT_EXIST              (EMP_FAIL -  7)//授权文件不存在
#define EMP_ERROR_MACHINE_CODE_NOT_MATCH_LISENCE (EMP_FAIL -  8)//授权文件与机器码不匹配
#define EMP_ERROR_JNI_INPUT_STRING_LENGTH_ERROR  (EMP_FAIL -  9)//JNI 输入字符串长度错误
#define EMP_ERROR_JNI_GET_CACHE_ROOT_PATH_ERROR  (EMP_FAIL - 10)//JNI 获取输入的外部存储根目录字符串内容失败
#define EMP_ERROR_JNI_GET_MACHINE_CODE_ERROR     (EMP_FAIL - 11)//JNI 获取输入的机器码字符串内容失败
#define EMP_ERROR_JNI_GET_LICENSE_PATH_ERROR     (EMP_FAIL - 12)//JNI 获取输入的授权文件路径字符串内容失败
#define EMP_ERROR_NULL_CACHE_ROOT                (EMP_FAIL - 13)//C++ 外部存储路径为空
#define EMP_ERROR_NULL_MACHINE_CODE              (EMP_FAIL - 14)//C++ 机器码为空
#define EMP_ERROR_NULL_LICENSE_PATH              (EMP_FAIL - 15)//C++ 授权文件路径为空
#define EMP_ERROR_MACHINE_CODE_MISMATCH_MACHINE  (EMP_FAIL - 16)//C++ 机器码与机器不匹配
#define EMP_ERROR_MACHINE_CODE_MISMATCH_LICENSE  (EMP_FAIL - 17)//C++ 机器码与授权文件不匹配
#define EMP_ERROR_NULL_HANDLE                    (EMP_FAIL - 18)//C++ 人脸检测器handl为空
#define EMP_ERROR_UNSUPPORT_PIXEL_FORMAT         (EMP_FAIL - 19)//C++ 不支持的像素排列格式
#define EMP_ERROR_INTERNAL_ERROR                 (EMP_FAIL - 20)//C++ 内部错误
#define EMP_ERROR_NULL_IMAGE_DATA                (EMP_FAIL - 21)//C++ 图像数据为空
#define EMP_ERROR_IMAGE_WIDTH_HEIGHT_ERROR       (EMP_FAIL - 22)//C++ 图像宽高错误
#define EMP_ERROR_NULL_OUTPUT_BUFFER             (EMP_FAIL - 23)//C++ 输出缓冲区指针为空
#define EMP_ERROR_OUTPUT_BUFFER_SIZE_ERROR       (EMP_FAIL - 24)//C++ 输出缓冲区大小错误
#define EMP_ERROR_IMGDATALENGTH_ERROR            (EMP_FAIL - 25)//C++ 图像数据长度出错
#define EMP_ERROR_GETIMGDATA_ERROR               (EMP_FAIL - 26)//C++ 获取图像数据出错
#define EMP_ERROR_LOADMODELERROR                 (EMP_FAIL - 27)//C++ 加载模型失败
#define EMP_ERROR_MAX_OUTPUT_SIZE_ERROR          (EMP_FAIL - 28)//C++ 最大输出数量错误
#define EMP_ERROR_NULL_MAX_OUTPUT_SIZE           (EMP_FAIL - 29)//C++ 最大输出数量指针为空
#define EMP_ERROR_CONVERT_INPUT_IMAGE_ERROR      (EMP_FAIL - 30)//C++ 输入图像转换格式失败
#define EMP_ERROR_PREDICT_LANDMARK_FAILED        (EMP_FAIL - 31)//C++ 预测人脸特征点位置失败
#define EMP_ERROR_MODELNOTEXIST                  (EMP_FAIL - 32)//C++ 指定的模型路径下不存在需要的模型文件
#define EMP_ERROR_LICENSE_TIME_OUT               (EMP_FAIL - 33)//C++ 超过授权时间
#define EMP_ERROR_NULL_INPUT_BUFFER              (EMP_FAIL - 34)//C++ 输入缓冲区为空
#define EMP_ERROR_INPUT_BUFFER_SIZE_ERROR        (EMP_FAIL - 35)//C++ 输入缓冲区长度错误
#define EMP_ERROR_INPUT_DATA_NOT_USABLE          (EMP_FAIL - 36)//C++ 输入的数据不合法
#define EMP_ERROR_PREDICT_FACE_LANDMARK_ERROR    (EMP_FAIL - 37)//C++ 人脸landmark点预测失败
#define EMP_ERROR_LICENSE_CHECK_FAILED           (EMP_FAIL - 38)//C++ 授权验证失败
#define EMP_ERROR_FEATURE_ENCODE_ERROR           (EMP_FAIL - 39)//C++ 特征编码失败
#define EMP_ERROR_FEATURE_DECODE_ERROR           (EMP_FAIL - 40)//C++ 特征解码失败
#define EMP_ERROR_NULL_INPUT_IMG                 (EMP_FAIL - 41)//C++ 输入图像为空
#define EMP_ERROR_MACHINECODEFILESIZE            (EMP_FAIL - 42)//C++ 机器码文件大小错误
#define EMP_ERROR_LICENSEFILESIZE                (EMP_FAIL - 43)//C++ 授权文件大小错误
#define EMP_ERROR_BIND_PORT_ERROR                (EMP_FAIL - 44)//C++ 绑定端口出错
#define EMP_ERROR_CREATE_UDP                     (EMP_FAIL - 45)//C++ 创建UDP通信套接字出错
#define EMP_ERROR_PROCESS_TIME_OUT               (EMP_FAIL - 46)//C++ 处理过程超时
#define EMP_ERROR_NULL_SOCKET                    (EMP_FAIL - 47)//C++ socket为空
#define EMP_ERROR_NULL_FACE_RANGE_DATA           (EMP_FAIL - 48)//C++ 人脸区域缓冲区为空
#define EMP_ERROR_UNSUPPORT_ROTATE_ANGLE         (EMP_FAIL - 49)//C++ 不支持的图像旋转角度
#define EMP_ERROR_FACE_ID_NOT_EXIST              (EMP_FAIL - 50)//C++ 指定的face id不存在
#define EMP_ERROR_CONVERT_JAVA_EMPIMG_TO_CEMPIMG (EMP_FAIL - 51)//JNI 从java中的EMPIMG转换到C中的EMPIMG失败
#define EMP_ERROR_NEW_OPERATE_FAILED             (EMP_FAIL - 52)//new operate failed
#define EMP_ERROR_IMREAD_FAILED                  (EMP_FAIL - 53)//读取图像文件失败
#define EMP_ERROR_IMDECODE_FAILED                (EMP_FAIL - 54)//解码图像失败
#define EMP_ERROR_LOCAL_GROUP_NAME_EMPTY         (EMP_FAIL - 55)//本地人像数据库名称为空
#define EMP_ERROR_EMPTY_FACE_NAME                (EMP_FAIL - 56)//人脸名称为空
#define EMP_ERROR_STORE_LOCAL_GROUP_FAILED       (EMP_FAIL - 57)//保存本地人像数据库失败
#define EMP_ERROR_DELETE_LOCAL_GROUP_FAILED      (EMP_FAIL - 58)//删除本地人像数据库失败
#define EMP_ERROR_RESTORE_LOCAL_GROUP_FAILED     (EMP_FAIL - 59)//加载本地人像数据库失败
#define EMP_ERROR_NOT_CONFIGED                   (EMP_FAIL - 60)//引擎未配置
#define EMP_ERROR_NOT_INITED                     (EMP_FAIL - 61)//引擎未初始化
#define EMP_ERROR_CREATE_TABLE_FAILED            (EMP_FAIL - 62)//在本地人脸数据库中创建数据表失败
#define EMP_ERROR_SQL_ERROR                      (EMP_FAIL - 63)//sqlite3执行sql语句失败
#define EMP_ERROR_CREATE_FACE_DB_FAILED          (EMP_FAIL - 64)//创建本地数据库失败
#define EMP_ERROR_TABLE_NOT_EXIST                (EMP_FAIL - 65)//本地数据库中不存在指定的数据库表
#define EMP_ERROR_OPEN_LOCAL_GROUP_FAILED        (EMP_FAIL - 66)//打开本地人像数据库失败
#define EMP_ERROR_ALIGN_FACE_FAILED              (EMP_FAIL - 67)//人脸对齐失败


#define EMP_MAX_PROCESS_TIME                     (30000)//单幅图像最大处理时间，单位：毫秒
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

//设置错误码
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

