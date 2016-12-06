#include <stdio.h>

int primos [100] ;
int m ;

main ()
{
    int v ;
    int i ;

    m = 100 ;

    i = 1 ; 
    while (i <= m) { 
        primos [i] = 1 ;
        i = i + 1 ;
    }

    i = 2 ; 
    while (i <= m) { 
        v = i * 2 ;
        while (v <= m) { 
            primos [v] = 0 ;
            v = v + i ;
        }
        i = i + 1 ;
    }

    i = 1 ; 
    while (i <= m) { 
        if (primos [i] == 1) {
            printf (" %d  ", i) ;
        }
//@ ." - "
        i = i + 1 ;
    }
}

//@ main
