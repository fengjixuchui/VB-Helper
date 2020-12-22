#pragma once
#include <pro.h>

struct mid_ProjectInfo2
{
	uint32 Todo;
};


struct mid_ControlInfo
{
	qstring m_ControlName;			//�ؼ�������
	qstring m_ControlEventGuid;		//�ؼ���Ӧ�¼���GUID
	qvector<uint32> mVec_UseEvent;	//�ؼ������¼��ĵ�ַ
};

enum midEnum_EventType
{
	e_NoneEvent,
	e_UserEvent,
	e_PutMemEvent,
	e_GetMemEvent,
	e_SetMemEvent,
	e_PutMemStr,
	e_GetMemStr,
	e_GetMem2,
	e_PutMem2,
	e_PutMem4,
	e_GetMem4,
	e_PutMemObj,
	e_GetMemObj,
	e_SetMemObj,
	e_GetMemNewObj,
	e_PutMemNewObj,
	e_SetMemNewObj
};

struct mid_VTable
{
	midEnum_EventType m_EventType;
	uint32 m_Offset;
	uint32 m_MethodAddr;
};

struct mid_OptionalObjectInfo
{
	bool bHasControl;		//��Object�Ƿ�����ؼ�
	qvector<mid_ControlInfo> mVec_ControlInfo;

	qvector<mid_VTable> mVec_MethodLink;
};


struct mid_ObjectMess
{
	qstring m_ObjectName;	//���������
	qstring m_ObjectTypeName;
	uint32 m_ObjectType;
	qlist<qstring> mVec_MethodName;

	uint16 m_ClassSize;		//�������ռ��С
	qstring m_ObjectIID;	//���ú���ʱ���GUID

	uint16 m_iPCodeCount;	//�����opcode��������

	bool bHasClasses;		//��Object�Ƿ������

	bool bHasOptionalObj;
	mid_OptionalObjectInfo m_OptionObjInfo;
};


struct mid_WindowsApi
{
	qstring LibraryName;
	qstring FunctionName;
};

struct mid_ComApi
{
	qstring uuid_coclass;
	uint32 GlobalVarAddr;
};

struct mid_ApiInfo
{
	qvector<mid_WindowsApi> mVec_WinApi;
	qvector<mid_ComApi> mVec_ComApi;
};

struct mid_ProjectInfo
{
	qstring ProjectName;			//��������
	qstring ProjectDescription;		//��������

	mid_ProjectInfo2 m_ProjectInfo2;
	uint32 lpCodeStart;				//VB�û�������ʼ��ַ
	uint32 lpCodeEnd;				//VB�û����������ַ
	qvector<uint32> mVec_FuncTable;	//���еĺ����б�
	mid_ApiInfo m_ApiInfo;			//���������Api
};

struct mid_GUITable
{
	uint32 ToDo;
};

struct mid_ExternalControl
{
	qstring LibName;
	qstring IDEName;
	qstring ControlName;
};

struct mid_COMRegData
{
	qstring RegComName;
	qstring RegComUUID;
};

struct mid_VBHeader
{
	uint32 m_lpSubMain;									//Main�������

	mid_ProjectInfo m_ProjectInfo;						//���̶�����Ϣ
	qvector<mid_ObjectMess> mVec_ObjectTable;			//������Ϣ
	qvector<mid_GUITable> mVec_GuiTable;				//���������Ϣ
	qvector<mid_ExternalControl> mVec_ExternalControl;	//����COM�ؼ���Ϣ
	qvector<mid_COMRegData> mVec_ComRegData;			//ע��COM�����Ϣ
};