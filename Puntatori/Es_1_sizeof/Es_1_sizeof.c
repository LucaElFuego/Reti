#include <stdio.h>

//Comando per compilare e aggiornare il .exe senza crearne uno nuovo
//gcc Es_1_sizeof.c -o Es_1_sizeof.exe
//Installa Code Runner per runnare il codice (Devi configuarare gcc prima)

int main(void) 
{
    int i; //0x005 primo indirizzo
    i = 10;
    char c = 'c'; //0x00A

    int *pi; // 0x01B

    int v[] = {55, 66, 77};

    printf("La variabile i occupa %d byte\n", sizeof(i));
    printf("Il tipo char occupa %d byte\n", sizeof(char));
    printf("La variabile pi* occupa %d byte\n", sizeof(pi));

    printf("L'indirizzo di i e' %p e contiene %d\n",&i, i);
    printf("L'indirizzo di c e' %p e contiene %c\n",&c, c);
    printf("L'indirizzo di pi e' %p e contiene %p\n",&pi, pi); //Se non dai alcun valore al puntatore, il valore che viene restituito punta a vuoto
    printf("L'indirizzo di v[2] e' %p e contiene %d\n",&v[2], v[2]);
    return 0;
}