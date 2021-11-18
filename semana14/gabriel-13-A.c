/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 14 / EXERCÍCIO 14-A

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>

int countNumbers(int number, int evenOdd);

/**
 * Main method
 * 
 * executa o programa principal
 * 
 * @return int 
*/
int main()
{
    system("cls");
    int num;
    for (int i = 0; i < 5; i++)
    {
        printf("Digite um numero: ");
        scanf("%d",&num);
        int even = digitos(num, 0);
        int odd = digitos(num, 1);
        printf("O numero %d tem %d digitos pares\n", num, even);
        printf("O numero %d tem %d digitos impares\n", num, odd);
    }
}

/**
 * digitos method
 * 
 * conta quantos digitos o numero tem
 * 
 * @return int 
*/
int digitos(int number, int evenOdd)
{
    if (number < 0)
        return 0;
    int digit = number % 10, count = 0;
    int rest = number / 10;

    if ((digit % 2) == evenOdd)
    {
        count++;
    }

    if (rest > 0)
    {
        count += digitos(rest, evenOdd);
    }

    return count;
}