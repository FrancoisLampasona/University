#include <stdio.h>

int main (void){

    int value=2;

   // Per le variabili int :

    for (int i = 0; value >= 0 ; ++i) {
        printf(" %d",value);
        value=value*2 ;
    }

    printf("\n Il massimo valore possibile per una variavile int e' : %d\n",value-1);

    // Per le variabili long :

    long b=2;

    for (int i = 0; b >= 0 ; ++i) {
        printf(" %d",b);
        b=b*2 ;
    }
    printf("\n Il massimo valore possibile per una variavile long e' : %d",b-1);

 /*   // Per le variabili unsigned int : (tenere conto del complemento a 2 da finire)

    unsigned int c=2;

    for (int i = 0; c >= 0 ; ++i) {
        printf(" %d",c);
        c=c*2 ;

    }
    printf("\n Il massimo valore possibile per una variavile long e' : %d",c-1);
    */

}