#pragma once
#include <ida.hpp>
#include <bytes.hpp>
#include <kernwin.hpp>
#include <vector>
#include "public.h"

#include "middleVB.h"

//������������������������������������������������������������������������������������
#pragma pack(push,1)

//�ṹ���СΪ0x18
struct DefaultEvent
{
	uint32 dwNull;				//Ϊ0,δ֪
	uint32 EventInfo;			//�¼�����������Ϣ
	uint32 lpObjectInfo;		//ָ��ǰ����ı���ָ��
	uint32 QueryInterface;		//QueryInterface
	uint32 AddRef;				//AddRef
	uint32 Release;				//Release
};

//�ṹ���СΪ0x28
struct ControlInfo
{
	uint16 szNone;				//δ֪
	uint16 UserEventCount;		//�û��¼�����
	uint16 EventSupcount;		//֧�ֵ��¼�����ĸ���
	uint16 bWEventsOffset;		//���������¼����ڴ�ṹ���ƫ��
	uint32 lpGuid;				//ָ��ؼ�GUID��ָ��
	uint32 dwIndex;				//��ǰ�ؼ�������ID
	uint32 dwNull1;				//����
	uint32 dwNull2;				//����
	uint32 aEventTable;			//ִ���¼�������ָ��
	uint32 lpIdeData;			//����
	uint32 lpszName;			//�ؼ�������
	uint32 dwIndexCopy;			//��ǰ�ؼ��ĵڶ�����ID
};

//�ṹ���С����Ϊ0x18
struct EventTable
{
	uint32 dwNull;				//Ϊ0
	uint32 aControl;			//ָ��ؼ���Ϣ...
	uint32 aObjectInfo;			//ָ�������Ϣ
	uint32 aQueryInterface;		//QueryInterface����
	uint32 aAddRef;				//AddRef����
	uint32 aRelease;			//Release����
	//uint32 aEventPointer;		//�¼�,ʵ�ʴ�СΪaEventPointer[aControl.EventCount - 1]
};

//�ṹ���СΪ0x34
struct ParentObjInfo
{
	uint16 flag;				//��־ֵ
	uint16 offset;				//ĳ��λ��
	//To do...
};

//�ṹ���СΪ0x40
struct PrivateObjectInfo
{
	uint32 lpHeapLink;			//ֵΪ0,����
	uint32 lpObjectInfo;		//ָ��ǰ˽�ж���Ķ���ָ��,ObjectInfo*
	uint32 dwReserved;			//ֵΪ-1,����
	uint32 szNone1;				//δ֪
	uint16 wClassCount;			//���������
	uint16 oSize;				//ĳ����Ҫֵ
	uint32 szNone3;				//δ֪
	uint32 lpObjectList;		//****************,ָ��ParentObjInfo����,��Ա��С��ObjectDescription.MethodCount��ͬ
	uint32 IDEData2;			//����
	uint32 ClassVarList;		//ָ��������ڴ�ռ�
	uint32 szNone4;				//δ֪
	uint32 szNone5;				//δ֪
	uint32 IDEData3[3];			//����
	uint32 dwObjectType;		//���������������
	uint32 dwIdentifier;		//�ṹ���ģ��汾
};

//�ṹ���СΪ0x38
struct ObjectInfo
{
	uint16 wRefCount;			//ֵΪ1,δ֪
	uint16 ObjectIndex;			//��ǰ�����ڹ��̶��������е��±�
	uint32 ObjectTable;			//ָ��ObjectTable�ı���ָ��
	uint32 lpIDEData1;			//ֵΪ0,����
	uint32 lpPrivateObject;		//****************ָ��˽�ж����ָ��,PrivateObjectInfo*
	uint32 dwReserved;			//ֵΪ-1,����
	uint32 dwNull;				//ֵΪ0,����
	uint32 lpObject;			//ָ�����������Ϣ�ı���ָ��,ObjectDescription*
	uint32 lpProjectData;		//ָ���ڴ��е�����
	uint16 szNone1;				//δ֪
	uint16 szNone2;				//Ϊ0,δ֪
	uint32 szNone3;				//δ֪��
	uint16 wConstants;			//�ڳ������еĳ�������
	uint16 wMaxConstants;		//����ĳ�������
	uint32 lpIDEData2;			//����
	uint32 lpIDEData3;			//����
	uint32 lpOptionObject;		//������ڶ�����Ϣ,��ó�Ա��һ��������OptionalObjectInfo
};

