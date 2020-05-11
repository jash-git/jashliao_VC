//[C/C++ 基礎] 取代system("pause")的標準函數


void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}