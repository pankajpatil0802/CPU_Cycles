#include <stdio.h>
#include <windows.h>


int main(int argc, char* argv[])
{
	if (2 != argc)
	{
		return 0;
	}

	BOOL boRet;
	HANDLE hProcess;
	ULONG64 CycleTime;

	int Pid = atoi(argv[1]);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, Pid);
	if (NULL == hProcess)
	{
		//printf("OpenProcess failed");
		printf("0");
		return 0;
	}


	boRet = QueryProcessCycleTime(hProcess, &CycleTime);
	if (false == boRet)
	{
		//printf("QueryProcessCycleTime failed");
		printf("0");
		CloseHandle(hProcess);
		return 0;
	}

	printf("%llu", CycleTime);
	CloseHandle(hProcess);
	return CycleTime;
}
