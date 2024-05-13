#include <stdio.h>
#include <math.h>
#define N 4


int main (int argc,const char * argv[]){

    int x[N]={8,3,6,1};
    int y[N]={7,4,5,3};
    float segm=0,min;
    int i;

    if (argc!=6){
        printf("Errore nel passaggio dei parametri\n");
        return 0;
    }

    const char *c=argv[1];
    for (i = 0; i < N; i++) {
            sscanf(argv[i + 2], "%d,%d", &x[i], &y[i]);
    }

    if (*c=='m'){

        for (i = 0; i < N-1; ++i) {
            segm += (float) sqrt(pow(x[i]-x[i+1],2)+ pow(y[i]-y[i+1],2));
        }
        printf("%.2f",segm);

    }else if (*c=='a'){

        segm = (float) sqrt(pow(x[i]-x[i+1],2)+ pow(y[i]-y[i+1],2));
        min=segm;

        for (i = 0; i < N-2; ++i) {
            segm = (float) sqrt(pow(x[i]-x[i+1],2)+ pow(y[i]-y[i+1],2));
            if(min<segm){
                min=segm;
            }
        }

        printf("%.2f",segm);

    }else{
        printf("Passati parametri sbagliati\n");
        return 1;
    }

}