#include <stdio.h>

int main (void){
    int valore, count=0;

do
{
    printf("Inserisci un numero : ");
    scanf("%d",&valore);

    count += valore;

} while (valore!=0);

printf("La somma dei valori inseriti e' : %d\n",count);

}