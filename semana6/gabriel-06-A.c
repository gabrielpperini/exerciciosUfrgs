/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 06 / EXERCÍCIO 06-A

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_1 10
#define TAMANHO_2 5

/**
 * printVector method
 * 
 * print the name and the elements from a vector
 * 
 * @return int 
*/
int printVector(const int *const vector, int size, char *name)
{
    printf("\n");
    printf(name);
    printf(" [");
    for (int i = 0; i < size; i++)
        printf(" %d ", vector[i]);
    printf("]");
    return 0;
}

/**
 * Main method
 * 
 * build two vectors randomly and check if has divisors in the second vector for each element from first vector
 * 
 * @return int 
*/
int main()
{
    system("cls");
    srand(time(NULL));
    int vector1[TAMANHO_1], vector2[TAMANHO_2];

    for (int i = 0; i < TAMANHO_1; i++)
    {
        vector1[i] = 100 + (rand() % 901);
    }
    for (int i = 0; i < TAMANHO_2; i++)
    {
        vector2[i] = 1 + (rand() % 10);
    }

    printVector(vector1, TAMANHO_1, "Vetor 1");
    printVector(vector2, TAMANHO_2, "Vetor 2");

    for (int i = 0; i < TAMANHO_1; i++)
    {
        int count = 0;
        printf("\n\nNumero %d", vector1[i]);
        for (int e = 0; e < TAMANHO_2; e++)
        {
            if (vector1[i] % vector2[e] == 0)
            {
                printf("\nDivisivel por %d na posicao %d", vector2[e], e);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nNao possui divisores no segundo vetor");
        }
    }

    return 0;
}