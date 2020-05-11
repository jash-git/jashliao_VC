#include <stdio.h>
#include <stdlib.h>
/*C語言模擬資料分頁顯示（每頁元素10個）演算法*/
int main()
{
    int num=23;
    int obj[10];
    int all_page=0;//n
    int now_page=2;//1~n
    int i,j;
	
	//計算總頁數
    all_page=num/10;
    if((num%10)>0)
    {
        all_page++;
    }

    //顯示目前狀態變數
	printf("num=%d\n",num);
    printf("all_page=%d\n",all_page);
    printf("now_page=%d\n",now_page);

    //初始化分頁的元件的內容
	for(i=0;i<10;i++)
    {
        obj[i]=-1;
    }

	//按照所在頁數設定對應元素
    if(now_page<=all_page)
    {
        for(i=0;i<10;i++)
        {
            j=i+((now_page-1)*10);
            if(j<num)
            {
                obj[i]=j;
            }
        }
    }
    else
    {
        printf("no page=%d\n",now_page);
    }

	//顯示結果
    for(i=0;i<10;i++)
    {
        printf("obj[%d]=%d\n",i,obj[i]);
    }

    return 0;
}
