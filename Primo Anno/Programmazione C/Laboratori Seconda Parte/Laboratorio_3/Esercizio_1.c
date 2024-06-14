#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car
{
    char *marca;
    char *modello;
    unsigned int benzina;
    unsigned int capacita;
} Car;

Car *initCar(const char *marca, const char *modello, const size_t capacita)
{
    Car *p = (Car *)malloc(sizeof(Car));

    if (!p)
    {
        printf("Errore allocazione della memoria");
        exit(1);
    }

    p->marca = strdup(marca);
    p->modello = strdup(modello);
    if (!p->marca || !p->modello)
    {
        printf("Errore allocazione della memoria");
        exit(1);
    }
    p->capacita = capacita;
    p->benzina = 0;

    return p;
}

void printCar(const Car *c)
{
    printf("Macchina: %s %s\nCapacita': %d (%d attuali).\n",
           c->marca, c->modello, c->capacita, c->benzina);
}

int compareCar(const Car *c1, const Car *c2)
{
    if (strcmp(c1->marca, c2->marca) == 0 &&
        strcmp(c1->modello, c2->modello) == 0 &&
        c1->capacita == c2->capacita &&
        c1->benzina == c2->benzina)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    Car *ferrarino = initCar("Ferrari", "550", 100);
    Car *ferrarino2 = initCar("Ferrari", "550", 100);
  
    printCar(ferrarino);
    printf("%d", compareCar(ferrarino, ferrarino2));
  
    // Liberiamo la memoria allocata per le auto
    free(ferrarino->marca);
    free(ferrarino->modello);
    free(ferrarino);
    free(ferrarino2->marca);
    free(ferrarino2->modello);
    free(ferrarino2);
}
