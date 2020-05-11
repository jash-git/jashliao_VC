using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Runtime.InteropServices;//USE DLL

namespace SYWCardLib_CS_test
{
    public static class SYWCardLib
    {
        [DllImport("./SYWCardLib.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Add")]
        public static extern double Add(double a, double b);
    }
}
