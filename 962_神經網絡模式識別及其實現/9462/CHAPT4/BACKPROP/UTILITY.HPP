
int MenuMax[2] = {8,3};
char menu1Txt[8][40] =
       {"1] Set Temperature",     "2] Set ETA",
        "3] Set Alpha",           "4] Set Max Iterations",
        "5] Set Error Tolerance", "6] Load parms from file",
        "7] Set Topology",        "8] Exit"};
char menu2Txt[6][40] =
       {"1] Set Number of Layers","2] Set Neurons/Layer","3] Return","","",""};

int menu(int id){
   int i,rv;
   system("cls");
   for (i=0; i<MenuMax[id]; i++) {
      switch (id) {
         case 0:
            printf("%s\n",menu1Txt[i]);
            break;
         case 1:
            printf("%s\n",menu2Txt[i]);
            break;
         default:;
         } /* endswitch */
      }
   printf("\n==>\n");
   rv=-1;
   while ((rv<1) || (rv>MenuMax[id])){
    while (!kbhit()); rv=(int)getch()-0x30;
    //scanf("%d",&rv);
    }
   return rv;
   }

