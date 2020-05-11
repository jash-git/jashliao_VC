// Filter.cpp: implementation of the CFilter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemsGroServer.h"
#include "Filter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFilter::CFilter()
{
	K1X1p_secorder1=0.0f;K2X1p_secorder1=0.0f;K3X1p_secorder1=0.0f;K4X1p_secorder1=0.0f;
	K1X2p_secorder1=0.0f;K2X2p_secorder1=0.0f;K3X2p_secorder1=0.0f;K4X2p_secorder1=0.0f;
	XX1p_secorder1=0.0f;Y_secorder1=0.0f;
	XX2p_secorder1=0.0f;
	////////////////////////////
	secorder1.dut=0.0f;
	secorder1.fa=1.0f;
	secorder1.fb=87.92f; 
	secorder1.fc=3943.84f; 
	secorder1.fd=0.0f; 
	secorder1.fe=3943.84f;
	secorder1.ut=0.0f;
	secorder1.x1=0.0f;
	secorder1.x2=0.0f;
	//////////////////////////
}

CFilter::~CFilter()
{

}
float CFilter::SecOrderLowPass(float u)
{

	//////////////////////////////////////////////////

	//runge-kuta 參數   
	float delT=0.01f;
	secorder1.ut=u;
	K1X1p_secorder1=0.0f;K2X1p_secorder1=0.0f;K3X1p_secorder1=0.0f;K4X1p_secorder1=0.0f;
	K1X2p_secorder1=0.0f;K2X2p_secorder1=0.0f;K3X2p_secorder1=0.0f;K4X2p_secorder1=0.0f;
	XX1p_secorder1=0.0f;Y_secorder1=0.0f;
	XX2p_secorder1=0.0f;
	// K1=Tf(x,t);      //以下為runge-kuta的運算
	K1X1p_secorder1 = secorder1.x2;//x1的微分=p1 (x1鬥特=p1)
	K1X2p_secorder1 = -(secorder1.fc/secorder1.fa)*secorder1.x1 - (secorder1.fb/secorder1.fa)*secorder1.x2 + (secorder1.fd/secorder1.fa)*secorder1.dut+(secorder1.fe/secorder1.fa)*secorder1.ut;
	// K2=Tf(x+b1k1 , t+a1T);
	XX1p_secorder1 = secorder1.x1 +delT/2.0f * K1X1p_secorder1;
	XX2p_secorder1 = secorder1.x2 +delT/2.0f * K1X2p_secorder1;
	K2X1p_secorder1=XX2p_secorder1;
	K2X2p_secorder1 = -(secorder1.fc/secorder1.fa)*XX1p_secorder1 - (secorder1.fb/secorder1.fa)*XX2p_secorder1 + (secorder1.fd/secorder1.fa)*secorder1.dut+(secorder1.fe/secorder1.fa)*secorder1.ut;
	// K3=Tf(x+b2K1+b3K2 , t+a2T);
	XX1p_secorder1 = secorder1.x1 + delT/2.0f * K2X1p_secorder1;
	XX2p_secorder1 = secorder1.x2 + delT/2.0f * K2X2p_secorder1;
	K3X1p_secorder1=XX2p_secorder1;
	K3X2p_secorder1 = -(secorder1.fc/secorder1.fa)*XX1p_secorder1 - (secorder1.fb/secorder1.fa)*XX2p_secorder1 + (secorder1.fd/secorder1.fa)*secorder1.dut+ (secorder1.fe/secorder1.fa)*secorder1.ut;
	// K4=Tf(x+b4k1+b5K2+b6K3 , t+a3T);
	XX1p_secorder1 = secorder1.x1 + delT * K3X1p_secorder1;
	XX2p_secorder1 = secorder1.x2 + delT * K3X2p_secorder1;
	K4X1p_secorder1=XX2p_secorder1;
	K4X2p_secorder1 = -(secorder1.fc/secorder1.fa)*XX1p_secorder1 - (secorder1.fb/secorder1.fa)*XX2p_secorder1 + (secorder1.fd/secorder1.fa)*secorder1.dut+ (secorder1.fe/secorder1.fa)*secorder1.ut;
	secorder1.x1=secorder1.x1+delT*(K1X1p_secorder1+2.0f*(K2X1p_secorder1+K3X1p_secorder1)+K4X1p_secorder1)/6.0f;
	secorder1.x2=secorder1.x2+delT*(K1X2p_secorder1+2.0f*(K2X2p_secorder1+K3X2p_secorder1)+K4X2p_secorder1)/6.0f;
	return secorder1.x1;

}