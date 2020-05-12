/****************************************************************/
/* 功能：將黑白影像Image，分成K群，結果儲存於Cluster中     */
/* 參數一：原始黑白影像Image                                */
/* 參數二：分群的結果Cluster                                 */
/* 參數三：分成K群                                         */
/****************************************************************/

void k_means(int Image[M][N], int cluster[M][N], int K)
{
/* Dis:計算單一點到群心的距離 */
/* Min:計算單一點到各個群心的距離中的最小值 */
/* Dm:平均失真度 */
/* Dn:前一回合的平均失真度 */
/* Error:失真臨界值 */
/* Cents:存放各個群心的座標 */
/* NCP:一群所包含的點數 */
/* EN:所有點數總和 */

    
  int i, j, k;
  int **Cents, **tmpcts, *NCP, **data_points;
  long double Error, Dm, Dn, Min, EN, Dis, *lmindis;
            
  /* 計算所有點數 */
  EN = 0;
  for(i = 0; i < M; i++){
    for(j = 0; j < N; j++){
        if(Image[i][j] == 1)
            EN++;
    }
  }

  /* 宣告陣列data_points，用以儲存所有點的位置座標 */
  data_points = new int * [EN];
  for(I = 0; I < EN; i++)
      data_points[i] = new int [2];

  /* 記錄所有點的位置，存於陣列data_points中 */
  int z;
  z = 0;
  for(i = 0; i < M; i++){
    for(j = 0; j < N; j++){
        if(Image[i][j] == 1){
            data_points[z][0] = i;
            data_points[z][1] = j;

            z++;
        }
    }
  }

  /* 宣告陣列Cents，用以儲存群心的位置座標 */
  /* 宣告陣列tmpcts，用以儲存該群所包含的點之座標的加總 */
  Cents = new int * [K + 1];   
  tmpcts = new int * [K + 1];
  for(int i = 1; i <= K; i++){
      Cents[i] = new int [2];
      tmpcts[i] = new int [2];
  }           

  /* 從所有點中任選K個點作為初始群心，並存於陣列Cents中 */
  int v;
  randomize();
  for(i = 1; i <= K; i++){
      v = random(K);

      Cents[i][0] = data_points[v][0];
      Cents[i][1] = data_points[v][1];
  }
    
  /* 宣告陣列NCP，用以儲存各群所包含的點數和 */
  NCP = new int [K+1];
    
  /* 宣告陣列lmindis，用已儲存各群的失真度 */
  lmindis = new long double [K + 1];
      
  Dm = 0x7fffffff;   /* Dm:初始值為無限大 */
  Error = 0.005;
      
  do{
      /* 將所需參數歸零 */
      for(i = 1; i <= K; i++){
          lmindis[i] = 0;

          tmpcts[i][0] = 0;
          tmpcts[i][1] = 0;
          NCP[i] = 0;
      }
        
      /* 計算單一點與各群心的距離，將該點分配給與之距離最近之群心 */
      for(I = 0; I < M; i++){
        for(j = 0; j < N; j++){
            if(Image[i][j] == 1){
                //先算距離再分類
                min = 0x7fffffff;
                for(k = 1; k <= K; k++){
                    Dis = sqrt((I - Cents[k][0])*( I -Cents[k][0])+( j -Cents[k][1])*(                           j -Cents[k][1]))

                    if(Min > Dis){
                        Min = Dis;
                        Cluster[i][j] = k;
                    }
                }
                  
                /* 計算群心到該群各點的距離和(單一群的失真度) */
                T = Cluster[i][j];
                  
                NCP[T]++;
                lmindis[T] += Min;
                  
                tmpcts[T][0] += i;
                tmpcts[T][1] += j;
            }
        }
      }
    
      /* 求出新的群心(mean) */ 
      for(i = 1; i <= K; i++){
          if(NCP[i] > 0){   /* 可能有一群沒分到任何點 */
             Cents[i][0] = tmpcts[i][0]/NCP[i];
             Cents[i][1] = tmpcts[i][1]/NCP[i];
          }
      }

      /* Dm:平均失真度 */
      /* Dn:前一輪的平均失真度 */
      /* Error:失真臨界值 */
      Dn = Dm;
      Dm = 0;
      for(i = 1; i <= K; i++)
          Dm += lmindis[i];

      Dm/=EN;        
  }while( ((Dn - Dm)/Dm) > Error );
}
