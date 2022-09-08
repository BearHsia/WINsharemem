// winkernel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\share_lib\share_kernelside.h"

HANDLE gDoneEvent;
void CALLBACK TimerRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
	if (lpParam != NULL)
	{
		((SHARE_MEM_KERNEL_SIDE*)(lpParam))->main();
	}
	if(!((SHARE_MEM_KERNEL_SIDE*)(lpParam))->IsRtxRunningState())
		SetEvent(gDoneEvent);
}

void NonRealTimeLoop(SHARE_MEM_KERNEL_SIDE* shareMemoryKernelPtr)
{
	if (shareMemoryKernelPtr != NULL)
		shareMemoryKernelPtr->testNrtMain();
}

int main()
{
    std::cout << "Hello World!\n";
	SHARE_MEM_KERNEL_SIDE* shareMemoryKernelPtr = new SHARE_MEM_KERNEL_SIDE();
	shareMemoryKernelPtr->init();
	std::cout << "SHM is initialized!\n";

	gDoneEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	HANDLE hTimer = NULL;
	HANDLE hTimerQueue = CreateTimerQueue();
	
	CreateTimerQueueTimer(
		&hTimer,
		hTimerQueue,
		(WAITORTIMERCALLBACK)TimerRoutine,
		(PVOID)shareMemoryKernelPtr,
		0, WIN_KERNEL_SAMPLING_TIME, 0);
	std::cout << "Create Timer!\n";

	shareMemoryKernelPtr->setEvent(); //signal the process is ready

	std::cout << "Start!\n";
	while (shareMemoryKernelPtr->IsRtxRunningState())
	{
		//nrt main loop
		NonRealTimeLoop(shareMemoryKernelPtr);
		Sleep(WIN_KERNEL_LOOP_SLEEP_TIME);
	}
	std::cout << "Stop!\n";

	if (WaitForSingleObject(gDoneEvent, INFINITE) != WAIT_OBJECT_0)
		printf("WaitForSingleObject failed (%d)\n", GetLastError());
	CloseHandle(gDoneEvent);

	// Delete all timers in the timer queue.
	if (!DeleteTimerQueue(hTimerQueue))
		printf("DeleteTimerQueue failed (%d)\n", GetLastError());

	shareMemoryKernelPtr->setEvent();  //signal the process is closed
	delete shareMemoryKernelPtr;
	std::cout << "SHM closed!\n";
	ExitProcess(0);
	return 0;
}