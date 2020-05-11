using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.WindowsMediaServices.Interop;
using System.IO;//step 03
namespace MMSConnectIP
{
    class Program
    {
        static void Main(string[] args)
        {
            String StrFileName;
            StrFileName = "MMSIP.txt";
            StreamWriter sw1 = File.CreateText(StrFileName); ;
            sw1.Close();
            WMSServer m_WMSServer;
            m_WMSServer = new WMSServer();
            int playcount;
            int i;
            string strData;
            playcount = m_WMSServer.Players.Count;
            for (i = 0; i < playcount; i++)
            {
                strData = m_WMSServer.Players[i].NetworkAddress;
                StreamWriter FileWrite = File.AppendText(StrFileName);
                FileWrite.WriteLine(strData);
                FileWrite.Close();
            }
        }
    }
}
