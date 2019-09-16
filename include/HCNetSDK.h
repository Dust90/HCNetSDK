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

#define SERIALNO_LEN            48      //���кų���
#define NET_DVR_DEV_ADDRESS_MAX_LEN 129
#define NET_DVR_LOGIN_USERNAME_MAX_LEN 64
#define NET_DVR_LOGIN_PASSWD_MAX_LEN 64


#define LIGHT_PWRON        2    /* ��ͨ�ƹ��Դ */
#define WIPER_PWRON        3    /* ��ͨ��ˢ���� */
#define FAN_PWRON        4    /* ��ͨ���ȿ��� */
#define HEATER_PWRON    5    /* ��ͨ���������� */
#define AUX_PWRON1        6    /* ��ͨ�����豸���� */
#define AUX_PWRON2        7    /* ��ͨ�����豸���� */
#define SET_PRESET        8    /* ����Ԥ�õ� */
#define CLE_PRESET        9    /* ���Ԥ�õ� */

#define ZOOM_IN            11    /* �������ٶ�SS���(���ʱ��) */
#define ZOOM_OUT        12    /* �������ٶ�SS��С(���ʱ�С) */
#define FOCUS_NEAR      13  /* �������ٶ�SSǰ�� */
#define FOCUS_FAR       14  /* �������ٶ�SS��� */
#define IRIS_OPEN       15  /* ��Ȧ���ٶ�SS���� */
#define IRIS_CLOSE      16  /* ��Ȧ���ٶ�SS��С */

#define TILT_UP            21    /* ��̨��SS���ٶ����� */
#define TILT_DOWN        22    /* ��̨��SS���ٶ��¸� */
#define PAN_LEFT        23    /* ��̨��SS���ٶ���ת */
#define PAN_RIGHT        24    /* ��̨��SS���ٶ���ת */
#define UP_LEFT            25    /* ��̨��SS���ٶ���������ת */
#define UP_RIGHT        26    /* ��̨��SS���ٶ���������ת */
#define DOWN_LEFT        27    /* ��̨��SS���ٶ��¸�����ת */
#define DOWN_RIGHT        28    /* ��̨��SS���ٶ��¸�����ת */
#define PAN_AUTO        29    /* ��̨��SS���ٶ������Զ�ɨ�� */

#define FILL_PRE_SEQ    30    /* ��Ԥ�õ����Ѳ������ */
#define SET_SEQ_DWELL    31    /* ����Ѳ����ͣ��ʱ�� */
#define SET_SEQ_SPEED    32    /* ����Ѳ���ٶ� */
#define CLE_PRE_SEQ        33    /* ��Ԥ�õ��Ѳ��������ɾ�� */
#define STA_MEM_CRUISE    34    /* ��ʼ��¼�켣 */
#define STO_MEM_CRUISE    35    /* ֹͣ��¼�켣 */
#define RUN_CRUISE        36    /* ��ʼ�켣 */
#define RUN_SEQ            37    /* ��ʼѲ�� */
#define STOP_SEQ        38    /* ֹͣѲ�� */
#define GOTO_PRESET        39    /* ����ת��Ԥ�õ� */

#define DEL_SEQ         43  /* ɾ��Ѳ��·�� */
#define STOP_CRUISE        44    /* ֹͣ�켣 */
#define DELETE_CRUISE    45    /* ɾ�������켣 */
#define DELETE_ALL_CRUISE 46/* ɾ�����й켣 */

#define PAN_CIRCLE      50   /* ��̨��SS���ٶ��Զ�Բ��ɨ�� */
#define DRAG_PTZ        51   /* �϶�PTZ */
#define LINEAR_SCAN     52   /* ����ɨ�� */ //2014-03-15
#define CLE_ALL_PRESET  53   /* Ԥ�õ�ȫ����� */
#define CLE_ALL_SEQ     54   /* Ѳ��ȫ����� */
#define CLE_ALL_CRUISE  55   /* �켣ȫ����� */

#define POPUP_MENU      56   /* ��ʾ�����˵� */

