using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Runtime.InteropServices;//USE DLL

namespace SYWCardLib_CS_test
{
    public struct CardInfo
    {
        public int intType;//卡片類型
        public int intUsage;//卡片用途
        public int intConfiguration;//延伸資料類型

        public int intPassThroughCounter;//通行次數
        public int intHolidayWeekProgramValue;//周計畫+假日通行設定

        public int intStartExpirationDate;//卡片有效期限設定
        public int intEnd1eExpirationDate;//卡片有效期限設定
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 17)]
        public string strStartExpirationDate;//'YYYYMMddHHmm'
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 17)]
        public string strEndleExpirationDate;//'YYYYMMddHHmm'

        public int intFirstPassThroughTimeRange;//可通行時段
        public int intSecondPassThroughTimeRange;//可通行時段
        public int intThirdPassThroughTimeRange;//可通行時段

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 17)]
        public string strUserUniqueIdentifier;//用戶識別碼 "AAAAAAAA"(PS長度和原本不同)
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 5)]
        public string strScramblerCode;//擾碼設定 "aaaa"(PS長度和原本不同)

        //-----------------------------------------------------------
        //延伸資料
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string strUserPasswordCode;//使用者密碼設定 "12345678"(單一個)

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string strDoorName1;//門區名稱設定(使用類似ArrayList方式存取) GWC_DOOR_NAME_LENGTH_MAXIMUM=8
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string strDoorName2;//門區名稱設定(使用類似ArrayList方式存取) GWC_DOOR_NAME_LENGTH_MAXIMUM=8
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string strDoorName3;//門區名稱設定(使用類似ArrayList方式存取) GWC_DOOR_NAME_LENGTH_MAXIMUM=8
        public int intDoorNameSize;//紀錄SIZE

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 1152)]//http://codingjames.blogspot.tw/2009/08/cstructarray.html
        public int []intDoorAccess;//new int[1152];//門區群組設定(使用類似ArrayList方式存取) MAX=1152
        public int intDoorAccessSize;//紀錄SIZE
    }
    public static class SYWCardLib
    {
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Add")]
        public static extern double Add(double a, double b);
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WCard_init")]
        public static extern int WCard_init();
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WCard_detectReader")]
        public static extern int WCard_detectReader();
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WCard_read")]
        public static extern int WCard_read(ref IntPtr ptr);//讀取
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WCard_write")]
        public static extern int WCard_write(ref CardInfo res);
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WCard_readTest")]
        public static extern int WCard_readTest();
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WCard_writeTest")]
        public static extern int WCard_writeTest(int state);
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WCard_close")]
        public static extern int WCard_close();
    }
}
