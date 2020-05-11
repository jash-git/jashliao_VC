#include <iostream>
#include <cstdio>
using namespace std;
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
/*
    //int 轉 byte
    unsigned char bytes[4];
    unsigned long n = 0x5555;

    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
    printf("%02X %02X %02X %02X\n", bytes[0], bytes[1], bytes[2], bytes[3]);
*/
int main()
{
    unsigned char arr[] = {0x80,0x15,0x1,0x8,0x30,0x33,0x31,0x35,0x31,0x30,0x33,0x30,0x2,0x8,0x30,0x33,0x35,0x31,0x2d,0x33,0x32,0x31,0x30,0xe};
    unsigned int sum =0;
    unsigned char checksum[2];
    for(int i=0;i<sizeof(arr);i++)
    {
        sum+=arr[i];
    }
    checksum[0] = (sum >> 8) & 0xFF;
    checksum[1] = sum & 0xFF;
    printf("%02X %02X\n", checksum[0], checksum[1]);
    cout<<sizeof(arr)<<endl;//計算陣列長度
    cout << "Hello world!" << endl;
    Pause();
    return 0;
}
