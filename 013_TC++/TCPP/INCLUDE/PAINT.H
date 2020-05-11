/* Chessbox software system Version 1.0,  January 28 1989 */
/* This software system is copyrighted by Ho, Hong-Fa. */
/* All rights reserved worldwide. No part of this software may be reproduced,
   transmitted, transcribed, stored in any retrieval system by any means
   without permission.
*/
unsigned char board[240];
unsigned char pos[34];
extern unsigned char piece[34][120];
extern void piecemove(int source,int d_position);
extern void initchess(int pic_inverse,int page,int hide_paint);
extern void printboard(int pce_inverse);
extern void clearboard(void);
extern void closechess(void);
extern int readuser(int *user_pce,int *d_position);
extern void print(char *string,int line_feed);
extern void swappiece(int source,int *shape);

