#include "ComManager.h"

#include <hexrays.hpp>
#include <diskio.hpp>


int idaapi EnumerateTypeLib(const char* file, void* ud)
{
	qvector<qstring>* pRecvData = (qvector<qstring>*)ud;
	pRecvData->push_back(file);
	return 0;
}

void InitComManager()
{
	//To do...�ж�COMĿ¼�Ƿ����

	qstring qstr_idaDir = idadir(PLG_SUBDIR);
	qstring qstr_ComDir = qstr_idaDir + "\\COM";
	qstring qstr_VBHpp = qstr_ComDir + "\\";
	qstr_VBHpp += VBHPPFILE;

	//To do...�������������ж��Ƿ���Ҫ��������VBhppͷ�ļ��Ĺ���
	bool needUpdateHpp = false;

	qvector<qstring> vec_ComFile;
	enumerate_files(0, 0, qstr_ComDir.c_str(), "*.*", EnumerateTypeLib, &vec_ComFile);

	
	GenerateComHpp(vec_ComFile);
	
	
	return;
}