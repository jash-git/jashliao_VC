#include <stdio.h>   // FILE...

// get the file size.
long getfilesize(FILE *pFile)
{
        // check FILE*.
        if( pFile == NULL)
        {
                return -1;
        }

        // get current file pointer offset.
        long cur_pos = ftell(pFile);
        if(cur_pos == -1)
        {
                return -1;
        }

        // fseek to the position of file end.
        if(fseek(pFile, 0L, SEEK_END) == -1)
        {
                return -1;
        }

        // get file size.
        long size = ftell(pFile);

        // fseek back to previous pos.
        if(fseek(pFile, cur_pos, SEEK_SET) == -1)
        {
                return -1;
        }

        // deal returns.
        return size;
}
int main()
{
        // open a file.
        FILE *pFile = fopen("c:\\123.bat", "r");
        if(pFile == NULL)
        {
                printf("error.\n");
                return 0;
        }

        // get the file size.
        printf("the file size: %ld bytes\n", getfilesize(pFile));

        // close the file.
        fclose(pFile);

        return 0;
}
