// ARPTable.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "ARPTable.h"
#include <Iprtrmib.h>
#include <Iphlpapi.h>
#include <IOSTREAM>
#include <stdio.h>
using namespace std;
#define ARP_TABLE_SIZE   1
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 僅有的一個應用程式物件

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 並於失敗時列印錯誤
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 配合您的需要變更錯誤碼
		_tprintf(_T("嚴重錯誤: MFC 初始化失敗\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: 在此撰寫應用程式行為的程式碼。
		unsigned long nSize = ARP_TABLE_SIZE;

		PMIB_IPNETTABLE pMib = (PMIB_IPNETTABLE)malloc(sizeof(MIB_IPNETTABLE)+sizeof(MIB_IPNETROW)*nSize);

		DWORD dwRetval = GetIpNetTable(pMib,&nSize,TRUE); 
		while (dwRetval)
		{
		   dwRetval = GetIpNetTable(pMib, &nSize, TRUE);	   
		}

		DWORD dwNumEntries = (unsigned long)pMib->dwNumEntries ;	

		printf("---------------------------\n");

		/* 抓取ARP Information */
		for (DWORD i=0; i<dwNumEntries; i++) 
		{
			/* 列IP */
			printf("IP : %d.%d.%d.%d\n", pMib->table[i].dwAddr&0xff,
				(pMib->table[i].dwAddr&0xff00) >> 8,
				(pMib->table[i].dwAddr&0xff0000) >> 16,
				(pMib->table[i].dwAddr) >> 24);
		
			/* 列MAC */
			printf("MAC: %x-%x-%x-%x-%x-%x\n", (int)pMib->table[i].bPhysAddr[0],
				(int)pMib->table[i].bPhysAddr[1],
				(int)pMib->table[i].bPhysAddr[2],
				(int)pMib->table[i].bPhysAddr[3],
				(int)pMib->table[i].bPhysAddr[4],
				(int)pMib->table[i].bPhysAddr[5]);
		}

		printf("---------------------------\n");
	}

	return nRetCode;
}
