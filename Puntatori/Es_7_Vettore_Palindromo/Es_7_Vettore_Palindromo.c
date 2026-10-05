#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

//Dato un vettore di interi grande n (chiesto in input)
//a. Caricare il vettore con valori casuali (1-10)
//b. Dire se è palindromo

void Carica_Vettore(int *v, int *dim);
void Stampa_Vettore(int *v, int *dim);
int Controlla_Palindromo(int *v, int *dim);

int main(void) 
{
    int *pv;
    int *dim;
    srand(time(0));

    printf("Inserisci dimensione array: ");
    dim = (int*) malloc(sizeof(int));
    scanf("%d", dim);

    //Allocazione spazio in memoria per array
    pv = (int*) malloc(sizeof(int) * (*dim));

    Carica_Vettore(pv, dim);
    Stampa_Vettore(pv, dim);
    if (Controlla_Palindromo(pv, dim) == TRUE) {
        printf("Il vettore è palindromo\n");
    }
    else {
        printf("Il vettore non è palindromo\n");
    }

    return 0;
}

void Carica_Vettore(int *v, int *dim) {
    int *i = (int*) malloc(sizeof(int));
    for(*i = 0; *i < *dim; (*i)++) {
        *(v + *i) = 1 + rand()%10;
    }
}

void Stampa_Vettore(int *v, int *dim) {
    int *i = (int*) malloc(sizeof(int));
    for(*i = 0; *i < *dim; (*i)++) {
        printf("v[%d]: %d\n", *i, *(v + *i));
    }
}


int Controlla_Palindromo(int *v, int *dim) {
    int *i = (int*) malloc(sizeof(int));
    int palindromo = TRUE;
    do {
        if (*(v + *i) == *(v + *dim - *i - 1)) {
            (*i)++;
        }
        else {
            return FALSE;
        }
    } while(*i < *dim && palindromo == TRUE);
    return TRUE;
}