/*****************************************************************/
/**  CH_arraytype﹚竡**/
/**  把计flag璝0玥valueSi,璝1玥铬臘 **/
/**  把计value**/
/*****************************************************************/
typedef struct ch_array{
  int flag;
  int value;
}cha;
/*******************************************************************************/ 
/**  繬ひ耙じ﹃е硉秆絏 **/
/**  把计dˇ**/
/**  把计块Huffman array**/
/**  把计块CH array**/
/*******************************************************************************/

int Huffman_Decode(int d_prom,int *Huf_array,cha *CH_array)
{
  int i,j,code_ptr=0,array_ptr;
  /*﹍てcode_ptr*/
  code_ptr=d_prom;
  /*﹍てarray_ptr*/
  for(i=0;i<d_prom;i++)
    array_ptr=array_ptr+2*Huf_array[i];
  /*秆絏癹伴*/
  while(CH_array[array_ptr].flag!=0){
    array_ptr=array_ptr+CH_array[array_ptr].value;
    /*オ*/
    if(Huff_array[code_ptr]!=0)
      array_ptr++;
      /*璝絏=ˇ1ˇ,玥*/
      code_ptr++;
    /*じ*/
  }
  return CH_array[array_ptr].value;
}