//�ṹ���СΪ0x40
struct OptionalObjectInfo
{
	uint32 lguidObjectGUICount;		//guid�ĸ���
	uint32 aObjectCLSID;			//ָ��CLSID��ָ��
	uint32 dwNull;					//δ֪
	uint32 aguidObjectGUITable;		//ָ��guidObjectGUI��ָ���ָ��
	uint32 lObjectDefaultIIDCount;	//DefaultIID�ĸ���
	uint32 aObjectEventsIIDTable;	//ָ��EventsIID��ָ���ָ��
	uint32 lObjectEventsIIDCount;	//EventsIID�ĸ���
	uint32 aObjectDefaultIIDTable;	//ָ��DefaultIID��ָ���ָ��
	uint32 lControlCount;			//�ؼ�����
	uint32 aControlArray;			//ָ��ؼ������ָ��
	int16 iMethodLinkCount;			//���ӵĺ�������
	uint16 iPCodeCount;				//ʹ�õ�Opcodes����
	uint16 oInitializeEvent;		//MethodLinkTable�г�ʼ���¼���ƫ��
	uint16 oTerminateEvent;			//MethodLinkTable���ս��¼���ƫ��
	uint32 MethodLinkTable;			//ָ�������ӵ�ָ���ָ��
	uint32 aBasicClassObject;		//ָ��һ���ڴ�ṹ
	uint32 szNone;					//����
	uint32 lFlag;					//δ֪
};

//�ṹ���СΪ0x30
struct ObjectDescription
{
	uint32 ObjectInfo;		//ָ��ObjectInfo��ָ��,ObjectInfo*
	uint32 dwReserved;		//ֵΪ-1,δ֪
	uint32 PublicBytes;		//ָ��Public������С������ָ��
	uint32 StaticBytes;		//ָ��Static������С������ָ��
	uint32 ModulePublic;	//ָ��Public���������ڴ�
	uint32 ModuleStatic;	//ָ��Static���������ڴ�
	uint32 NTSObjectName;	//****************���������
	int32 MethodCount;		//****************�������еĺ�������
	int32 MethodNameTable;	//****************���к���������ָ��
	uint32 StaticVars;		//ModuleStatic�о�̬������ƫ��
	uint32 ObjectType;		//****************���������bitmask
	uint32 dwNull;			//����
};


//�ṹ���СΪ0x54
struct ObjectTable
{
	uint32 lpHeapLink;			//��ԶΪ0
	uint32 lpExecProj;			//VB Exec COM������ڴ�ָ��
	uint32 lpProjectInfo2;		//�ڶ����̶�����Ϣ,ProjectInfo2*
	uint32 dwReserved;			//��ԶΪ-1
	uint32 dwNull;				//δ��ʹ��
	uint32 lpProjectObject;		//���ڴ��еĹ�������ָ��
	uint8  uuidObject[0x10];	//������GUID
	uint16 fCompileState;		//����ʱ����ڲ����
	uint16 dwTotalObjects;		//****************�����д��ڵĶ�������
	uint16 dwCompiledObjects;	//����������,���������ͬ
	uint16 dwObjectsInUse;		//ʹ�ö������,ͨ�����������ͬ
	uint32 lpObjectArray;		//****************ָ�����������Ϣ�����ָ��,ObjectDescription*
	uint32 fIdeFlag;			//����
	uint32 lpIdeData;			//����
	uint32 lpIdeData2;			//����
	uint32 lpszProjectName;		//�������Ƶ�ָ��
	uint32 dwLcid;				//���̵�LocaleID 
	uint32 dwLcid2;				//���̵�Second LocalID
	uint32 lpIdeData3;			//����
	uint32 dwIdentifier;		//��ǰ�ṹ��İ汾,2
};

