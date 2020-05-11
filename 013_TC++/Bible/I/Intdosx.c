
/*                          */
/* Program Name : intdosx.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int delete_file(char far *filename);

void main()
{
    int err;

    clrscr();
    err = delete_file("NULLFILE");
    if (!err)
       printf("Delete NULLFILE success !\n");
    else
       printf("Delete NULLFILE failed !\n");
}

int delete_file(char far *filename)
{
    union REGS regs; struct SREGS sregs;
    int ret;
    regs.h.ah = 0x41;                 /* delete file */
    regs.x.dx = FP_OFF(filename);
    sregs.ds = FP_SEG(filename);
    ret = intdosx(&regs, &regs, &sregs);

    /* if carry flag is set, there was an error */
    return(regs.x.cflag ? ret : 0);
}
