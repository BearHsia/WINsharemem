#pragma once
#include <Windows.h>
#include "datastructure.h"

class SHARE_MEM_FORM_SIDE
{
public:
	SHARE_MEM_FORM_SIDE();
	~SHARE_MEM_FORM_SIDE();

	SHARE_MEMORY_DATA_STRUCT* ShareMemoryDataPtr;
private:
	void init();
	void close();

	//HANDLE hEvent;
	//HANDLE hShmem;
	//STARTUPINFO startUpInfo;
	//PROCESS_INFORMATION processInfo;
	wchar_t snEventName[32];
	wchar_t snShmemName[32];
	wchar_t RtssPathName[512];


	//bool createHandler();
	//bool createEvent();
	//bool createShmem();

	//bool deleteHandler();
	//bool deleteShmem();
	//bool deleteEvent();
	//bool waitForEvent();
};