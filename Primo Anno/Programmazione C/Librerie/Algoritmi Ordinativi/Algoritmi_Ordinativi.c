#include "Algoritmi_Ordinativi.h"
#include <stdio.h>

void scambia(int *a, int *b)
{
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

void insertion_sort(int *Array, int len)
{

    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Array[i] < Array[j])
            {
                int tmp = Array[i];
                Array[i] = Array[j];
                Array[j] = tmp;
            }
        }
    }
}

void selection_sort(int *Array, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int indice_min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (Array[j] < Array[indice_min])
            {
                indice_min = j;
            }
        }
        if (indice_min != i)
        {
            scambia(&Array[i], &Array[indice_min]);
        }
    }
}

void bubble_sort(int *Array, int n)
{
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                scambia(&Array[j], &Array[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void stampa_array(int *Array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}