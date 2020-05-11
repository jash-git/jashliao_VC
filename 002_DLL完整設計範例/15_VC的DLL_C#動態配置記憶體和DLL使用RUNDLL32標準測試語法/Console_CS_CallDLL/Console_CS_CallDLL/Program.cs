using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Runtime.InteropServices;//USE DLL

namespace ConsoleApplication1
{
    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct Bar
    {

        /// int
        public int id;

        /// char*
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.LPStr)]
        public string name;
    }

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct Data
    {
        public bool bData;
        public int nData;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string strData;
    }

    class Program
    {
        //*
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Test_AllocData")]
        public static extern void Test_AllocData(int size, ref IntPtr ptr);
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Test_FreeData")]
        public static extern void Test_FreeData(IntPtr ptr);
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl,CharSet=CharSet.Ansi, EntryPoint = "GetBar")]
        extern static void GetBar(ref Bar bar);
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SaveByteArray")]
        static extern Int32 SaveByteArray(IntPtr pArray, int nSize);
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Add")]
        static extern double Add(double a, double b);
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Subtract")]
        static extern double Subtract(double a, double b);
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Multiply")]
        static extern double Multiply(double a, double b);
        [DllImport("./c_MathFuncsDll.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Divide")]
        static extern double Divide(double a, double b);
        //*/
    /*
    [DllImport("msvcrt.dll")]
    public static extern int puts(string c);

    [DllImport("msvcrt.dll")] 
    public static extern int _flushall();
     */
        static void Pause()
        {
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }
        static void Main(string[] args)
        {
            ///*
            double d1 = 5.0d;
            double d2 = 20.0d;
            double d3=0.0;
            d3 = Add(d1, d2);
            Console.WriteLine("HELLO WORD");
            Console.WriteLine("d1=" + d1);
            Console.WriteLine("d2=" + d2);
            Console.WriteLine("d3=" + d3);

            //============================
            byte[] array = new byte[16];

            for (int i = 0; i < 16; i++)
            {
                array[i] = (byte)(i + 97);
            }
            
            int size = Marshal.SizeOf(array[0]) * array.Length;
            IntPtr pnt = Marshal.AllocHGlobal(size);
            try
            {
                // Copy the array to unmanaged memory.
                Marshal.Copy(array, 0, pnt, array.Length);
            }
            finally
            {
                // Free the unmanaged memory.
                // Marshal.FreeHGlobal(pnt);
                Console.WriteLine("C# data 2 C++ error");
            }
            SaveByteArray(pnt, array.Length);
            Marshal.FreeHGlobal(pnt);
            //============================
            Bar b = new Bar();
            b.id = 100;
            b.name = "hi bar English";
            GetBar(ref b);
            Console.WriteLine("b's id is " + b.id);
            Console.WriteLine("b's name is " + b.name);

            // testing for retrive struct array buffer from DLL
            IntPtr binary = new IntPtr();
            {
                Data[] ad = new Data[3];
                Test_AllocData(3, ref binary);
                ad[0] = (Data)Marshal.PtrToStructure(binary + Marshal.SizeOf(typeof(Data)) * 0, typeof(Data));
                ad[1] = (Data)Marshal.PtrToStructure(binary + Marshal.SizeOf(typeof(Data)) * 1, typeof(Data));
                ad[2] = (Data)Marshal.PtrToStructure(binary + Marshal.SizeOf(typeof(Data)) * 2, typeof(Data));
                Test_FreeData(binary);

                for (int i = 0; i < 3; i++)
                {
                    Console.WriteLine(string.Format("@AllocData from DLL i={0} n={1} str={2}", i, ad[i].nData, ad[i].strData));
                }
            }

            Console.WriteLine("Call C++ DLL finish");
            //*/
            /*
            puts("Test");
            _flushall();
            */
            Pause();
        }
    }
}
