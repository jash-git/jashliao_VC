#pragma once

// 以 Microsoft Visual C++ 建立，由電腦產生的 IDispatch 包裝函式類別

// 注意: 請勿修改這個檔案的內容。如果這個類別是由
//  Microsoft Visual C++ 產生的，您的修改將會被覆寫。

/////////////////////////////////////////////////////////////////////////////
// COcx1 包裝函式類別

class COcx1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(COcx1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x6BF52A52, 0x394A, 0x11D3, { 0xB1, 0x53, 0x0, 0xC0, 0x4F, 0x79, 0xFA, 0xA6 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 屬性
public:
enum
{
    amvUninitialized = 0,
    amvLoading = 1,
    amvInteractive = 3,
    amvComplete = 4
}ReadyStateConstants;
enum
{
    mpStopped = 0,
    mpPaused = 1,
    mpPlaying = 2,
    mpWaiting = 3,
    mpScanForward = 4,
    mpScanReverse = 5,
    mpClosed = 6
}MPPlayStateConstants;
enum
{
    mpDefaultSize = 0,
    mpHalfSize = 1,
    mpDoubleSize = 2,
    mpFullScreen = 3,
    mpFitToSize = 4,
    mpOneSixteenthScreen = 5,
    mpOneFourthScreen = 6,
    mpOneHalfScreen = 7
}MPDisplaySizeConstants;
enum
{
    mpReadyStateUninitialized = 0,
    mpReadyStateLoading = 1,
    mpReadyStateInteractive = 3,
    mpReadyStateComplete = 4
}MPReadyStateConstants;
enum
{
    mpTime = 0,
    mpFrames = 1
}MPDisplayModeConstants;
enum
{
    mpShowURL = 0,
    mpClipURL = 1,
    mpBannerURL = 2
}MPMoreInfoType;
enum
{
    mpShowFilename = 0,
    mpShowTitle = 1,
    mpShowAuthor = 2,
    mpShowCopyright = 3,
    mpShowRating = 4,
    mpShowDescription = 5,
    mpShowLogoIcon = 6,
    mpClipFilename = 7,
    mpClipTitle = 8,
    mpClipAuthor = 9,
    mpClipCopyright = 10,
    mpClipRating = 11,
    mpClipDescription = 12,
    mpClipLogoIcon = 13,
    mpBannerImage = 14,
    mpBannerMoreInfo = 15,
    mpWatermark = 16
}MPMediaInfoType;
enum
{
    dvdMenu_Title = 2,
    dvdMenu_Root = 3,
    dvdMenu_Subpicture = 4,
    dvdMenu_Audio = 5,
    dvdMenu_Angle = 6,
    dvdMenu_Chapter = 7
}DVDMenuIDConstants;
enum
{
    mpShowDialogHelp = 0,
    mpShowDialogStatistics = 1,
    mpShowDialogOptions = 2,
    mpShowDialogContextMenu = 3
}MPShowDialogConstants;


// 作業
public:
////////////////////////////////////////////////////////////////
//jash Write
void close()
 {
  InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
 }
 CString get_URL()
 {
  CString result;
  InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
  return result;
 }
 void put_URL(LPCTSTR newValue)
 {
  static BYTE parms[] = VTS_BSTR ;
  InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 long get_openState()
 {
  long result;
  InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
  return result;
 }
 long get_playState()
 {
  long result;
  InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_controls()
 {
  LPDISPATCH result;
  InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_settings()
 {
  LPDISPATCH result;
  InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_currentMedia()
 {
  LPDISPATCH result;
  InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 void put_currentMedia(LPDISPATCH newValue)
 {
  static BYTE parms[] = VTS_DISPATCH ;
  InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 LPDISPATCH get_mediaCollection()
 {
  LPDISPATCH result;
  InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_playlistCollection()
 {
  LPDISPATCH result;
  InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 CString get_versionInfo()
 {
  CString result;
  InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
  return result;
 }
 void launchURL(LPCTSTR bstrURL)
 {
  static BYTE parms[] = VTS_BSTR ;
  InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrURL);
 }
 LPDISPATCH get_network()
 {
  LPDISPATCH result;
  InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_currentPlaylist()
 {
  LPDISPATCH result;
  InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 void put_currentPlaylist(LPDISPATCH newValue)
 {
  static BYTE parms[] = VTS_DISPATCH ;
  InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 LPDISPATCH get_cdromCollection()
 {
  LPDISPATCH result;
  InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_closedCaption()
 {
  LPDISPATCH result;
  InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 BOOL get_isOnline()
 {
  BOOL result;
  InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_Error()
 {
  LPDISPATCH result;
  InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 CString get_status()
 {
  CString result;
  InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_dvd()
 {
  LPDISPATCH result;
  InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH newPlaylist(LPCTSTR bstrName, LPCTSTR bstrURL)
 {
  LPDISPATCH result;
  static BYTE parms[] = VTS_BSTR VTS_BSTR ;
  InvokeHelper(0x29, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrName, bstrURL);
  return result;
 }
 LPDISPATCH newMedia(LPCTSTR bstrURL)
 {
  LPDISPATCH result;
  static BYTE parms[] = VTS_BSTR ;
  InvokeHelper(0x2a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrURL);
  return result;
 }
 BOOL get_enabled()
 {
  BOOL result;
  InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
  return result;
 }
 void put_enabled(BOOL newValue)
 {
  static BYTE parms[] = VTS_BOOL ;
  InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 BOOL get_fullScreen()
 {
  BOOL result;
  InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
  return result;
 }
 void put_fullScreen(BOOL newValue)
 {
  static BYTE parms[] = VTS_BOOL ;
  InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 BOOL get_enableContextMenu()
 {
  BOOL result;
  InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
  return result;
 }
 void put_enableContextMenu(BOOL newValue)
 {
  static BYTE parms[] = VTS_BOOL ;
  InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 void put_uiMode(LPCTSTR newValue)
 {
  static BYTE parms[] = VTS_BSTR ;
  InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 CString get_uiMode()
 {
  CString result;
  InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
  return result;
 }
 BOOL get_stretchToFit()
 {
  BOOL result;
  InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
  return result;
 }
 void put_stretchToFit(BOOL newValue)
 {
  static BYTE parms[] = VTS_BOOL ;
  InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 BOOL get_windowlessVideo()
 {
  BOOL result;
  InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
  return result;
 }
 void put_windowlessVideo(BOOL newValue)
 {
  static BYTE parms[] = VTS_BOOL ;
  InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
 }
 BOOL get_isRemote()
 {
  BOOL result;
  InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
  return result;
 }
 LPDISPATCH get_playerApplication()
 {
  LPDISPATCH result;
  InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
  return result;
 }
 void openPlayer(LPCTSTR bstrURL)
 {
  static BYTE parms[] = VTS_BSTR ;
  InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrURL);
 }
/////////////////////////////////////////////////////////////////////////


};
