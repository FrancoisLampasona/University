#ifndef ALGORITMI_ORDINATIVI_H
#define ALGORITMI_ORDINATIVI_H

void scambia(int *a, int *b);

void insertion_sort(int *Array, int len);
void selection_sort(int *Array, int len);
void bubble_sort(int *Array, int len);

void merge_sort(int *Array, int left, int right);
void merge(int *Array, int left, int middle, int right);

void quick_sort(int *Array, int first, int last);
int pivot(int *Array, int len);
int partion(int *Array, int first, int last, int pivot);

void stampa_array(int *Array, int len);

#endif