//�ṹ���СΪ0x23C
struct ProjectInfo
{
	uint32 dwVersion;			//�汾�ţ�Ϊ0x1F4
	uint32 lpObjectTable;		//****************������ָ��ObjectTable*
	uint32 dwNull;				//����
	uint32 lpCodeStart;			//VB�û�������ʼ��ַ,δ��ʹ��
	uint32 lpCodeEnd;			//VB�û����������ַ,δ��ʹ��
	uint32 dwDataSize;			//VB����ṹ���С,δ��ʹ��
	uint32 lpThreadSpace;		//�̶߳���Ķ���ָ��
	uint32 lpVbaSeh;			//VBA�쳣������ָ��
	uint32 lpNativeCode;		//���ݶ�ָ��
	uint8  szNone[0x210];		//�հ�,Internal Project Identifier
	uint32 lpExternalTable;		//****************API������ָ��
	uint32 dwExternalCount;		//****************����API�ĸ���
};


struct ProjectInfo2
{
	uint32 lpHeapLink;				//����,Ϊ0
	uint32 lpObjectTable;			//ָ��ObjectTable�ı���ָ��
	uint32 dwReserved1;				//����,Ϊ-1
	uint32 szNone1;					//����
	uint32 lpObjectList;			//ָ�����������Ϣ��ָ��,�����...
	uint32 szNone2;					//����
	uint32 szProjectDescription;	//ָ�򹤳�������ָ��
	uint32 szProjectHelpFile;		//ָ�򹤳̰����ļ���ָ��
	uint32 dwReserved2;				//����,Ϊ-1
	uint32 dwHelpContextId;			//���������еİ���ID
};

struct SControl
{
	uint8 szNone1;
	uint8 szNone2;
	qstring ControlName;
	uint8 szNone3;
	uint8 ControlID;
};

//�ṹ���СΪ0x50
struct GUITable
{
	uint32 StructSize;					//��ǰ�ṹ��Ĵ�С,Ϊ0x50
	uint8  guidObjectGUI[16];			//��ǰGUI�����GUID
	uint8  guidFreezeEventsIID[16];		//Freeze�¼���GUID
	uint32 ObjectId;					//�ڹ����еĶ���ID
	uint32 ControlFlags;				//����ؼ����ʹ�õ�flag
	uint32 fOLEMisc;					//OLEMisc flag
	uint8  guidObjectCLSID[16];			//CLSID
	uint32 lGUIObjectInfoSize;			//****************GUI������Ϣ�Ĵ�С
	uint32 dwNull;						//δ֪
	uint32 GUIObjectInfo;				//****************GUI������Ϣ,GUIObjectInfo*,����Ҳ������ſؼ�������λ�õ���Ϣ
	uint32 Offset;						//��VBHeader.lpGuiTable�������Ա��ƫ��
};

//�ṹ���СΪ0x44
struct RegistrationInfo
{
	uint32 bNextObject;				//COM�ӿ���Ϣ��ƫ��
	uint32 bObjectName;				//�������Ƶ�ƫ��
	uint32 bObjectDescription;		//����������ƫ��
	uint32 dwInstancing;			//ʵ��ģʽ
	uint32 dwObjectId;				//��ǰ�����ڹ����е�ID
	uint8 uuidObject[16];			//�����CLSID
	uint32 fIsInterface;			//ָʾ��һ��CLSID�Ƿ���Ч
	uint32 bUuidObjectIFace;		//����Ľӿڵ�CLSID��ƫ��
	uint32 bUuidEventsIFace;		//�����¼���CLSID��ƫ��
	uint32 fHasEvents;				//ָ�������CLSID�Ƿ���Ч
	uint32 dwMiscStatus;			//OLEMIC Flags
	uint8 fClassType;				//Class Type
	uint8 fObjectType;				//��������
	uint16 wToolboxBitmap32;		//�������еĿؼ�ͼID
	uint16 wDefaultIcon;			//�ؼ�������Сͼ��
	uint16 fIsDesigner;				//ָ���Ƿ�Ϊ�����
	uint32 bDesignerData;			//��Ƶ�����
};


//��СΪ0x2A
struct COMRegData
{
	uint32 bRegInfo;				//COM�ӿ���Ϣ��ƫ��,RegistrationInfo*
	uint32 bSZProjectName;			//Project����TypeLib��ƫ��
	uint32 bSZHelpDirectory;		//����Ŀ¼��ƫ��
	uint32 bSZProjectDescription;	//����������ƫ��
	uint8  uuidProjectCLSID[16];	//Project����TypeLib��CLSID
	uint32 dwTlbLcid;				//LCID of Type Library
	uint16 szNone;					//δ֪
	uint16 wTlbVerMajor;			//TypeLib���汾��
	uint16 wTlbVerMinor;			//TypeLib�ΰ汾��
};


