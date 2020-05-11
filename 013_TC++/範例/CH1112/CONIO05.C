/* program conio05.c */
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
	unsigned freq,status,ratio;
	cprintf("Enter frequency in Hz (100-1500) : ");
	cscanf("%hu",&freq);
	/* get 8255 chip status */
	status = inportb(Chip_8255);
	/* put timer in oscillator mode */
	outportb(Timer_mode,Timer_osc);
	ratio = (unsigned)(Timer_freq/freq);
	outportb(Timer_count,(ratio & 0xff));
	outportb(Timer_count,((ratio >> 8) & 0xff));
	cprintf("\r\n Hit any key to exit ");
  /* turn on speaker */
	outportb(Chip_8255,(status | 3));
	while ( ! kbhit() )	;
	/* turn off speaker */
	status = inportb(Chip_8255);
	outportb(Chip_8255,(status & 0));
}
