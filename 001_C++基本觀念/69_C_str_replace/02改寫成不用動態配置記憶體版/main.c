#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
   char* pchrsource = "My English Name Jash.liao";
   char pchrresult[1000];//char* pchrresult;
   char* pchrfind="Name";
   char* pchrrep="Name is";
   char* pchrformer;
   char* pchrlocation;
   int intrep;// 替換文字的長度
   int intfind;// 搜尋文字的長度
   int intlength;// 結果文字的長度
   int intgap=0;// 偏移量

   intfind=strlen(pchrfind);// 搜尋文字的長度
   intrep=strlen(pchrrep);// 替換文字的長度
   intlength=strlen(pchrsource)+1;// 結果文字的長度

   //pchrresult = (char*)malloc(sizeof(char) * intlength);// 配置記憶體
   strcpy(pchrresult, pchrsource);//複製文字

   pchrformer=pchrsource;
   pchrlocation= strstr(pchrformer, pchrfind);//搜尋文字出現的起始位址指標

   while(pchrlocation!=NULL){

       intgap+=(pchrlocation - pchrformer);//定位偏移量
       pchrresult[intgap]='\0';// 將結束符號定在搜尋到的位址上

       intlength+=(intrep-intfind);//計算新的長度
       //pchrresult = (char*)realloc(pchrresult, intlength * sizeof(char));// 變更記憶體空間
       strcat(pchrresult, pchrrep);//串接在結果後面
       intgap+=intrep;//更新偏移量


       pchrformer=pchrlocation+intfind;//更新尚未被取代的字串的位址

       strcat(pchrresult, pchrformer);//將尚未被取代的文字串接在結果後面


       pchrlocation= strstr(pchrformer, pchrfind);//搜尋文字出現的起始位址指標
   }

   pchrresult[strlen(pchrresult)]='\0';

   printf( "source: '%s'\n", pchrsource );
   printf( "result: '%s'\n", pchrresult);

   //free(pchrresult);
   return 0;
}
