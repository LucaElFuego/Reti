#include <stdio.h>

int main(void) 
{
    int v[] = {33, 44, 55};
    int i;

    for (i = 0; i < 3; i++) {
        //printf("v[%d]: %d indirizzo: %p\n", i, v[i], &v[i]); //Gli indirizzi hanno un gap di 4 byte, siccome gli interi occupano quello spazio
        printf("v[%d]: %d indirizzo: %p\n", i, *(v+i), &(v+i));
    }
    
    //printf("\nPrima cella: %d con indirizzo %p\n", v[0], &v[0]);

    int *pv = v;
    printf("\nPrima cella: %d con indirizzo %p\n", *pv, pv);
    pv++;
    printf("Prima cella: %d con indirizzo %p\n", *pv, pv);
    return 0;
}