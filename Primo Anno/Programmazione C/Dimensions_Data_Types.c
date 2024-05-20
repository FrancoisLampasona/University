#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

    char a;
    unsigned char b;
    short int c;
    unsigned short int d;
    int e;
    unsigned int f;
    long int g;
    unsigned long int h;
    float i;
    double j;
    long double k;

    printf("\nTipi di Dato\n\n");

    printf("Char : \n - Valore Massimo : %d  \n - Valore Minimo : %d \n - Byte : %lu  Bit : %lu\n\n", CHAR_MAX, CHAR_MIN, sizeof(char), sizeof(char) * 8);
    printf("Unsigned Char : \n - Valore Massimo : %u \n - Valore Minimo : 0  \n - Byte : %lu  Bit : %lu\n\n", UCHAR_MAX, sizeof(unsigned char), sizeof(unsigned char) * 8);
    printf("Short Int : \n - Valore Massimo : %d  \n - Valore Minimo : %d  \n - Byte : %lu  Bit : %lu\n\n", SHRT_MAX, SHRT_MIN, sizeof(short), sizeof(short) * 8);
    printf("Unsigned Short Int : \n - Valore Massimo : %u  \n - Valore Minimo : 0  \n - Byte : %lu  Bit : %lu\n\n", USHRT_MAX, sizeof(unsigned short), sizeof(unsigned short) * 8);
    printf("Int : \n - Valore Massimo : %d  \n - Valore Minimo : %d  \n - Byte : %lu  Bit : %lu\n\n", INT_MAX, INT_MIN, sizeof(int), sizeof(int) * 8);
    printf("Unsigned Int : \n - Valore Massimo : %u  \n - Valore Minimo : 0  \n - Byte : %lu  Bit : %lu\n\n", UINT_MAX, sizeof(unsigned int), sizeof(unsigned int) * 8);
    printf("Long Int : \n - Valore Massimo : %ld  \n - Valore Minimo : %ld  \n - Byte : %lu  Bit : %lu\n\n", LONG_MAX, LONG_MIN, sizeof(long), sizeof(long) * 8);
    printf("Unsigned Long Int : \n - Valore Massimo : %lu  \n - Valore Minimo : 0  \n - Byte : %lu  Bit : %lu\n\n", ULONG_MAX, sizeof(unsigned long), sizeof(unsigned long) * 8);
    printf("Float : \n - Valore Massimo : %.3e \n - Valore Minimo : %.2e \n - Byte : %lu  Bit : %lu\n\n", FLT_MAX, FLT_MIN, sizeof(float), sizeof(float) * 8);
    printf("Double : \n - Valore Massimo : %.2e  \n - Valore Minimo : %.2e  \n - Byte : %lu  Bit : %lu\n\n", DBL_MAX, DBL_MIN, sizeof(double), sizeof(double) * 8);
    printf("Long Double : \n - Valore Massimo : %.2e  \n - Valore Minimo : %.2e  \n - Byte : %lu  Bit : %lu\n\n", LDBL_MAX, LDBL_MIN, sizeof(long double), sizeof(long double) * 8);

    int unIntero;
    long unLongInt;
    float unFloating;
    double unDoublePrec;

    int *intPtr;
    long *longPtr;
    float *floatPtr;
    double *doublePtr;

    char *charPtr;
    unsigned char *ucharPtr;
    short *shortPtr;
    unsigned short *ushortPtr;
    unsigned int *uintPtr;
    unsigned long *ulongPtr;

    printf("\nPUNTATORI\n");

    printf("intPtr:         %lu bytes (%lu)\n", sizeof(intPtr), sizeof(int *));
    printf("longPtr:        %lu bytes (%lu)\n", sizeof(longPtr), sizeof(long *));
    printf("floatPtr:       %lu bytes (%lu)\n", sizeof(floatPtr), sizeof(float *));
    printf("doublePtr:      %lu bytes (%lu)\n", sizeof(doublePtr), sizeof(double *));
    printf("charPtr:        %lu bytes (%lu)\n", sizeof(charPtr), sizeof(char *));
    printf("ucharPtr:       %lu bytes (%lu)\n", sizeof(ucharPtr), sizeof(unsigned char *));
    printf("shortPtr:       %lu bytes (%lu)\n", sizeof(shortPtr), sizeof(short *));
    printf("ushortPtr:      %lu bytes (%lu)\n", sizeof(ushortPtr), sizeof(unsigned short *));
    printf("uintPtr:        %lu bytes (%lu)\n", sizeof(uintPtr), sizeof(unsigned int *));
    printf("ulongPtr:       %lu bytes (%lu)\n", sizeof(ulongPtr), sizeof(unsigned long *));

    return 0;
}
