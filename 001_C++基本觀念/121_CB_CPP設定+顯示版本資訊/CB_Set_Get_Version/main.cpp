#include <iostream>
#include <cstdio>
#include "version.h"

using namespace std;
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    cout << "Hello world!" << endl;
    cout << "ProductVersion" << RC_FILEVERSION_STRING<< endl;
    Pause();
    return 0;
}
