#include <stdio.h>
#include <stdlib.h>
/*
Figure 2.7 ¡V C Language implementation of the CRC calculation
*/
unsigned int calcrc16( unsigned char * dataP, int n )
{
	unsigned char i, j; // Byte counter, bit counter
	unsigned int crc16; // calculation
	crc16 = 0x0000; // PRESET value
	for (i = 0; i < n; i++) // check each Byte in the array
	{
		crc16 ^= *dataP++;
		for (j = 0; j < 8; j++) // test each bit in the Byte
		{
			if(crc16 & 0x0001 )
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
int main()
{
    unsigned char data[6];
    //string input = "00 06 80 01 00 03";
    data[0]=00;
    data[1]=06;
    data[2]=16*8;
    data[3]=01;
    data[4]=00;
    data[5]=02;
    unsigned int CRC16= calcrc16( data, 6 );
    printf("%d\n%X",CRC16,CRC16);
    return 0;
}
