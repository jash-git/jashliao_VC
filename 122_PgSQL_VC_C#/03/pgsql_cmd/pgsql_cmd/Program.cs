using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Npgsql;

namespace pgsql_cmd
{
    class Program
    {
        static void Main(string[] args)
        {
            string struid;
            string strfilename;
            struid = args[0];
            strfilename = args[1];
            NpgsqlConnection conn;
            object obj;
            conn = new NpgsqlConnection("Server=172.17.254.202;Port=5432;User Id=NabroAdmin;Password=nabro;Database=NabroWebDB;Timeout=50;Encoding=UNICODE;");
            string dcCommand;
            dcCommand = "select img from tuka where uid= ";
            dcCommand = dcCommand + struid;
            NpgsqlCommand dc = new NpgsqlCommand(dcCommand, conn);
            dc.CommandTimeout = 250;
            conn.Open();
            obj = dc.ExecuteScalar();
            Byte[] data;
            data = (byte[])obj;
            FileStream FStream;
            FStream = File.Open("aa.txt", FileMode.Create, FileAccess.Write);
            FStream.Write(data, 0, data.Length);
            FStream.Close();
            conn.Clone();
            ///////////////////////////////////////////////////////////////////
            int i, j;
            int File_len;
            int intResult;
            byte[] dataArray = new byte[3];
            byte writedata;
            string s;
            FStream = File.Open("aa.txt", FileMode.Open);
            File_len = (int)FStream.Length;
            j = 0;
            FileStream myFileW = File.Open(strfilename, FileMode.OpenOrCreate, FileAccess.ReadWrite);
            BinaryWriter myWriter = new BinaryWriter(myFileW);
            for (i = 0; i < File_len; i++)
            {
                dataArray[j] = (byte)FStream.ReadByte();
                j++;
                if (j == 3)
                {
                    j = 0;
                    s = System.Text.Encoding.Default.GetString(dataArray);
                    intResult = Convert.ToInt32(s, 8);
                    writedata = (byte)intResult;
                    myWriter.Write(writedata);
                }
            }
            FStream.Close();
            myWriter.Close();
            myFileW.Close();
        }
    }
}
