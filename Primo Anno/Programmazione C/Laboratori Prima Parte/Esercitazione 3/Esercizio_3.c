#include <stdio.h>
#define K 10

int main (void){

float a,b,c,d,x;

printf("Inserisci il valore di a , b , c , d :");
scanf("%f%f%f%f",&a,&b,&c,&d);

x = (-d*K)/(a+b*c);

printf("Il risultato della X : %.2f",x);

}