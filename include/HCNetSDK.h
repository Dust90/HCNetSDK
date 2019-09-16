#ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_

#ifndef _WINDOWS_
    #if (defined(_WIN32) || defined(_WIN64))
        #include <winsock2.h>
        #include <windows.h>
    #endif
#endif

#ifndef __PLAYRECT_defined
    #define __PLAYRECT_defined
    typedef struct __PLAYRECT
    {
        int x;
        int y;
        int uWidth;
        int uHeight;
    }PLAYRECT;
#endif

#if (defined(_WIN32)) //windows
    typedef  unsigned __int64   UINT64;
    typedef  signed   __int64   INT64;
#elif defined(__linux__) || defined(__APPLE__) //linux
    #define  BOOL  int
      #include <stdint.h>
      typedef uint32_t    DWORD;
      typedef uint16_t    WORD;
      typedef uint16_t    SHORT;
      typedef uint16_t    USHORT;
      typedef int32_t     LONG;
      typedef uint8_t     BYTE;
      typedef uint32_t    UINT;
      typedef void*       LPVOID;
      typedef void*       HANDLE;
      typedef uint32_t *  LPDWORD;
      typedef uint64_t    UINT64;

    #ifndef TRUE
        #define TRUE  1
    #endif
    #ifndef FALSE
        #define FALSE 0
    #endif
    #ifndef NULL
        #define NULL 0
    #endif

    #define __stdcall
    #define CALLBACK

    #define NET_DVR_API extern "C"
    typedef unsigned int   COLORKEY;
    typedef unsigned int   COLORREF;

    #ifndef __HWND_defined
        #define __HWND_defined
        #if defined(__linux__)
            typedef unsigned int HWND;
        #else
            typedef void* HWND;
        #endif
    #endif

    #ifndef __HDC_defined
        #define __HDC_defined
        #if defined(__linux__)
            typedef struct __DC
            {
                void*   surface;        //SDL Surface
                HWND    hWnd;           //HDC window handle
            }DC;
            typedef DC* HDC;
        #else
            typedef void* HDC;
        #endif
    #endif

    typedef struct tagInitInfo
    {
        int uWidth;
        int uHeight;
    }INITINFO;
#endif

#define SERIALNO_LEN            48      //序列号长度
#define NET_DVR_DEV_ADDRESS_MAX_LEN 129
#define NET_DVR_LOGIN_USERNAME_MAX_LEN 64
#define NET_DVR_LOGIN_PASSWD_MAX_LEN 64


#define LIGHT_PWRON        2    /* 接通灯光电源 */
#define WIPER_PWRON        3    /* 接通雨刷开关 */
#define FAN_PWRON        4    /* 接通风扇开关 */
#define HEATER_PWRON    5    /* 接通加热器开关 */
#define AUX_PWRON1        6    /* 接通辅助设备开关 */
#define AUX_PWRON2        7    /* 接通辅助设备开关 */
#define SET_PRESET        8    /* 设置预置点 */
#define CLE_PRESET        9    /* 清除预置点 */

#define ZOOM_IN            11    /* 焦距以速度SS变大(倍率变大) */
#define ZOOM_OUT        12    /* 焦距以速度SS变小(倍率变小) */
#define FOCUS_NEAR      13  /* 焦点以速度SS前调 */
#define FOCUS_FAR       14  /* 焦点以速度SS后调 */
#define IRIS_OPEN       15  /* 光圈以速度SS扩大 */
#define IRIS_CLOSE      16  /* 光圈以速度SS缩小 */

#define TILT_UP            21    /* 云台以SS的速度上仰 */
#define TILT_DOWN        22    /* 云台以SS的速度下俯 */
#define PAN_LEFT        23    /* 云台以SS的速度左转 */
#define PAN_RIGHT        24    /* 云台以SS的速度右转 */
#define UP_LEFT            25    /* 云台以SS的速度上仰和左转 */
#define UP_RIGHT        26    /* 云台以SS的速度上仰和右转 */
#define DOWN_LEFT        27    /* 云台以SS的速度下俯和左转 */
#define DOWN_RIGHT        28    /* 云台以SS的速度下俯和右转 */
#define PAN_AUTO        29    /* 云台以SS的速度左右自动扫描 */

