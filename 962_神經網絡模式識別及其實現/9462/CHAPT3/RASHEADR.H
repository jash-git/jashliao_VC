struct rasterfile  {
   int  ras_headstart;    /* Must be 0x1234 */
   int  ras_width;
   int  ras_height;
   int  ras_length; 
   int  ras_headend;      /* Must be 0x5678 */
   } ;                    

