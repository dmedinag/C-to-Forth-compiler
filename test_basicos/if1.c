#include <stdio.h>

// BORRAR LOS IFS incorrectos

int b ;

main ()
{
	int a ;

	a = 1 ;

	// if (a==1)
	// 	puts ("El texto se imprime A") ;
//@ cr

	if (a==1) {
		puts ("El texto se imprime B") ;
	}
//@ cr

	if (a==1) {
		puts ("El texto se imprime C") ;
	} else {
		printf ("%d\n", a) ;
	}
//@ cr

	// if (a==1) 
	// 	puts ("El texto se imprime D") ;
	// else
	// 	printf ("%d %d\n", a, a) ;

//@ cr
}

//@ main
