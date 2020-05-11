// EasyPlayer.cpp : implementation file
//

#include "stdafx.h"

#include "Player.h"
#include "vfw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


UINT LoopThread(LPVOID pParam);
/////////////////////////////////////////////////////////////////////////////
// Player

Player::Player(HWND hwParent)
{
	hwndParent=hwParent;

	m_sPath="";
	c_Player=NULL;
}

Player::Player()
: mZoom(0)
{
	hwndParent=NULL;

	m_sPath="";
	c_Player=NULL;;
}

Player::~Player()
{
	MCIWndDestroy(c_Player);
	c_Player=NULL;
	m_sPath="";
}

BEGIN_MESSAGE_MAP(Player, CWnd)
	//{{AFX_MSG_MAP(Player)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Player message handlers

void Player::OnDestroy() 
{
	CWnd::OnDestroy();
	
	MCIWndDestroy(c_Player);
	
}
//hwndParent的访问器
void Player::SetParent(HWND hParent)
{
	hwndParent=hParent;
}

HWND Player::GetParent()
{
	return hwndParent;
}
//Path的访问器
void Player::SetPath(CString sPath)
{
	m_sPath=sPath;
}

CString Player::GetPath()
{
	return m_sPath;
}
//返回MCI设备当前状态
/*
Operating mode       MCI constant 
not ready            MCI_MODE_NOT_READY 
open                 MCI_MODE_OPEN 
paused               MCI_MODE_PAUSE 
playing              MCI_MODE_PLAY 
recording            MCI_MODE_RECORD 
seeking              MCI_MODE_SEEK 
stopped              MCI_MODE_STOP 
*/
long Player::GetMode()
{
	char lp[3];
	long lMode;
	
	lMode=MCIWndGetMode(c_Player,lp,sizeof(lp));

	return lMode;
}

void Player::Kill()
{
	MCIWndClose(c_Player);
	/*
	该函数向窗口发送一个WM_CLOSE消息,窗口接收到该消息之后,关闭所打
	开的MCI文件,并关闭窗口。虽然SDK还提供了一个MCIWndClose函数,但
	该函数只能关闭在MCIWnd窗口中打开的文件,而MCIWnd窗口仍处于开启
	状态,仍可以打开其它MCI文件并进行播放。
	文章出处：http://www.diybl.com/course/3_program/c++/cppsl/200819/96105.html
	*/
	MCIWndDestroy(c_Player);
}

void Player::Resume()
{
	//恢复播放
	MCIWndResume(c_Player);
}

void Player::Play()
{
	//开始播放
	MCIWndPlay(c_Player);
}

void Player::Stop()
{
	//停止播放
	MCIWndStop(c_Player);
}

void Player::Pause()
{
	//暂停
	MCIWndPause(c_Player);
}

HWND Player::Initialize()
{
	//建立播放句柄
	c_Player=MCIWndCreate(hwndParent,AfxGetInstanceHandle(),
		WS_CHILD | WS_VISIBLE| MCIWNDF_NOMENU| MCIWNDF_NOTIFYALL| MCIWNDF_NOPLAYBAR,
		m_sPath);
	//设置时间格式,"frames"帧，或"ms"毫秒
	MCIWndSetTimeFormat(c_Player,_T("ms"));
	//设置更新周期
	MCIWndSetActiveTimer(c_Player,100);
	//得到当前音量
	lVolume=MCIWndGetVolume(c_Player);

	return c_Player;
}

void Player::Close()
{
	//关闭当前打开的mci文件
	MCIWndClose(c_Player);
}

UINT LoopThread(LPVOID pParam)
{

	CParams* pParameters;
	pParameters=(CParams*)pParam;

	Player* pWnd=(Player*)pParameters->pWnd;
	CEvent* pEvent=(CEvent*)pParameters->pEvent;
	HWND c_Player=(HWND)pParameters->hWnd;

	while(WaitForSingleObject(pEvent->m_hObject,5)==WAIT_TIMEOUT)
	{
		if (pWnd->GetMode()==MCI_MODE_STOP)
		::SendMessage(c_Player, MCI_PLAY, 0, 0);
	}

	return 0;
}

void Player::Loop()
{
	CParams Params;
	//重置内核时间
	m_Event.ResetEvent();

	Params.pWnd=(Player*)this;
	Params.pEvent=&m_Event;
	Params.hWnd=c_Player;

	AfxBeginThread(LoopThread,&Params);
}

void Player::Break()
{
	//使事件处于触发状态
	m_Event.SetEvent();
	Stop();
}

HWND Player::GetWindowHandle()
{
	return c_Player;
}

void Player::SetPosition(long lPos)
{
	//设置视频播放位置
	MCIWndSeek(c_Player,lPos);
}

long Player::GetPosition()
{
	//得到当前播放位置
	return MCIWndGetPosition(c_Player);
}

long Player::GetLength()
{
	//得到视频长度
	return MCIWndGetLength(c_Player);
}

void Player::SetVolume(long lVol)
{
	//设置音量
	lVolume=lVol;
	MCIWndSetVolume(c_Player,lVol);
}

long Player::GetVolume()
{
	//得到当前音量
	return lVolume;
}

void Player::IncreaseVolume()
{
	//加音量
	lVolume+=50;
	if (lVolume>=1000)
		lVolume=1000;

	SetVolume(lVolume);
}

void Player::DecreaseVolume()
{
	//减音量
	lVolume-=50;
	if (lVolume<=0)
		lVolume=0;

	SetVolume(lVolume);
}

void Player::Fwd()
{
	//快进
	lPos=GetPosition();
	lPos+=10000;
	if (lPos>GetLength())
		lPos=GetLength();

	SetPosition(lPos);
}

void Player::Rwd()
{
	//快退
	lPos=GetPosition();
	lPos-=10000;
	if (lPos<0)
		lPos=0;

	SetPosition(lPos);
}

int Player::SetSize(int zoom)
{
	//设置缩放比例，100为原来大小
	MCIWndSetZoom(c_Player,zoom);
	return 0;
}

int Player::GetSize(void)
{
	return mZoom;
}
