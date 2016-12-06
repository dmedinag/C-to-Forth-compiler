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
        d = 2 ;
        primo = 1 ;
        while (primo && d<i) { 
            p = i % d ;
            if (p == 0) {
                primo = 0 ;
            }
            d = d + 1 ;
        }

        if (primo) {
            printf ("%d  ", i) ;
        }

//@  ." - " 
//        i = i + 1 ;
    }
}

//@ main