#define FILL_PRE_SEQ    30    /* 将预置点加入巡航序列 */
#define SET_SEQ_DWELL    31    /* 设置巡航点停顿时间 */
#define SET_SEQ_SPEED    32    /* 设置巡航速度 */
#define CLE_PRE_SEQ        33    /* 将预置点从巡航序列中删除 */
#define STA_MEM_CRUISE    34    /* 开始记录轨迹 */
#define STO_MEM_CRUISE    35    /* 停止记录轨迹 */
#define RUN_CRUISE        36    /* 开始轨迹 */
#define RUN_SEQ            37    /* 开始巡航 */
#define STOP_SEQ        38    /* 停止巡航 */
#define GOTO_PRESET        39    /* 快球转到预置点 */

#define DEL_SEQ         43  /* 删除巡航路径 */
#define STOP_CRUISE        44    /* 停止轨迹 */
#define DELETE_CRUISE    45    /* 删除单条轨迹 */
#define DELETE_ALL_CRUISE 46/* 删除所有轨迹 */

#define PAN_CIRCLE      50   /* 云台以SS的速度自动圆周扫描 */
#define DRAG_PTZ        51   /* 拖动PTZ */
#define LINEAR_SCAN     52   /* 区域扫描 */ //2014-03-15
#define CLE_ALL_PRESET  53   /* 预置点全部清除 */
#define CLE_ALL_SEQ     54   /* 巡航全部清除 */
#define CLE_ALL_CRUISE  55   /* 轨迹全部清除 */

#define POPUP_MENU      56   /* 显示操作菜单 */

#define TILT_DOWN_ZOOM_IN    58    /* 云台以SS的速度下俯&&焦距以速度SS变大(倍率变大) */
#define TILT_DOWN_ZOOM_OUT  59  /* 云台以SS的速度下俯&&焦距以速度SS变小(倍率变小) */
#define PAN_LEFT_ZOOM_IN    60  /* 云台以SS的速度左转&&焦距以速度SS变大(倍率变大)*/
#define PAN_LEFT_ZOOM_OUT   61  /* 云台以SS的速度左转&&焦距以速度SS变小(倍率变小)*/
#define PAN_RIGHT_ZOOM_IN    62  /* 云台以SS的速度右转&&焦距以速度SS变大(倍率变大) */
#define PAN_RIGHT_ZOOM_OUT  63  /* 云台以SS的速度右转&&焦距以速度SS变小(倍率变小) */
#define UP_LEFT_ZOOM_IN     64  /* 云台以SS的速度上仰和左转&&焦距以速度SS变大(倍率变大)*/
#define UP_LEFT_ZOOM_OUT    65  /* 云台以SS的速度上仰和左转&&焦距以速度SS变小(倍率变小)*/
#define UP_RIGHT_ZOOM_IN    66  /* 云台以SS的速度上仰和右转&&焦距以速度SS变大(倍率变大)*/
#define UP_RIGHT_ZOOM_OUT   67  /* 云台以SS的速度上仰和右转&&焦距以速度SS变小(倍率变小)*/
#define DOWN_LEFT_ZOOM_IN   68  /* 云台以SS的速度下俯和左转&&焦距以速度SS变大(倍率变大) */
#define DOWN_LEFT_ZOOM_OUT  69  /* 云台以SS的速度下俯和左转&&焦距以速度SS变小(倍率变小) */
#define DOWN_RIGHT_ZOOM_IN    70  /* 云台以SS的速度下俯和右转&&焦距以速度SS变大(倍率变大) */
#define DOWN_RIGHT_ZOOM_OUT    71  /* 云台以SS的速度下俯和右转&&焦距以速度SS变小(倍率变小) */
#define TILT_UP_ZOOM_IN        72    /* 云台以SS的速度上仰&&焦距以速度SS变大(倍率变大) */
#define TILT_UP_ZOOM_OUT    73


