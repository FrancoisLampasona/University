#include <stdio.h>
#include <math.h>
#define N 4

struct coordinate
{
    int x;
    int y;
};

typedef struct coordinate S_cordinate;

int main(int argc, const char *argv[])
{

    if (argc != 2)
    {
        printf("Errore nel passaggio dei parametri\n");
        return 0;
    }

    S_cordinate coordinate[N];

    coordinate[0].x = 0;
    coordinate[0].y = 0;
    coordinate[1].x = 1;
    coordinate[1].y = 1;
    coordinate[2].x = 2;
    coordinate[2].y = 2;
    coordinate[3].x = 3;
    coordinate[3].y = 3;
    coordinate[4].x = 4;
    coordinate[4].y = 4;

    const char *c = argv[1];
    float segm = 0, min;
    int i;

    if (*c == 'm')
    {

        for (i = 0; i < N - 1; ++i)
        {
            segm += (float)sqrt(pow(coordinate[i].x - coordinate[i + 1].x, 2) + pow(coordinate[i].y - coordinate[i + 1].y, 2));
        }
        printf("%.2f", segm);
    }
    else if (*c == 'a')
    {

        segm = (float)sqrt(pow(coordinate[i].x - coordinate[i + 1].x, 2) + pow(coordinate[i].y - coordinate[i + 1].y, 2));
        min = segm;

        for (i = 0; i < N - 2; ++i)
        {
            segm = (float)sqrt(pow(coordinate[i].x - coordinate[i + 1].x, 2) + pow(coordinate[i].y - coordinate[i + 1].y, 2));
            if (min < segm)
            {
                min = segm;
            }
        }
    }
}