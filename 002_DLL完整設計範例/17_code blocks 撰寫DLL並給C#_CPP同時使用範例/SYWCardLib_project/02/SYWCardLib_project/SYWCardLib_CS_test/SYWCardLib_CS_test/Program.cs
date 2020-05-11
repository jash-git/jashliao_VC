using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace SYWCardLib_CS_test
{
    class Program
    {
        static void Pause()
        {
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }
        static void Main(string[] args)
        {
            CardInfo res = new CardInfo();
            res.intDoorAccess = new int[1152];
            res.intType = 1;
            res.intUsage = 1;
            res.intConfiguration = 9;
            res.intPassThroughCounter = 127;

            res.intHolidayWeekProgramValue = 0xEF;
            res.strStartExpirationDate="2016/06/07/15/34";//'YYYYMMddHHmm'
            res.strEndleExpirationDate="2016/06/07/15/34";//'YYYYMMddHHmm'

            res.intFirstPassThroughTimeRange = 100;//可通行時段
            res.intSecondPassThroughTimeRange = 200;//可通行時段
            res.intThirdPassThroughTimeRange = 300;//可通行時段

            res.strUserUniqueIdentifier="ABCDEFED";

            res.strScramblerCode="abcd";

            res.strUserPasswordCode="19810502";

            res.intDoorNameSize = 1;
            res.strDoorName1="Door-99";

            res.intDoorAccessSize = 1152;
            int i = 0;
            for (i = 0; i < 1152; i += 2)
            {
                res.intDoorAccess[i] = 1;
            }
            Console.WriteLine("6.8+3.2={0}",SYWCardLib.Add(6.8, 3.2));
            Console.WriteLine("call SYWCardLib.Add finish...");
            if (SYWCardLib.WCard_init() == 0)
            {
                int state = 0;
                if (state == 0)
                {
                    Console.WriteLine("WCard_write = {0}", SYWCardLib.WCard_write(ref res));
                    Pause();//把卡片移開讀卡機之後再回讀卡機等到BEEP才可以進行下一個動作
                    
                    IntPtr IP_res;// = new IntPtr();
                    IP_res = new IntPtr();
                    CardInfo[] carddata = new CardInfo[1];
	
                    Console.WriteLine("WCard_readTest = {0}", SYWCardLib.WCard_read(ref IP_res));

                    carddata[0] = (CardInfo)Marshal.PtrToStructure(IP_res + Marshal.SizeOf(typeof(CardInfo)) * 0, typeof(CardInfo));

                    Console.WriteLine( "GWCCardGetTypet = {0}",carddata[0].intType);
                    Console.WriteLine( "GWCCardGetUsaget = {0}" ,carddata[0].intUsage);
                    Console.WriteLine( "GWCCardGetConfigurationt = {0}" ,carddata[0].intConfiguration);
                    Console.WriteLine( "GWCCardGetPassThroughCountert = {0}" ,carddata[0].intPassThroughCounter);
                    Console.WriteLine( "GWCCardGetHolidayWeekProgramValuet = {0}" ,carddata[0].intHolidayWeekProgramValue);
                    Console.WriteLine( "GWCCardGetExpirationDatet = {0}~{1}" ,carddata[0].intStartExpirationDate,carddata[0].intEnd1eExpirationDate);
                    Console.WriteLine( "GWCCardGetPassThroughTimeRanget = {0},{1},{2}",carddata[0].intFirstPassThroughTimeRange,carddata[0].intSecondPassThroughTimeRange ,carddata[0].intThirdPassThroughTimeRange);
                    Console.WriteLine( "GWCCardGetUserUniqueIdentifiert = {0}",carddata[0].strUserUniqueIdentifier);
                    Console.WriteLine( "GWCCardGetScramblerCodet = {0}",carddata[0].strScramblerCode);
                    Console.WriteLine( "GWCCardGetUserPasswordCodet = {0}",carddata[0].strUserPasswordCode);
                    Console.WriteLine( "GWCCardFetchFirstDoorNamet = {0},{1},{2}" ,carddata[0].strDoorName1,carddata[0].strDoorName2 ,carddata[0].strDoorName3);
                    Pause();
                    Console.WriteLine( "GWCCardFetchNextDoorAccess = ");
                    for (i = 0; i < 1152; i++)
                    {
                        if (carddata[0].intDoorAccess[i] == 1)
                        {
                            Console.WriteLine( "\t{0}",(i + 1) );
                        }
                    }
                    /*
                    Console.WriteLine("WCard_writeTest = {0}", SYWCardLib.WCard_writeTest(1));
                    Pause();//把卡片移開讀卡機之後再回讀卡機等到BEEP才可以進行下一個動作
                    Console.WriteLine("WCard_readTest = {0}", SYWCardLib.WCard_readTest());
                    Pause();
                    Console.WriteLine("WCard_writeTest = {0}", SYWCardLib.WCard_writeTest(0));
                    Pause();
                    Console.WriteLine("WCard_readTest = {0}", SYWCardLib.WCard_readTest());
                    Pause();
                    SYWCardLib.WCard_close();
                    */
                }
                else
                {
                    Console.WriteLine("Detect Reader Fail...{0}", state);
                }
            }
            SYWCardLib.WCard_close();
            Pause();
        }
    }
}
