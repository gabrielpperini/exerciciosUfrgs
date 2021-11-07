/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 10 / EXERCÍCIO 10-A

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>

void deriva(double *poli, int grau, double *out);

/**
 * Main method
 * 
 * Build a vector to test function derivada
 * 
 * @return int 
*/
int main()
{
    system("cls");

    int grau;

    printf("Informe o grau do polinomio: ");
    scanf("%d", &grau);

    while (grau > 9 || grau < 1)
    {
        printf("Valor invalido! Por favor informe um valor entre 1 e 9.\n");
        printf("Informe o grau do polinomio: ");
        scanf("%d", &grau);
    }

    double poli[10], out[10];

    for (int i = grau; i >= 0; i--)
    {
        printf("Informe o componente x^%d: ", i);
        scanf("%lf", &poli[grau - i]);
    }

    printf("Polinomio de entrada:");
    for (int i = grau; i >= 0; i--)
    {
        if (i < grau)
            printf(" +");
        printf(" %.2lfx^%d", poli[grau - i], i);
    }

    deriva(poli, grau, out);

    printf("\nDerivada: ");
    int indexOut = grau - 1;
    for (int i = indexOut; i >= 0; i--)
    {
        if (i < indexOut)
            printf(" +");
        printf(" %.2lfx^%d", out[indexOut - i], i);
    }

    return 0;
}

/**
 * Deriva method
 * 
 * calculate the derivada function in a polinomium
 * 
*/
void deriva(double *poli, int grau, double *out)
{
    for (int i = grau; i >= 0; i--)
    {
        if ((i - 1) >= 0)
        {
            int index = grau - i;
            out[index] = poli[index] * i;
        }
    }
}