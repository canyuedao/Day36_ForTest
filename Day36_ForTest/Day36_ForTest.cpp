// Day36_ForTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
LPCWSTR Mutex=(LPCWSTR)"more_windows";

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hMutex=OpenMutex(MUTEX_ALL_ACCESS,true,Mutex);
	if(hMutex==NULL){
		printf("�򿪻�����ʧ��\n");
		while(1);
		return 0;
	}
	printf("�ȴ���...\n");
	DWORD dwResult=WaitForSingleObject(hMutex,20*1000);
	switch(dwResult){
		case WAIT_ABANDONED:
			printf("ӵ�л������Ľ���������ֹ\n");
			break;
		case WAIT_OBJECT_0:
			printf("�Ѿ��յ��ź�\n");
			break;
		case WAIT_TIMEOUT:
			printf("�ź�δ�ڹ涨ʱ�����͵�\n");
			break;

	}
	//getchar();
	while(1);
	return 0;
}

