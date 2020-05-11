#include <stdio.h>
#include <stdlib.h>

#define ROW               2
#define COL                4

// ==================================== 
// main function
int main(int argc, char**argv)
{        
        int i=0, j=0;
        int **ptr2 = NULL;

        // 生成一維指標陣列
        ptr2 = (int**)malloc(sizeof(int*)*ROW);

        // 每個指標陣列再生成整數陣列
        for(i=0; i<ROW; i++)
        {
            ptr2[i] = (int*)malloc(sizeof(int)*COL);
        }
        
        // write
        int cnt = 0;
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL; j++)
            {
                ptr2[i][j] = cnt++;
            }
        }

        // read value and address
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL; j++)
            {
                printf("ptr2[%d][%d]=%d(%0X)\n", i, j, ptr2[i][j], &ptr2[i][j]);
            }
        }

        // 釋放指標陣列
        for(i=0; i<ROW; i++) free(ptr2[i]);

        // 釋放指標
        free(ptr2);

        return 0;
}