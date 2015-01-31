// Day36_ForTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
LPCWSTR Mutex=(LPCWSTR)"more_windows";

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hMutex=OpenMutex(MUTEX_ALL_ACCESS,true,Mutex);
	if(hMutex==NULL){
		printf("打开互斥量失败\n");
		while(1);
		return 0;
	}
	printf("等待中...\n");
	DWORD dwResult=WaitForSingleObject(hMutex,20*1000);
	switch(dwResult){
		case WAIT_ABANDONED:
			printf("拥有互斥量的进程意外终止\n");
			break;
		case WAIT_OBJECT_0:
			printf("已经收到信号\n");
			break;
		case WAIT_TIMEOUT:
			printf("信号未在规定时间内送到\n");
			break;

	}
	//getchar();
	while(1);
	return 0;
}

