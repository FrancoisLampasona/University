#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void storemin(const int *a, const size_t n, int *min)
{
    if (n == 0)
    {
        return;
    }
    if (*a < *min)
        *min = *a;
    storemin(a + 1, n - 1, min);
}

int main(void)
{
    int a[] = {1, 8, -3, 15, -116, 91, -30, -92};
    int m = INT_MAX;
    storemin(a, 8, &m);
    printf("min=%d\n", m);
}