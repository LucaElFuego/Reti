#include <stdio.h>
#include <stdlib.h>

//Dati 3 numeri interi in input, stmpare in output la media
int main(void) 
{
    printf("Inserire il primo numero: ");
    int *n1 = (int*) malloc(sizeof(int));
    scanf("%d", n1); //Nella scanf basta mettere il nome della variabile perché ci serve il contenuto per avere l'indirizzo

    printf("Inserire il secondo numero: ");
    int *n2 = (int*) malloc(sizeof(int));
    scanf("%d", n2);

    printf("Inserire il terzo numero: ");
    int *n3 = (int*) malloc(sizeof(int));
    scanf("%d", n3);

    printf("\nn1: %d \nn2: %d \nn3: %d", *n1, *n2, *n3);
    
    
    float *media = (float*) malloc(sizeof(float));
    *media = (*n1 + *n2 + *n3)/3;
    free(n1);
    free(n2);
    free(n3);
    printf("\nmedia: %f", *media);
}