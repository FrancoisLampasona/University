#include <stdio.h>

int main (void){
    int a;

    printf("Inserisci un valore intero da tastiera :");
    scanf("%d",&a);

    int flag = 0;
    int indice = 1;

    while (indice<=a)
    {
        if ((a%indice)==0)
        {
            flag++;
        }
        indice++;
    }

    if (flag==2)
    {
        printf("Il numero %d e' primo",a);
    }else{
        printf("Il numero %d non e' primo",a);
    }
    
    

    
}