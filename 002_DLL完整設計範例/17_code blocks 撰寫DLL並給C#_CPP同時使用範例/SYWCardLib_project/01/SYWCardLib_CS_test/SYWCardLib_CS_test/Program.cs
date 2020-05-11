using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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
            Console.WriteLine("6.8+3.2={0}",SYWCardLib.Add(6.8, 3.2));
            Console.WriteLine("call SYWCardLib.Add finish...");
            Pause();
        }
    }
}
