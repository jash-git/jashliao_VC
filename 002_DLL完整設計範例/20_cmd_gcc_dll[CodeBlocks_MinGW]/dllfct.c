   #include <stdio.h>
   #include "dllfct.h"
	void Pause()
	{
		printf("Press Enter key to continue....");
		fgetc(stdin);
	}
   EXPORT void tstfunc (void)
   {
      printf ("Hello\n");
	  Pause();	  
   }