/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 02 / EXERCÍCIO 02-1

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <math.h>

/**
 * Main method
 * 
 * calculate a triangule area by Heron formula
 * 
 * @return int 
*/
int main()
{
    int a, b, c;
    // get all triangule sides
    printf("Informe os lados do triangulo: ");
    scanf("%d %d %d", &a, &b, &c);

    // apply Heron formula and print the result
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("A area do triangulo e: %.2f", area);

    return 0;
}