#include "pch.h"
#include "share_formside.h"
#include <limits.h>
#include <stdio.h>

SHARE_MEM_FORM_SIDE::SHARE_MEM_FORM_SIDE()
{
	wcscpy_s(this->snEventName, CNC_EVENT_NAME);
	wcscpy_s(this->snShmemName, CNC_SHMEM_NAME);

	wchar_t arrDirStr[512];
	GetCurrentDirectory(512, arrDirStr);
	wcscpy_s(this->RtssPathName, L"\"");
	lstrcat((RtssPathName), arrDirStr);
	lstrcat(RtssPathName, L"..\Debug\winkernel.exe\"");
	printf("%ls", RtssPathName);
	init();
}

SHARE_MEM_FORM_SIDE::~SHARE_MEM_FORM_SIDE()
{
	close();
}

void SHARE_MEM_FORM_SIDE::init()
{
	//temp
	ShareMemoryDataPtr = new SHARE_MEMORY_DATA_STRUCT;
	ShareMemoryDataPtr->systemRunning = TRUE;
}

void SHARE_MEM_FORM_SIDE::close()
{
	//temp
	delete ShareMemoryDataPtr;
}