#define TILT_DOWN_ZOOM_IN    58    /* ��̨��SS���ٶ��¸�&&�������ٶ�SS���(���ʱ��) */
#define TILT_DOWN_ZOOM_OUT  59  /* ��̨��SS���ٶ��¸�&&�������ٶ�SS��С(���ʱ�С) */
#define PAN_LEFT_ZOOM_IN    60  /* ��̨��SS���ٶ���ת&&�������ٶ�SS���(���ʱ��)*/
#define PAN_LEFT_ZOOM_OUT   61  /* ��̨��SS���ٶ���ת&&�������ٶ�SS��С(���ʱ�С)*/
#define PAN_RIGHT_ZOOM_IN    62  /* ��̨��SS���ٶ���ת&&�������ٶ�SS���(���ʱ��) */
#define PAN_RIGHT_ZOOM_OUT  63  /* ��̨��SS���ٶ���ת&&�������ٶ�SS��С(���ʱ�С) */
#define UP_LEFT_ZOOM_IN     64  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS���(���ʱ��)*/
#define UP_LEFT_ZOOM_OUT    65  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS��С(���ʱ�С)*/
#define UP_RIGHT_ZOOM_IN    66  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS���(���ʱ��)*/
#define UP_RIGHT_ZOOM_OUT   67  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS��С(���ʱ�С)*/
#define DOWN_LEFT_ZOOM_IN   68  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS���(���ʱ��) */
#define DOWN_LEFT_ZOOM_OUT  69  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS��С(���ʱ�С) */
#define DOWN_RIGHT_ZOOM_IN    70  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS���(���ʱ��) */
#define DOWN_RIGHT_ZOOM_OUT    71  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS��С(���ʱ�С) */
#define TILT_UP_ZOOM_IN        72    /* ��̨��SS���ٶ�����&&�������ٶ�SS���(���ʱ��) */
#define TILT_UP_ZOOM_OUT    73


