#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(char *scelta);
// ES 1
void Carica_Casuale_Char(char *str, int *len, char min, char max);
void Stampa_Array_Char(char *str, int *len);
int *Conta_Char_Alfabeto(char *str, int *len);
// ES 2
void Carica_Casuale_Int(int *arr, int *len, int min, int max);
void Stampa_Array_Int(int *arr, int *len);
void Carica_Positivi_Negativi(int *arr, int *len);
// ES 3
void Cifrario_Cesare(char *str, int *shift);

int main(void)
{
    char *scelta = (char *)malloc(sizeof(char));

    srand(time(NULL));

    do
    {
        menu(scelta);
        switch (*scelta)
        {
        case 'a':
        case 'A':
            /*
            Dato un array di char, caricarlo casualmente con valori compresi tra '!' e '}',
            stamparlo e contare quanti caratteri dell'alfabeto contiene
            */
            {
                int* dim = (int*) malloc(sizeof(int));
                printf("Inserire lunghezza del vettore: ");
                scanf("%d", dim);
                
                char* str = (char*) calloc(*dim, sizeof(char));
                Carica_Casuale_Char(str, dim, '!', '}');
                Stampa_Array_Char(str, dim);
                printf("I caratteri all'interno del vettore sono %d\n", *Conta_Char_Alfabeto(str, dim));

                free(str);
                free(dim);
            }
            break;
        case 'b':
        case 'B':
            /*
            Date un array di interi, caricarlo casualmente con valori compresi tra -20 e 20 e stamparlo.
            Caricare in un array positivi tutti i valori > 0 presenti nell'array originale.
            Caricare in un array negativi tutti i valori < 0 presenti nell'array originale.
            Stampare entrambi gli array risultanti.
            OTTIMIZZARE L'OCCUPAZIONE DI MEMORIA: i due array devono aumentare di dimensione
            solo quando un valore viene caricato
            */
            {
                int* dim = (int*) malloc(sizeof(int));
                printf("Inserire lunghezza del vettore: ");
                scanf("%d", dim);
                
                // = 0 escluso
                int* nums = (int*) calloc(*dim, sizeof(int));
                Carica_Casuale_Int(nums, dim, -20, 20);
                printf("Stampa array:\n");
                Stampa_Array_Int(nums, dim);
                Carica_Positivi_Negativi(nums, dim);

                free(nums);
                free(dim);
            }
            break;
        case 'c':
        case 'C':
            /*
            Cifrario cesare: data una stringa in input e uno shift,
            cifrarla spostando ogni carattere dell'alfabeto di shift posizioni.
            */
            {
                char* str = (char*) calloc(100, sizeof(char));
                printf("Inserire Stringa da convertire: ");
                gets(str);
                str = (char*) realloc(str, (strlen(str) + 1));

                int* shift = (int*) malloc(sizeof(int));
                printf("Inserire Shift: ");
                scanf("%d", shift);

                Cifrario_Cesare(str, shift);
                free(str);
                free(shift);
            }
            break;
        }
        getchar();
    } while (*scelta != 'q');
    printf("programma terminato...\n");
    free(scelta);
    return 0;
}

void menu(char *scelta)
{
    printf("=== VERIFICA ===\n");
    printf("a. Esercizio 1\n");
    printf("b. Esercizio 2\n");
    printf("c. Esercizio 3\n");
    printf("q. Termina\n");
    printf("Scelta > ");
    scanf("%c", scelta);
    fflush(stdin);
    system("@cls||clear");
}

void Carica_Casuale_Char(char *str, int *len, char min, char max)
{
    int* i = (int*) malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
    {
        //char c = (char) rand() % (max - min + 1) + min;
        //*(str + *i) = c;
        //printf("%c \n", c);
        *(str + *i) = (char) rand() % (max - min + 1) + min;
    }
    free(i);
}

void Stampa_Array_Char(char *str, int *len)
{
    int* i = (int*) malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
    {
        printf("%c\n", *(str + *i));
    }
    free(i);
}

int *Conta_Char_Alfabeto(char *str, int *len)
{
    int* i = (int*) malloc(sizeof(int));
    int* cont = (int*) calloc(0, sizeof(int));
    *cont = 0;
    for (*i = 0; *i < *len; (*i)++)
    {
        if ((*(str + *i) >= 'A' && *(str + *i) <= 'Z') || (*(str + *i) >= 'a' && *(str + *i) <= 'z')) {
            (*cont)++;
        }
    }
    free(i);
    return cont;
}

// ES 2
void Carica_Casuale_Int(int *arr, int *len, int min, int max)
{
    int* i = (int*) malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
    {
        *(arr + *i) = rand() % ((max - min + 1) + min);
    }
    free(i);   
}

void Stampa_Array_Int(int *arr, int *len)
{
    int* i = (int*) malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
    {
        printf("%d\n", *(arr + *i));
    }
    free(i);
}

void Carica_Positivi_Negativi(int *arr, int *len)
{
    
    int* dim_1 = (int*) malloc(sizeof(int));
    *dim_1 = 0;
    int* nums_pos = (int*) malloc(sizeof(int));

    int* dim_2 = (int*) malloc(sizeof(int));
    *dim_2 = 0;
    int* nums_neg = (int*) malloc(sizeof(int));

    int* i = (int*) malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
    {
        if (*(arr + *i) != 0) {
            if (*(arr + *i) > 0) {
                (*dim_1)++;
                nums_pos = (int*) realloc(nums_pos, *dim_1);
                *(nums_pos + (*dim_1 - 1)) = *(arr + *i);
            }
            else
            {
                (*dim_2)++;
                nums_neg = (int*) realloc(nums_neg, *dim_2);
                *(nums_neg + (*dim_2 - 1)) = *(arr + *i);
            }
            
        }
    }

    printf("\nStampa Numeri Positivi:\n");
    Stampa_Array_Int(nums_pos, dim_1);
    printf("\nStampa Numeri Negativi:\n");
    Stampa_Array_Int(nums_neg, dim_2);
    
    free(i);
    free(nums_pos);
    free(nums_neg);
    free(dim_1);
    free(dim_2);
}

// ESERCIZIO 3
void Cifrario_Cesare(char *str, int *shift)
{
    for (; *str != '\0'; (*str)++)
    {
        printf("%c", (*str + *shift));
    }
    printf("\n");
}