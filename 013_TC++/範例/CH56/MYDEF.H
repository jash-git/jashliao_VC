/* program mydef.h */
/* demo personal library set up */

#define true	 				1
#define false 				0
#define t							"true"
#define f							"false"
#define pi						3.14159
#define c_to_f				1.8
#define f_to_c    		0.555556
#define dif						32.0
#define Area(r)	 			2*pi*(r)*(r)
#define g(x)					2*(x)*(x)-4*(x)+5
#define odd(x)				((x) % 2 == 1 ) ? 1 : 0
#define fr(c)					(c)*c_to_f+dif
#define ce(f)					((f)-dif)*f_to_c
#define Is_Lower(c) 	(((c) >= 'a' ) && ((c) <= 'z' )) ? 1 : 0
#define Is_Upper(c) 	(((c) >= 'A' ) && ((c) <= 'Z' )) ? 1 : 0