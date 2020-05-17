using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS_crc16_CCITT_TABLE
{
    public class Crc16
    {
        //Figure 2.7 – C Language implementation of the CRC calculation
        public static long calcrc16(byte[] dataP)
        {
	        int i, j; // Byte counter, bit counter
	        long crc16; // calculation
	        crc16 = 0000; // PRESET value
            for (i = 0; i < dataP.Length; i++) // check each Byte in the array
	        {
                crc16 ^= dataP[i];
		        for (j = 0; j < 8; j++) // test each bit in the Byte
		        {
                    if (crc16%2==1)//(crc16 & 0x0001 )
			        {
				        crc16 >>= 1;
				        crc16 ^= 0x8408; // POLYNOMIAL x^16 + x^12 + x^5 + 1
			        }
			        else
			        {
				        crc16 >>= 1;
			        }
		        }
	        }
	        return( crc16 ); // returns calculated crc (16 bits)
        }
    }
}
