#include <stdio.h>

int primo ;
int n  ;
int m ;

main ()
{
    int d ;
    int i ;
    int p ;

    i = 1 ; 
    n = 1 ; 
    m = 100 ;
    
    for (i = 1 ; i <= m ; i=i+1) {  
        primo = 1 ;
        for (d = 2 ; d < i ; d=d+1) {
            if (i % d == 0) {
                primo = 0 ;
            }
        }

        if (primo) {
            printf ("%d  ", i) ;
        }

//@  ." - " 
//        i = i + 1 ;
    }
}

//@ main


