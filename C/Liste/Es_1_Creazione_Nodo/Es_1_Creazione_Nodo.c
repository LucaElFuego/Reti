#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct studente
{
    int matr;
    char cognome[MAX];
    float inf, sis, tpsit;
}Studente;

Studente* Crea_Nodo();
void Stampa_Lista(Studente* nodo);

int main (void) {
    Studente* nodo = NULL;

    nodo = Crea_Nodo();
    Stampa_Lista(nodo);

    free(nodo);
    return 0;
}

Studente* Crea_Nodo() {
    int mat;
    float info, sist, tech;
    char cogn[MAX];

    printf("Matricola: ");
    scanf("%d", &mat);
    fflush(stdin);
    printf("Cognome:");
    gets(cogn);
    printf("Media Informatica: ");
    scanf("%f", &info);
    printf("Media Sistemi: ");
    scanf("%f", &sist);
    printf("Media TPSI: ");
    scanf("%f", &tech);
    
    //Devi usare -> e non . per i campi perché non funziona nella allocazione dinamica
    Studente* studente = (Studente*) calloc(1, sizeof(Studente));
    studente->matr = mat;
    studente->inf = info;
    studente->sis = sist;
    studente->tpsit = tech;
    //studente.cognome = "Rossi"; //NON PUOI FARLO!
    strcpy(studente->cognome, "Rossi");

    return studente;
}

void Stampa_Lista(Studente* nodo) {
    printf("\nSTAMPA STUDENTE\n");
    printf("&d\t%s\t%.2f\t%.2f\t%.2f\n",
        nodo->matr, nodo->cognome, nodo->inf, nodo->sis, nodo->tpsit);
}