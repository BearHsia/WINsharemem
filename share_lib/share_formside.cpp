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
	wcscpy_s(this->RtssPathName, L""); // the first argument of lstrcat() must be null-terminated
	lstrcat((RtssPathName), arrDirStr);
	
	//lstrcat(RtssPathName, L"..\\Debug\\winkernel.exe\"");
	lstrcat(RtssPathName, L"\\winkernel.exe");
	//printf("%ls", RtssPathName);
	/*FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "output.txt", "w")) == NULL) {
		fprintf(fp, "%ls", RtssPathName);
		fclose(fp);
	}*/

	init();
}

SHARE_MEM_FORM_SIDE::~SHARE_MEM_FORM_SIDE()
{
	close();
}

bool SHARE_MEM_FORM_SIDE::init()
{
	createHandler();

	bool bResult = 0;

	if (ShareMemoryDataPtr->systemRunning)
		return true;

	ZeroMemory(&startUpInfo, sizeof(STARTUPINFO));
	startUpInfo.cb = sizeof(STARTUPINFO);
	ZeroMemory(&processInfo, sizeof(PROCESS_INFORMATION));
	
	bResult = CreateProcess(
		RtssPathName,  // _In_opt_ LPCWSTR lpApplicationName,
		NULL,		   // _Inout_opt_ LPWSTR lpCommandLine,
		NULL,		   // _In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,
		NULL,		   // _In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,
		FALSE,		   // _In_ BOOL bInheritHandles,
		0,		   // _In_ DWORD dwCreationFlags,
		NULL,		   // _In_opt_ LPVOID lpEnvironment,
		NULL,		   // _In_opt_ LPCWSTR lpCurrentDirectory,
		&startUpInfo,  // _In_ LPSTARTUPINFOW lpStartupInfo,
		&processInfo); // _Out_ LPPROCESS_INFORMATION lpProcessInformation
	
	if (bResult == false)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return false;
	}
	
	//wait for windows console
	//DWORD OpenState;
	//OpenState = WaitForSingleObject(processInfo.hProcess, INFINITE);
	
	waitForEvent();
	ShareMemoryDataPtr->systemRunning = true;
	
	return true;
}

bool SHARE_MEM_FORM_SIDE::createHandler()
{
	createEvent();
	createShmem();
	return true;
}

bool  SHARE_MEM_FORM_SIDE::createEvent()
{
	hEvent = OpenEvent(NULL, NULL, snEventName);
	if (hEvent == NULL)
	{
		hEvent = CreateEvent(NULL, 1, 0, snEventName);
	}
	return true;
}

bool  SHARE_MEM_FORM_SIDE::createShmem()
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

bool SHARE_MEM_FORM_SIDE::close()
{
	if (ShareMemoryDataPtr != NULL)
	{
		ShareMemoryDataPtr->systemRunning = false; 
		// this will break the while loop
		// and automatically terminate the process
		waitForEvent();
		deleteHandler();
		ShareMemoryDataPtr = NULL;
	}
	return true;
}

bool SHARE_MEM_FORM_SIDE::deleteHandler()
{
	deleteShmem();
	deleteEvent();
	return true;
}

bool SHARE_MEM_FORM_SIDE::deleteShmem()
{
	UnmapViewOfFile((PVOID)ShareMemoryDataPtr);
	CloseHandle(hShmem);
	return true;
}

bool SHARE_MEM_FORM_SIDE::deleteEvent()
{
	CloseHandle(hEvent);
	return true;
}

bool SHARE_MEM_FORM_SIDE::waitForEvent(void)
{
	WaitForSingleObject(hEvent, INFINITE);
	ResetEvent(hEvent);
	return true;
}