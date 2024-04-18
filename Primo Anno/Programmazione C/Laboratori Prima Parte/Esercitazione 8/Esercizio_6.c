#include <stdio.h>

int main (void){

    int c,app,flag=0,dopp=0;

    do {

        c=getchar();

        if(flag==0) {

            if (dopp!=c) {

                if (c == 'c') {
                    flag = 1;
                    app = c;
                } else {
                    putchar(c);
                    dopp = c;
                }
            }else{
                flag=0;
            }

        }else if(flag == 1)

        {
            if(c=='h')
            {
                putchar('k');
                flag=0;
            }else if (c=='c'){
               flag=1;
            }else{
                putchar(app);
                putchar(c);
                flag=0;
            }
        }

    } while (c!=EOF);

}