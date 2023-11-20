#include <stdio.h>

int main (void){
    int x1,x2;

    x1=0;
    x2=1;

    for (int i = 0; i < 20; i++)
    {
        x2=x1+x2;
        x1=x2-x1;
        printf("%d ",x1);
    }
    
}