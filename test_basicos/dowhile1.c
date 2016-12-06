#include <stdio.h>

// BORRAR LOS IFS incorrectos

int b ;

main ()
{
	int a ;

	a = 10 ;

	do {
//@  cr
		printf ("%d", a) ;
		if (a % 2) {
			puts (" es impar ") ;
		} else {
			puts (" es par ") ;
		}
		a = a - 1 ;
	} while (a > 0) ;
}

//@ main
