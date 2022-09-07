#pragma once
#include <Windows.h>
#include <tchar.h>
#include "datastructure.h"

class SHARE_MEM_KERNEL_SIDE
{
public:
	SHARE_MEM_KERNEL_SIDE();
	~SHARE_MEM_KERNEL_SIDE();
	//bool init();
	//void main();
	//void testNrtMain();
	bool close();
	//void setEvent();
	//bool IsRtxRunningState();
	SHARE_MEMORY_DATA_STRUCT* ShareMemoryDataPtr;

private:

	HANDLE hEvent;
	HANDLE hShmem;
	wchar_t snEventName[32];
	wchar_t snShmemName[32];

	//bool createHandler();
	//bool createEvent();
	//bool createShmem();

	bool deleteHandler();
	bool deleteShmem();
	bool deleteEvent();
};