//NET_DVR_Login_V30()参数结构
typedef struct tagNET_DVR_DEVICEINFO_V30
{
    BYTE sSerialNumber[SERIALNO_LEN];  //序列号
    BYTE byAlarmInPortNum;                //报警输入个数
    BYTE byAlarmOutPortNum;                //报警输出个数
    BYTE byDiskNum;                    //硬盘个数
    BYTE byDVRType;                    //设备类型, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;                    //模拟通道个数
    BYTE byStartChan;                    //起始通道号,例如DVS-1,DVR - 1
    BYTE byAudioChanNum;                //语音通道数
    BYTE byIPChanNum;                    //最大数字通道个数，低位
    BYTE byZeroChanNum;            //零通道编码个数 //2010-01-16
    BYTE byMainProto;            //主码流传输协议类型 0-private, 1-rtsp,2-同时支持private和rtsp
    BYTE bySubProto;                //子码流传输协议类型0-private, 1-rtsp,2-同时支持private和rtsp
    BYTE bySupport;
    BYTE bySupport1;
    BYTE bySupport2;
    WORD wDevType;
    BYTE bySupport3;
    BYTE byMultiStreamProto;//是否支持多码流,按位表示,0-不支持,1-支持,bit1-码流3,bit2-码流4,bit7-主码流，bit-8子码流
    BYTE byStartDChan;        //起始数字通道号,0表示无效
    BYTE byStartDTalkChan;    //起始数字对讲通道号，区别于模拟对讲通道号，0表示无效
    BYTE byHighDChanNum;        //数字通道个数，高位
    BYTE bySupport4;
    BYTE byLanguageType;
    BYTE byVoiceInChanNum;   //音频输入通道数
    BYTE byStartVoiceInChanNo; //音频输入起始通道号 0表示无效
    BYTE  bySupport5;
    BYTE  bySupport6;
    BYTE  byMirrorChanNum;    //镜像通道个数，<录播主机中用于表示导播通道>
    WORD wStartMirrorChanNo;  //起始镜像通道号
    BYTE bySupport7;
    BYTE  byRes2;        //保留
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

typedef struct tagNET_DVR_DEVICEINFO_V40
{
    NET_DVR_DEVICEINFO_V30 struDeviceV30;
    BYTE  bySupportLock;        //设备支持锁定功能，该字段由SDK根据设备返回值来赋值的。bySupportLock为1时，dwSurplusLockTime和byRetryLoginTime有效
    BYTE  byRetryLoginTime;        //剩余可尝试登陆的次数，用户名，密码错误时，此参数有效
    BYTE  byPasswordLevel;      //admin密码安全等级0-无效，1-默认密码，2-有效密码,3-风险较高的密码。当用户的密码为出厂默认密码（12345）或者风险较高的密码时，上层客户端需要提示用户更改密码。
    BYTE  byProxyType;  //代理类型，0-不使用代理, 1-使用socks5代理, 2-使用EHome代理
    DWORD dwSurplusLockTime;    //剩余时间，单位秒，用户锁定时，此参数有效
    BYTE  byCharEncodeType;     //字符编码类型
    BYTE  bySupportDev5;//支持v50版本的设备参数获取，设备名称和设备类型名称长度扩展为64字节
    BYTE  bySupport;  //能力集扩展，位与结果：0- 不支持，1- 支持
    BYTE  byLoginMode; //登录模式 0-Private登录 1-ISAPI登录
    DWORD dwOEMCode;
    int iResidualValidity;   //该用户密码剩余有效天数，单位：天，返回负值，表示密码已经超期使用，例如“-3表示密码已经超期使用3天”
    BYTE  byResidualValidity; // iResidualValidity字段是否有效，0-无效，1-有效
    BYTE  byRes2[243];
}NET_DVR_DEVICEINFO_V40, *LPNET_DVR_DEVICEINFO_V40;

typedef void (*fLoginResultCallBack) (LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo , void* pUser);
typedef void (*REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

typedef struct tagNET_DVR_USER_LOGIN_INFO
{
    char sDeviceAddress[NET_DVR_DEV_ADDRESS_MAX_LEN];
    BYTE byUseTransport;    //是否启用能力集透传，0--不启用透传，默认，1--启用透传
    WORD wPort;
    char sUserName[NET_DVR_LOGIN_USERNAME_MAX_LEN];
    char sPassword[NET_DVR_LOGIN_PASSWD_MAX_LEN];
    fLoginResultCallBack cbLoginResult;
    void *pUser;
    BOOL bUseAsynLogin;
    BYTE byProxyType; //0:不使用代理，1：使用标准代理，2：使用EHome代理
    BYTE byUseUTCTime;    //0-不进行转换，默认,1-接口上输入输出全部使用UTC时间,SDK完成UTC时间与设备时区的转换,2-接口上输入输出全部使用平台本地时间，SDK完成平台本地时间与设备时区的转换
    BYTE byLoginMode; //0-Private 1-ISAPI 2-自适应
    BYTE byHttps;    //0-不适用tls，1-使用tls 2-自适应
    LONG iProxyID;    //代理服务器序号，添加代理服务器信息时，相对应的服务器数组下表值
    BYTE byVerifyMode;  //认证方式，0-不认证，1-双向认证，2-单向认证；认证仅在使用TLS的时候生效;
    BYTE byRes3[119];
}NET_DVR_USER_LOGIN_INFO,*LPNET_DVR_USER_LOGIN_INFO;

//图片质量
typedef struct tagNET_DVR_JPEGPARA
{
    WORD    wPicSize;
    WORD    wPicQuality;            /* 图片质量系数 0-最好 1-较好 2-一般 */
}NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

//软解码预览参数
typedef struct tagNET_DVR_CLIENTINFO
{
    LONG lChannel;
    LONG lLinkMode;
    HWND hPlayWnd;
    char* sMultiCastIP;
    BYTE byProtoType;
    BYTE byRes[3];
}NET_DVR_CLIENTINFO, *LPNET_DVR_CLIENTINFO;

#define STREAM_ID_LEN   32

//预览V40接口
typedef struct tagNET_DVR_PREVIEWINFO
{
    LONG lChannel;
    DWORD dwStreamType;
    DWORD dwLinkMode;
    HWND hPlayWnd;
    DWORD bBlocked;
    DWORD bPassbackRecord;
    BYTE byPreviewMode;
    BYTE byStreamID[STREAM_ID_LEN];
    BYTE byProtoType;
    BYTE byRes1;
    BYTE byVideoCodingType;
    DWORD dwDisplayBufNum;
    BYTE byNPQMode;
    BYTE byRes[215];
}NET_DVR_PREVIEWINFO, *LPNET_DVR_PREVIEWINFO;



BOOL NET_DVR_Init();
BOOL NET_DVR_Cleanup();

LONG NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
LONG NET_DVR_Login_V40(LPNET_DVR_USER_LOGIN_INFO pLoginInfo,LPNET_DVR_DEVICEINFO_V40 lpDeviceInfo);
BOOL NET_DVR_Logout(LONG lUserID);
BOOL NET_DVR_Logout_V30(LONG lUserID);

BOOL NET_DVR_SetConnectTime(DWORD dwWaitTime, DWORD dwTryTimes);
BOOL NET_DVR_SetReconnect(DWORD dwInterval, BOOL bEnableRecon);

BOOL NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);
LONG NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(*fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser), void* pUser, BOOL bBlocked);
BOOL NET_DVR_ClosePreview(LONG lUserID, DWORD nSessionID);
BOOL NET_DVR_ClosePlayBack(LONG lUserID, DWORD nSessionID);
LONG NET_DVR_RealPlay_V40(LONG lUserID, LPNET_DVR_PREVIEWINFO lpPreviewInfo, REALDATACALLBACK fRealDataCallBack_V30, void* pUser);

BOOL NET_DVR_SaveRealData(LONG lRealHandle,char *sFileName);
BOOL NET_DVR_StopSaveRealData(LONG lRealHandle);

BOOL NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
BOOL NET_DVR_StopRealPlay(LONG lRealHandle);

DWORD NET_DVR_GetLastError();

#endif