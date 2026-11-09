#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

//Prototipi
void Visualizza_Menu();
void Es_1();
int Verifica_Palindroma(char* str);
void Es_2();
void Inverti_Stringa(char* inizio);
void Es_3();
void Ottieni_Consonanti_Vocali(int* consonanti, int* vocali);
void Es_6();
void Concatena_Stringhe(char* str1, char* str2);
void Es_7();
void Genera_Stringa_Casuale(char* str, int* dim, char min, char max);
void Converti_In_Maiuscolo(char* str, int* dim);

int main(void) 
{
    int* scelta;

    scelta = (int*) malloc(sizeof(int));
    srand(time(NULL));

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

            case 3:
                Es_3();
                break;

            case 6:
                Es_6();
                break;

            case 7:
                Es_7();
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
    printf("7. Carica stringa casuale da A a Z e straformare il contenuto in maiuscolo\n");
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

    //Inverti_Stringa(str);

    char* fine = str + strlen(str - 1);

    printf("La stringa invertita e': ");
    for (;fine != str; fine--)
    {
        printf("%c", *fine);
    }
    printf("%c\n", *str);
    
    //printf("La stringa invertita è: %s\n", str);
    free(str);
    free(fine);
}

void Inverti_Stringa(char* inizio) {
    char* fine = inizio + (strlen(inizio) - 1);
    char* aus = (char*) malloc(sizeof(char));

    while (inizio < fine)
    {
        *aus = *inizio;
        *inizio = *fine;
        *fine = *aus;

        inizio++;
        fine--;
    }
}

void Es_3() {
    char* str = (char*) malloc(sizeof(char) * MAX);
    int* consonanti = (int*) malloc(sizeof(int));
    int* vocali = (int*) malloc(sizeof(int));

    printf("Inserisci stringa: ");
    gets(str);
    str = realloc(str, sizeof(char) * (strlen(str)) + 1);

    Ottieni_Consonanti_Vocali(consonanti, vocali);

    printf("Abbiamo %d consonanti e %d vocali in questa stringa", consonanti, vocali);
    free(str);
    free(consonanti);
    free(vocali);
}

void Ottieni_Consonanti_Vocali(int* consonanti, int* vocali) {

}

void Es_6() {
    char* str1 = (char*) malloc(sizeof(char) * MAX);
    char* str2 = (char*) malloc(sizeof(char) * MAX);

    printf("Inserisci stringa 1: ");
    gets(str1);
    //str1 = realloc(str1, sizeof(char) * (strlen(str1)) + 1);

    printf("Inserisci stringa 2: ");
    gets(str2);

    str2 = realloc(str2, sizeof(char) * (strlen(str2)) + 1);
    str1 = realloc(str1, sizeof(char) * (strlen(str1) + strlen(str2) + 1));

    Concatena_Stringhe(str1, str2);
    printf("Stringa concatenata: %s\n", str1);

    free(str1);
    free(str2);
}

void Concatena_Stringhe(char* str1, char* str2) {
    char* inizio = str1 + strlen(str1); //ci mettiamo sul tappo
    
    for (; *str2 != '\0'; inizio++, str2++)
    {
        *inizio = *str2;
    }
    
    *inizio = '\0';
}

void Es_7() {
    int* dim = (int*) malloc(sizeof(int));

    printf("Inserisci dimensione stringa: ");
    scanf("%d", dim);
    
    char* str = (char*) malloc(sizeof(char) * ((*dim) + 1));

    *(str + *dim) = '\0';

    Genera_Stringa_Casuale(str, dim, 'a', 'z');
    printf("Stringa finale %s", str);
    free(dim);
}


void Genera_Stringa_Casuale(char* str, int* dim, char min, char max) {
    int* i = (int*) malloc(sizeof(int));
    for (*i = 0; *i < *dim; (*i)++)
    {
        *(str + *i) = rand() % ((max - min + 1) + min);
    }
    
    Converti_In_Maiuscolo(str, dim);
}

void Converti_In_Maiuscolo(char* str, int* dim) {
    //32 è la differenza sul codice Ascii per maiuscole e minuscole
    const int n_conversione = 'a' - 'A'; //Si ricava facendo differenza tra qualunque minuscola con la rispettiva maiuscola
    int* i = (int*) malloc(sizeof(int));
    for (*i = 0; *i < *dim; (*i)++)
    {
        if (*str >= 'a' && *str <= 'z') {
            *(str + *i) = *(str + *i) - n_conversione;
        }
        else
        {
            printf("Valore non valido per conversione in maiuscolo!\n");
        }
        
    }
}