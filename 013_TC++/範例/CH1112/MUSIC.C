/* program music.c */
/* demo make sound from speaker */

#include <dos.h>
#include <conio.h>
#define  Timer_freq   1193180L
#define  Timer_count  0x42
#define  Timer_mode   0x43
#define  Timer_osc    0xB6
#define  Chip_8255    0x61
main()
{
      int freq[8]={347,394,435,460,510,570,635,660};
      unsigned status,ratio;
      int i;
      /* get 8255 chip status */
      status = inportb(Chip_8255);
      /* put timer in oscillator mode */
      outportb(Timer_mode,Timer_osc);
      for (i=0;i<8;i++)
      {
	ratio = (unsigned)(Timer_freq/freq[i]);
	outportb(Timer_count,(ratio & 0xff));
	outportb(Timer_count,((ratio >> 8) & 0xff));
	/* turn on speaker */
	outportb(Chip_8255,(status | 3));
	delay(500);
	/* turn off speaker */
	status = inportb(Chip_8255);
	outportb(Chip_8255,(status & 0));
      }
}
