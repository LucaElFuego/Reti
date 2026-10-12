#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//Prototipi
void Visualizza_Menu();
void Es_1();
int Verifica_Palindroma(char* str);
void Es_2();
void Es_6();
void Concatena_Stringhe(char* str1, char* str2);

int main(void) 
{
    int* scelta;

    scelta = (int*) malloc(sizeof(int));

    do {
        Visualizza_Menu();
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

            case 6:
                Es_6();
                break;
            
            default:
                printf("Input non valido!\n");
                break;
        }
    }while(*scelta != 0);

    return 0;
}


void Visualizza_Menu() {
    printf("ESERCITAZIONE - PUNTATORI \n\n");
    printf("1. Verifica se una stringa e' palindroma\n");
    printf("2. Inverti una stringa\n");
    printf("3. Conta vocali e consonanti in una stringa\n");
    printf("4. Cerca valore in un vettore\n");
    printf("5. Calcola minimo, massimo e media di un vettore\n");
    printf("6. Concatena 2 stringhe\n");
    printf("\n0. Esci\n");
}

void Es_1() {
    char* str = (char*) malloc(sizeof(char) * MAX);

    printf("Inserisci stringa: ");
    gets(str); //scanf per stringhe che prende tutto, anche gli spazi
    str = realloc(str, sizeof(char) * (strlen(str)) + 1); //strlen non conta il tappo quindi facciamo +1

    if (Verifica_Palindroma(str) == 1) {
        printf("La stringa %s e' palindroma");
    }
    else {
        printf("La stringa %s non e' palindroma");
    }
    free(str);
}

int Verifica_Palindroma(char* str) {
    char* inizio;
    char* fine;
    inizio = str;
    fine = str + (strlen(str) - 1);

    while (inizio < fine && (*inizio == *fine))
    {
        inizio++;
        fine--;
    }
    
    if (*inizio == *fine) {
        return 1;
    }
    free(inizio);
    free(fine);
    return 0;
}

void Es_2() {
    char* str = (char*) malloc(sizeof(char) * MAX);

    printf("Inserisci stringa: ");
    gets(str);
    str = realloc(str, sizeof(char) * (strlen(str)) + 1);

    char* fine = str + strlen(str - 1);

    printf("La stringa invertita e': ");
    while (str < fine)
    {
        printf("%c", *fine);
        fine--;
    }
    printf("%c\n", *str);
    
    free(str);
    free(fine);
}

void Es_6() {
    char* str1 = (char*) malloc(sizeof(char) * MAX);

    printf("Inserisci stringa 1: ");
    gets(str1);
    str1 = realloc(str1, sizeof(char) * (strlen(str1)) + 1);

    
    char* str2 = (char*) malloc(sizeof(char) * MAX);

    printf("Inserisci stringa 2: ");
    gets(str2);
    str2 = realloc(str2, sizeof(char) * (strlen(str2)) + 1);

    Concatena_Stringhe(str1, str2);

    free(str1);
    free(str2);
}

void Concatena_Stringhe(char* str1, char* str2) {
    str1 = realloc(str1, sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    char* inizio = str1 + strlen(str1); //ci mettiamo sul tappo

    //*inizio = *str2;
}