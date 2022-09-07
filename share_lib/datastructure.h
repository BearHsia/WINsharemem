#pragma once

#define CNC_EVENT_NAME			L"CNC_EVENT"
//indicates the end of winkernel

#define CNC_SHMEM_NAME			L"CNC_SHMEM"

// sampling time
constexpr long long RTX_KERNEL_SAMPLING_TIME = 100;
constexpr long long WIN_KERNEL_SAMPLING_TIME = 100;
constexpr long long WIN_KERNEL_LOOP_SLEEP_TIME = 100;

typedef struct
{
	bool					systemRunning;
	bool					Enable; // for RT and NRT loop
	int						RealTimeCounter;
	int						nonRealTimeCounter;
} SHARE_MEMORY_DATA_STRUCT;