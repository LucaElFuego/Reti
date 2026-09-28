#include <stdio.h>
#include <stdlib.h>

/*
Memoria statica: Stack
Memoria dinamica: Heap
*/

//malloc(n): n sono i byte da allocare in memoria per le variabili
//Restituisce il primo indirizzo (devi fare cast perché se no da un tipo void*)
//Se in memoria c'era un valore lo mantiene

//calloc(n1, n2): n1 dimensione di vettore, n2 sono i byte da allocare in memoria per le variabili
//Restituisce le stesse cose della malloc
//Inizializza il contenuto in memoria con un valore neutro (0)

//realloc(n1, n2): n1 è la prima cella di memoria del vettore, n2 è la nuova dimensione che dovrà avere il vettore
//Restituiesce n1, perché magari non abbiamo le celle consecutive perché ci stanno valori in mezzo

//è importante fare la free(), per fare in modo che il computer possa utilizzarla dopo che non ci serve più

void Stampa_Vettore(int a[], int dim);

int main(void) 
{
    int v[] = {1, 2, 3, 4, 5};
    int dim_a = 5;

    /*int *dim;
    dim = (int*) malloc(sizeof(int));
    *dim = 5;*/
    //dim = dim_a

    printf("Array statico di %d elementi\n", dim_a);
    Stampa_Vettore(v, dim_a);

    //Allocazione dinamica
    int n_elementi = 10;
    int *p;

    
    //malloc(n_byte)
    printf("\nArray dinamico con malloc di %d elementi\n", n_elementi);
    p = (int*) malloc(sizeof(int) * n_elementi);
    Stampa_Vettore(p, n_elementi);
    free(p); //libero l'area di memoria quando non mi serve più

    
    //calloc(n_celle per tipo, n_byte per singolo tipo)
    printf("\nArray dinamico con calloc di %d elementi\n", n_elementi);
    p = (int*) calloc(n_elementi, sizeof(int));
    Stampa_Vettore(p, n_elementi);

    //ralloc(indirizzo prima cella, nuova dimensione)
    int nuova_dim = 15;
    printf("\nArray dinamico con realloc di %d elementi\n", nuova_dim);
    p = realloc(p, nuova_dim * sizeof(int));
    Stampa_Vettore(p, nuova_dim);

    return 0;
}

void Stampa_Vettore(int a[], int dim) {
    int i;
    for (i = 0; i < dim; i++) {
        printf("v[%d]: %d - %p\n", i, a[i], &a[i]);
    }
}