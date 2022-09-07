#include "pch.h"
#include "share_kernelside.h"
#include <limits.h>

SHARE_MEM_KERNEL_SIDE::SHARE_MEM_KERNEL_SIDE()
{
	wcscpy_s(this->snEventName, CNC_EVENT_NAME);
	wcscpy_s(this->snShmemName, CNC_SHMEM_NAME);
}

SHARE_MEM_KERNEL_SIDE::~SHARE_MEM_KERNEL_SIDE()
{
	close();
}

void SHARE_MEM_KERNEL_SIDE::main()
{
	if (!ShareMemoryDataPtr->Enable)
		return;
	if (ShareMemoryDataPtr->RealTimeCounter < INT_MAX)
		ShareMemoryDataPtr->RealTimeCounter++;
	else
		ShareMemoryDataPtr->RealTimeCounter = 0;

	return;
}

void SHARE_MEM_KERNEL_SIDE::testNrtMain()
{
	if (!ShareMemoryDataPtr->Enable)
		return;
	if (ShareMemoryDataPtr->nonRealTimeCounter < INT_MAX)
		ShareMemoryDataPtr->nonRealTimeCounter++;
	else
		ShareMemoryDataPtr->nonRealTimeCounter = 0;

	return;
}

bool SHARE_MEM_KERNEL_SIDE::init()
{
	// system initial
	createHandler();

	ShareMemoryDataPtr->systemRunning = true;
	ShareMemoryDataPtr->Enable = false;
	ShareMemoryDataPtr->RealTimeCounter = 0;
	ShareMemoryDataPtr->nonRealTimeCounter = 0;
	return true;
}

bool SHARE_MEM_KERNEL_SIDE::createHandler()
{
	createEvent();
	createShmem();

	return true;
}

bool  SHARE_MEM_KERNEL_SIDE::createEvent()
{
	hEvent = OpenEvent(NULL, NULL, snEventName);
	if (hEvent == NULL)
	{
		hEvent = CreateEvent(NULL, 1, 0, snEventName);
	}
	return true;
}

bool  SHARE_MEM_KERNEL_SIDE::createShmem()
{
	PVOID location;
	BOOLEAN bInit = 0;

	hShmem = OpenFileMapping(FILE_MAP_ALL_ACCESS, true, snShmemName);

	if (hShmem == NULL)
	{
		hShmem = CreateFileMapping(
			INVALID_HANDLE_VALUE,	// use paging file
			NULL,					// default security
			PAGE_READWRITE,			// read and write access
			0,						// maximum object size (high-order DWORD)
			sizeof(SHARE_MEMORY_DATA_STRUCT),// maximum object size (low-order DWORD)
			snShmemName						// LPCWSTR lpName
		);

		location = MapViewOfFile(hShmem, FILE_MAP_ALL_ACCESS, 0, 0, 0);

		bInit = 1;
	}
	else
	{
		location = MapViewOfFile(hShmem, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	}

	ShareMemoryDataPtr = (SHARE_MEMORY_DATA_STRUCT *)location;

	if (bInit)
	{
		ZeroMemory(ShareMemoryDataPtr, sizeof(SHARE_MEMORY_DATA_STRUCT));
	}

	return true;
}

void SHARE_MEM_KERNEL_SIDE::setEvent()
{
	SetEvent(hEvent);
}

bool SHARE_MEM_KERNEL_SIDE::IsRtxRunningState()
{
	return ShareMemoryDataPtr->systemRunning;
}

bool SHARE_MEM_KERNEL_SIDE::close()
{
	deleteHandler();
	return true;
}

bool SHARE_MEM_KERNEL_SIDE::deleteHandler()
{
	deleteShmem();
	deleteEvent();
	return true;
}

bool SHARE_MEM_KERNEL_SIDE::deleteShmem()
{
	UnmapViewOfFile((PVOID)ShareMemoryDataPtr);
	//this invalidates the range and decrements the physical page
	//and make this range available for others
	CloseHandle(hShmem);
	//After the last handle to an object is closed, 
	//the object is removed from the system
	ShareMemoryDataPtr = NULL;
	return true;
}

bool SHARE_MEM_KERNEL_SIDE::deleteEvent()
{
	CloseHandle(hEvent);
	return true;
}