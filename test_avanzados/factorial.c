#include <stdio.h>


main ()
{
    int resultado ;
    int n ;

    n=7 ;
    resultado=1 ;

    while (n>1) {
        resultado*=n;
        n--;

//@ ." n=" n_main @ .
//@ ." resultado=" resultado_main @ . cr

    }
    printf("%d\n", resultado) ;
}

//@ main cr
