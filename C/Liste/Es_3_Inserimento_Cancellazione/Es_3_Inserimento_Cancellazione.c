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
int Conta_Nodi(Dipendenti* head);

Dipendenti* Aggiungi_in_Testa(char cogn[MAX], int eta, Dipendenti* testa);
Dipendenti* Aggiungi_in_Coda(char cogn[MAX], int eta, Dipendenti* testa);
Dipendenti* Aggiungi_a_Posizione(char cogn[MAX], int eta, Dipendenti* testa, int pos);
Dipendenti* Cancella_a_Posizione(Dipendenti* testa, int pos);

int main (void) {
    srand(time(NULL));

    Dipendenti* testa = NULL;

    //Inserimento in testa
    testa = Aggiungi_a_Posizione("Rossi", 34, testa, 2);
    testa = Aggiungi_a_Posizione("Bianchi", 18, testa, -10);
    testa = Aggiungi_a_Posizione("Gialli", 69, testa, 2);
    testa = Aggiungi_a_Posizione("Verdi", 43, testa, 20);

    Stampa_Lista(testa);
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

    if(head == NULL)
        printf("Lista VUOTA\n");
    else
    {
        printf("\nLista dipendenti\n");
        printf("Matr.\tCognome\t\tEta'\n");
        while(lista != NULL)
        {
            printf("%s\t%s\t\t%d\n", 
                    lista->matricola, lista->cognome, lista->eta);
            lista = lista->next;
        }
    }
}

int Conta_Nodi(Dipendenti* head) {
    int cont = 0;

    while(head != NULL)
    {
        cont++;
        head = head->next;
    }

    return cont;
}

Dipendenti* Aggiungi_in_Testa(char cogn[MAX], int eta, Dipendenti* testa) {
    Dipendenti* new = Crea_Dipendente(cogn, eta);
    new->next = testa;
    return new;
}

Dipendenti* Aggiungi_in_Coda(char cogn[MAX], int eta, Dipendenti* testa) {
    Dipendenti* new = Crea_Dipendente(cogn, eta);
    if (testa == NULL) {
        testa = new;
    }
    else
    {
        Dipendenti* aus = testa;
        while (aus->next != NULL)
        {
            aus = aus->next;
        }
        aus->next = new;
    }
    return testa;
}

Dipendenti* Aggiungi_a_Posizione(char cogn[MAX], int eta, Dipendenti* testa, int pos) {
    Dipendenti* new;
    if (testa == NULL || pos<= 1) {
        testa = Aggiungi_in_Testa(cogn, eta, testa);
    }
    else
    {
        if (pos >= Conta_Nodi(testa)) {
            testa = Aggiungi_in_Coda(cogn, eta, testa);
        }
        else {
            new = Crea_Dipendente(cogn, eta);
            int cont = 1;
            Dipendenti* aus = testa;
            while (aus->next != NULL && pos-1 != cont)
            {
                aus = aus->next;
            }
            new->next = aus->next;
            aus->next = new;
        }
    }
    return testa;
}

Dipendenti* Cancella_a_Posizione(Dipendenti* testa, int pos) {
    Dipendenti* new;
    if (pos<= 1) {
        testa = testa->next;
    }
    else
    {
        Dipendenti* aus = testa;
        if (pos >= Conta_Nodi(testa)) {
            
        }
        else {
            int cont = 1;
            while (aus->next != NULL && pos-1 != cont)
            {
                aus = aus->next;
            }
            Dipendenti* canc = aus->next;
            aus->next = canc->next;
        }
    }
    return testa;
}