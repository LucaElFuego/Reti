#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct dipendente
{
    char matricola[5];
    char cognome[MAX];
    int eta;
    struct dipendente *next; //Puntatore al nodo successivo
} Dipendenti;

Dipendenti* Crea_Dipendente(char cogn[MAX], int eta);
void Stampa_Lista(Dipendenti* head);

int main (void) {
    Dipendenti* head;
    Dipendenti *n1, *n2, *n3;
    srand(time(NULL));

    //Creazione di nodi scollegati
    n1 = Crea_Dipendente("Rossi", 35);
    n2 = Crea_Dipendente("Bianchi", 42);
    n3 = Crea_Dipendente("Verdi", 28);

    n1->next = n2;
    n2->next = n3;
    head = n1;

    Stampa_Lista(head);

    free(n1);
    free(n2);
    free(n3);
    return 0;    
}

Dipendenti* Crea_Dipendente(char cogn[MAX], int eta) {
    Dipendenti* nodo = (Dipendenti*) malloc(sizeof(Dipendenti));
    char matr[5];
    int i;

    //Carico casualmente matricola
    //Es. AZ09
    for (i = 0; i < 2; i++) {
        matr[i] = 'A' + (rand() % ('Z' - 'A' + 1));
    }

    for (i = 2; i < 4; i++) {
        matr[i] = '0' + (rand() % 10);
    }

    matr[4] ='\0';

    strcpy(nodo->matricola, matr);
    strcpy(nodo->cognome, cogn);
    nodo->eta = eta;
    nodo->next = NULL;
    return nodo;
}

void Stampa_Lista(Dipendenti* head) {
    Dipendenti* lista = head;

    if (head == NULL) {
        return;
    }
    else 
    {
        printf("\nLista Dipendenti\n");
        while (lista != NULL)
        {
            printf();
            lista = lista->next;
        }
        
    }
}