//
//	確認 MMX 指令集是否可以使用
//
//		Copyright (c) 2000 Chihiro.SAKAMOTO (HyperWorks)
//
#include "StdAfx.h"
#include "MMX.h"

bool CheckMMXTechnology()
{
	int	cpuid_support;

	//
	// 判斷是否支援CPUID指令
	//
	_asm	{
		pushfd
		pop eax
		xor eax,00200000h
		push eax
		popfd
		pushfd
		pop ebx
		cmp eax,ebx
		mov cpuid_support,1
		je L1
		mov cpuid_support,0
L1:
	} ;
	//
	// 如果不支援CPUID，就不支援MMX
	//
	if (!cpuid_support)
		return false;

	//
	// 使用 cpuid 指令判斷MMX指令是否存在
	//
	int		hv;
	_asm	{
		xor	eax,eax
		cpuid
		mov	hv,eax
	} ;
	if (hv < 1)
		return false;

	int		featureFlags;
	_asm	{
		mov	eax,1
		cpuid
		mov	featureFlags,edx
	} ;
	if (featureFlags & 0x00800000)
		return true;
	return false;
}

const bool MmxSupported = CheckMMXTechnology();