//NET_DVR_Login_V30()�����ṹ
typedef struct tagNET_DVR_DEVICEINFO_V30
{
    BYTE sSerialNumber[SERIALNO_LEN];  //���к�
    BYTE byAlarmInPortNum;                //�����������
    BYTE byAlarmOutPortNum;                //�����������
    BYTE byDiskNum;                    //Ӳ�̸���
    BYTE byDVRType;                    //�豸����, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;                    //ģ��ͨ������
    BYTE byStartChan;                    //��ʼͨ����,����DVS-1,DVR - 1
    BYTE byAudioChanNum;                //����ͨ����
    BYTE byIPChanNum;                    //�������ͨ����������λ
    BYTE byZeroChanNum;            //��ͨ��������� //2010-01-16
    BYTE byMainProto;            //����������Э������ 0-private, 1-rtsp,2-ͬʱ֧��private��rtsp
    BYTE bySubProto;                //����������Э������0-private, 1-rtsp,2-ͬʱ֧��private��rtsp
    BYTE bySupport;
    BYTE bySupport1;
    BYTE bySupport2;
    WORD wDevType;
    BYTE bySupport3;
    BYTE byMultiStreamProto;//�Ƿ�֧�ֶ�����,��λ��ʾ,0-��֧��,1-֧��,bit1-����3,bit2-����4,bit7-��������bit-8������
    BYTE byStartDChan;        //��ʼ����ͨ����,0��ʾ��Ч
    BYTE byStartDTalkChan;    //��ʼ���ֶԽ�ͨ���ţ�������ģ��Խ�ͨ���ţ�0��ʾ��Ч
    BYTE byHighDChanNum;        //����ͨ����������λ
    BYTE bySupport4;
    BYTE byLanguageType;
    BYTE byVoiceInChanNum;   //��Ƶ����ͨ����
    BYTE byStartVoiceInChanNo; //��Ƶ������ʼͨ���� 0��ʾ��Ч
    BYTE  bySupport5;
    BYTE  bySupport6;
    BYTE  byMirrorChanNum;    //����ͨ��������<¼�����������ڱ�ʾ����ͨ��>
    WORD wStartMirrorChanNo;  //��ʼ����ͨ����
    BYTE bySupport7;
    BYTE  byRes2;        //����
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

typedef struct tagNET_DVR_DEVICEINFO_V40
{
    NET_DVR_DEVICEINFO_V30 struDeviceV30;
    BYTE  bySupportLock;        //�豸֧���������ܣ����ֶ���SDK�����豸����ֵ����ֵ�ġ�bySupportLockΪ1ʱ��dwSurplusLockTime��byRetryLoginTime��Ч
    BYTE  byRetryLoginTime;        //ʣ��ɳ��Ե�½�Ĵ������û������������ʱ���˲�����Ч
    BYTE  byPasswordLevel;      //admin���밲ȫ�ȼ�0-��Ч��1-Ĭ�����룬2-��Ч����,3-���սϸߵ����롣���û�������Ϊ����Ĭ�����루12345�����߷��սϸߵ�����ʱ���ϲ�ͻ�����Ҫ��ʾ�û��������롣
    BYTE  byProxyType;  //�������ͣ�0-��ʹ�ô���, 1-ʹ��socks5����, 2-ʹ��EHome����
    DWORD dwSurplusLockTime;    //ʣ��ʱ�䣬��λ�룬�û�����ʱ���˲�����Ч
    BYTE  byCharEncodeType;     //�ַ���������
    BYTE  bySupportDev5;//֧��v50�汾���豸������ȡ���豸���ƺ��豸�������Ƴ�����չΪ64�ֽ�
    BYTE  bySupport;  //��������չ��λ������0- ��֧�֣�1- ֧��
    BYTE  byLoginMode; //��¼ģʽ 0-Private��¼ 1-ISAPI��¼
    DWORD dwOEMCode;
    int iResidualValidity;   //���û�����ʣ����Ч��������λ���죬���ظ�ֵ����ʾ�����Ѿ�����ʹ�ã����硰-3��ʾ�����Ѿ�����ʹ��3�족
    BYTE  byResidualValidity; // iResidualValidity�ֶ��Ƿ���Ч��0-��Ч��1-��Ч
    BYTE  byRes2[243];
}NET_DVR_DEVICEINFO_V40, *LPNET_DVR_DEVICEINFO_V40;

typedef void (*fLoginResultCallBack) (LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo , void* pUser);
typedef void (*REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

typedef struct tagNET_DVR_USER_LOGIN_INFO
{
    char sDeviceAddress[NET_DVR_DEV_ADDRESS_MAX_LEN];
    BYTE byUseTransport;    //�Ƿ�����������͸����0--������͸����Ĭ�ϣ�1--����͸��
    WORD wPort;
    char sUserName[NET_DVR_LOGIN_USERNAME_MAX_LEN];
    char sPassword[NET_DVR_LOGIN_PASSWD_MAX_LEN];
    fLoginResultCallBack cbLoginResult;
    void *pUser;
    BOOL bUseAsynLogin;
    BYTE byProxyType; //0:��ʹ�ô���1��ʹ�ñ�׼����2��ʹ��EHome����
    BYTE byUseUTCTime;    //0-������ת����Ĭ��,1-�ӿ����������ȫ��ʹ��UTCʱ��,SDK���UTCʱ�����豸ʱ����ת��,2-�ӿ����������ȫ��ʹ��ƽ̨����ʱ�䣬SDK���ƽ̨����ʱ�����豸ʱ����ת��
    BYTE byLoginMode; //0-Private 1-ISAPI 2-����Ӧ
    BYTE byHttps;    //0-������tls��1-ʹ��tls 2-����Ӧ
    LONG iProxyID;    //�����������ţ���Ӵ����������Ϣʱ�����Ӧ�ķ����������±�ֵ
    BYTE byVerifyMode;  //��֤��ʽ��0-����֤��1-˫����֤��2-������֤����֤����ʹ��TLS��ʱ����Ч;
    BYTE byRes3[119];
}NET_DVR_USER_LOGIN_INFO,*LPNET_DVR_USER_LOGIN_INFO;

//ͼƬ����
typedef struct tagNET_DVR_JPEGPARA
{
    WORD    wPicSize;
    WORD    wPicQuality;            /* ͼƬ����ϵ�� 0-��� 1-�Ϻ� 2-һ�� */
}NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

//�����Ԥ������
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

//Ԥ��V40�ӿ�
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