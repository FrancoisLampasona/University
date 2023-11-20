#include <stdio.h>


int main (void){
    int a , b ;

    printf("Inserisci due numeri interi :");
    scanf("%d%d",&a,&b);

    int sum = a + b;

    printf("La media aritmetica e' : %d",sum/2);
}