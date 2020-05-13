#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
//http://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/Simple-Directory-Lister.html
int main (void)
{
    DIR *dp;
    struct dirent *ep;
    FILE *pf=fopen("00_filelist.txt","w");
    dp = opendir ("./");
    if (dp != NULL)
    {
        while (ep = readdir (dp))
        {
            puts (ep->d_name);
            fprintf(pf,"%s\n",ep->d_name);
        }
        (void) closedir (dp);
    }
    else
    {
        perror ("Couldn't open the directory");
    }
    fclose(pf);
    return 0;
}

