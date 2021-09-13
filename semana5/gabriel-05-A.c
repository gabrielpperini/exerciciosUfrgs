/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 05 / EXERCÍCIO 04-A

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
    if(number < 2){
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
    int px, py;
    printf("Informe os valores x e y: ");
    scanf("%d %d", &px, &py);
    while (px < 0 || py < 0 || px == py)
    {
        printf("Valores invalidos! Informe novamente...\n");
        printf("Informe os valores x e y: ");
        scanf("%d %d", &px, &py);
    }

    int x = px > py ? py : px;
    int y = px < py ? py : px;

    int sum = 0;
    for (int i = x; i <= y; i++)
    {
        if (isPrime(i))
        {
            sum += i;
        }
    }
    printf("A soma dos primos entre %d e %d eh %d", x, y, sum);
    return 0;
}