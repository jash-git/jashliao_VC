#include <stdio.h>
#include "RungeKutta_TwoOrder.h"
void main(void)
{
	RungeKutta_TwoOrder twoorder;
	twoorder.initial(1.0f,7.0f,25.0f,0.0f,25.0f,0.01f);
	
	printf("test");
}