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

bool SHARE_MEM_KERNEL_SIDE::close()
{
	deleteHandler();
	delete ShareMemoryDataPtr;
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
	return true;
}

bool SHARE_MEM_KERNEL_SIDE::deleteEvent()
{
	CloseHandle(hEvent);
	return true;
}