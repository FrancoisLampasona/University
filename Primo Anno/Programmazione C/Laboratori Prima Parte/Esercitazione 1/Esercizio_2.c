#include <stdio.h>


int main (void){
    int a;

    printf("Inserisci una numero intero:");
    scanf("%d",&a);

    if (a<0)
    {
        a=-a;
    }
    
    printf("Il numero inserito e' : %d",a);
}