#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

void Visualizza_Menu(int* scelta);
void Es_1();
void Es_2();
void Es_3();

void Carica_Vettore_Int(int* v, int* lunghezza, int min, int max);
void Stampa_Vettore_Int(int* v, int* lunghezza);
void Carica_Multipli(int* v, int* lunghezza, int* x);

void Carica_Vettore_Char(char* v, int* lunghezza, int min, int max);
void Stampa_Vettore_Char(char* v);
void Gnome_Sort(char* v, int* lunghezza);

int main(void) 
{
    int* scelta;

    scelta = (int*) malloc(sizeof(int));
    srand(time(NULL));

    do {
        system("@cls||clear"); //Pulisce la console
        fflush(stdin);
        Visualizza_Menu(scelta);
    }while(*scelta != 0);
    free(scelta);

    return 0;
}

void Visualizza_Menu(int* scelta) {
    printf("--- SIMULAZIONE VERIFICA ---\n");
    printf("1. Svolgi Es 1\n");
    printf("2. Svolgi Es 2\n");
    printf("3. Svolgi Es 3\n");
    printf("0. Esci\n");


    printf("Scelta: ");
    scanf("%d", scelta); //scelta contiene l'indirizzo per la variabile, quindi non ci serve la &
    
    system("@cls||clear"); //Pulisce la console
    fflush(stdin);

    switch (*scelta)
    {
        case 0:
            printf("Chiusura programma...\n");
            break;

        case 1:
            Es_1();
            break;

        case 2:
            Es_2();
            break;

        case 3:
            Es_3();
            break;
        
        default:
            printf("Input non valido!\n");
            getchar();
            break;
    }
}

void Es_1() {
    int* v;
    int* lunghezza = (int*) malloc(sizeof(int));

    do
    {
        printf("Inserire la lunghezza: ");
        scanf("%d", lunghezza);
    } while (*lunghezza <= 0);
    
    v = (int*) malloc(sizeof(int) * (*lunghezza));

    int* x = (int*) malloc(sizeof(int));
    do
    {
        printf("Inserire il numero di cui dovrai vedere i multipli: ");
        scanf("%d", x);
    } while (*x < -100 || *x > 100);

    Carica_Vettore_Int(v, lunghezza, -100, 100);
    Stampa_Vettore_Int(v, lunghezza);
    Carica_Multipli(v, lunghezza, x);

    free(lunghezza);
    free(v);
    free(x);
    getchar();
}

void Carica_Vettore_Int(int* v, int* lunghezza, int min, int max) {
    int* i = (int*) malloc(sizeof(int));

    for (*i = 0; *i < *lunghezza; (*i)++)
    {
        *(v + (*i)) = (rand() % (max - min + 1)) + min;
    }
    free(i);
}

void Stampa_Vettore_Int(int* v, int* lunghezza) {
    int* i = (int*) malloc(sizeof(int));
    printf("Stampa vettore:\n");
    for (*i = 0; *i < *lunghezza; (*i)++)
    {
        printf("%d ", *(v + (*i)));
    }
    printf("\n");
    free(i);
}

void Carica_Multipli(int* v, int* lunghezza, int* x) {
    int* i = (int*) malloc(sizeof(int));
    int* v_multipli = (int*) malloc(sizeof(int) * (*lunghezza));
    int* cont = (int*) malloc(sizeof(int));
    *cont = 0;

    for (*i = 0; *i < *lunghezza; (*i)++)
    {
        if(*(v + (*i)) % *x == 0) {
            *(v_multipli + (*cont)) = *(v + (*i));
            (*cont)++;
        }
    }

    v_multipli = (int*) realloc(v_multipli, sizeof(int) * (*cont));
    Stampa_Vettore_Int(v_multipli, cont);

    free(i);
    free(v_multipli);
    free(cont);
}

void Es_2() {
    char* v;
    int* lunghezza = (int*) malloc(sizeof(int));

    do
    {
        printf("Inserire la lunghezza: ");
        scanf("%d", lunghezza);
    } while (*lunghezza <= 0);
    
    v = (char*) malloc(sizeof(char) * (*lunghezza));
    Carica_Vettore_Char(v, lunghezza, 'a', 'z');
    Stampa_Vettore_Char(v);

    Gnome_Sort(v, lunghezza);
    Stampa_Vettore_Char(v);

    free(v);
    free(lunghezza);
    getchar();
}

void Carica_Vettore_Char(char* v, int* lunghezza, int min, int max) {
    int* i = (int*) malloc(sizeof(int));

    for (*i = 0; *i < *lunghezza; (*i)++)
    {
        *(v + (*i)) = (rand() % (max - min + 1)) + min;
    }
    free(i);
}

void Stampa_Vettore_Char(char* v) {
    printf("Stampa vettore:\n");
    for (; (*v) != '\0'; v++)
    {
        printf("%c ", *v);
    }
    printf("\n");
}

void Gnome_Sort(char* v, int* lunghezza) {
    int* index = (int*) malloc(sizeof(int));
    *index = 0;
    char* tmp;
    while (*index < *lunghezza) {
        if (*index == 0) {
            (*index)++;
        }
        if (*(v + *index) >= *(v + *index - 1)) {
            (*index)++;
        } 
            else {
            tmp = (char*) malloc(sizeof(char));
            *tmp = *(v + *index);
            *(v + *index) = *(v + *index - 1);
            *(v + *index - 1) = *tmp;
            (*index)--;
            free(tmp);
        }
    }
    free(index);
}

void Es_3() {
    
}