struct ExternalControlInfo
{
	uint32 NextControlOffset;		//��һ���ؼ���ƫ��
	uint32 GuidOffset1;				//δ֪Guid��ƫ��
	uint32 szNone1;					//δ֪
	uint32 szNone2;					//δ֪
	uint32 NoneOffset1;				//δ֪ƫ��
	uint32 NoneOffset2;				//δ֪ƫ��
	uint32 NoneOffset3;				//δ֪ƫ��
	uint32 szNone3;					//δ֪
	uint32 szNone4;					//δ֪
	uint32 szNone5;					//δ֪
	uint32 LibNameOffset;			//����Ŀ�����ƫ��
	uint32 ControlOffset;			//�ؼ�ȫ��ƫ��
	uint32 ControlNameOffset;		//�ؼ����ƫ��
};

//�ṹ���СΪ0x68
struct VBHeader
{
	uint32 szVbMagic;			//VB���
	uint16 wRuntimeBuild;		//���п�汾?
	uint16 szLangDLL;			//������չDLL
	uint32 szNone1;				//δ֪
	uint32 szNone2;				//δ֪
	uint32 szNone3;				//δ֪
	uint16 szSecLangDLL;		//�ڶ�������չDLL
	uint32 szNone4;				//δ֪
	uint32 szNone5;				//δ֪
	uint32 szNone6;				//δ֪
	uint16 wRuntimeRevision;	//****************�ڲ����п�İ汾
	uint32 dwLCID;				//����DLL��LCID
	uint32 dwSecLCID;			//�ڶ�����DLL��LCID
	uint32 lpSubMain;			//****************Main�������
	uint32 lpProjectInfo;		//****************������Ϣ��ָ��,ProjectInfo*
	uint32 fMdlIntCtls;
	uint32 fMDlIntCtls2;
	uint32 dwThreadFlags;
	uint32 dwThreadCount;
	uint16 wFormCount;				//****************���ڵĸ���
	uint16 wExternalCount;			//����ؼ��ĸ���
	uint32 dwThunkCount;			//
	uint32 lpGuiTable;				//****************������Ϣ��ָ��,GUITable*
	uint32 lpExternalTable;			//ָ�����ؼ���Ϣ��ָ��,ExternalControlInfo*
	uint32 lpComRegisterData;		//ע��Com�����Ϣ,COMRegData*
	uint32 bSZProjectDescription;	//����������Ϣ��ƫ��
	uint32 bSZProjectExeName;		//EXE���Ƶ�ƫ��
	uint32 bSZProjectHelpFile;		//���̰����ļ���ƫ��
	uint32 bSZProjectName;			//****************���̵����Ƶ�ƫ��
};

#pragma pack(pop)


class VBDecompilerEngine
{
public:
	VBDecompilerEngine();
	~VBDecompilerEngine();
private:
	mid_VBHeader VBHEAD;
	void GetSControl(uint32 sControlAddr, SControl& result);

	qstring GetControlTypeName(uint8 ControlID);
	bool HandleNativeCode(uint32 vbHeadAddr);

	bool hasControl(uint32 ObjectType);
	bool hasOptionalObjectInfo(uint32 ObjType);
	qstring GetObjectTypeName(uint32 ObjType);

	bool LoadMethodLink(OptionalObjectInfo& info, qvector<mid_VTable>& oVec_MethodLink);

	//��ԭʼVB��Ϣ����Ϊ�м��VB��Ϣ,��ΪPCode��NativeCode����
	bool TranslateNVBInfo(uint32 NativeHeadAddr);
	bool TranslatePVBInfo(uint32 PCodeHeadAddr);

	bool VBDE_ComRegData(uint32 lpComRegDataAddr);
	bool VBDE_ExternalControl(uint32 lpExControlAddr, uint32 cCount);
public:
	bool DoDecompile(ea_t PEEntry);
	void MakeFunction();
	void CreateVTable();
	void SetSubMain();
	void SetEventFuncName(std::map<qstring, qvector<coClassInfo>>& oMap);
	void AddClassGuid(std::map<qstring, qvector<coClassInfo>>& oMap);

	//��ȡ�û��������ʼ��ַ
	ea_t GetUserCodeStartAddr();
	//��ȡ�û�����ν�����ַ
	ea_t GetUserCodeEndAddr();
};

