/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 05 / EXERCÍCIO 04-B

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * is prime method
 * 
 * verify if the number is prime
 * 
 * @return bool
*/
bool isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int x = 2; x < number; x++)
    {
        if (number % x == 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * Main method
 * 
 * Request two numbers and 
 * 
 * @return int 
*/
int main()
{
    system("cls");
    int x, y;
    printf("Informe os dois numeros: ");
    scanf("%d %d", &x, &y);
    while (x < 0 || y < 0 || x == y)
    {
        printf("Valores invalidos! Informe novamente...\n");
        printf("Informe os dois numeros: ");
        scanf("%d %d", &x, &y);
    }

    printf("\n");
    int mmc = 1;
    for (int i = 2; i < (x + y); i++)
    {
        if (isPrime(i) && (x % i == 0 || y % i == 0))
        {
            do
            {
                mmc *= i;
                printf("%5d %5d | %d\n", x, y, i);
                if (x % i == 0)
                    x = x / i;
                if (y % i == 0)
                    y = y / i;
            } while (x % i == 0 || y % i == 0);

            if (x == 1 && y == 1)
            {
                printf("%5d %5d |", x, y);
                break;
            }
        }
    }
    printf("\n\nMMC = %d", mmc);
    return 0;
}