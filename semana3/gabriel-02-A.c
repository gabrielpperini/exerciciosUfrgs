/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 03 / EXERCÍCIO 03-A

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>

/**
 * Main method
 * 
 * Calculate the Final Media and print the result
 * 
 * @return int 
*/
int main()
{
    float ap1, ap2, tf;
    printf("Informe a nota da AP1: ");
    scanf("%f", &ap1);

    if (ap1 < 6.0)
    {
        float recuperacao;
        printf("Informe a nota da Recuperacao: ");
        scanf("%f", &recuperacao);
        ap1 = (ap1 + recuperacao) / 2.0;
        printf("Nota AP1 apos recuperacao: %.1f\n", ap1);
    }

    printf("Informe a nota da AP2: ");
    scanf("%f", &ap2);
    printf("Informe a nota do Trabalho Final: ");
    scanf("%f", &tf);

    float mediaFinal = (ap1 * .35) + (ap2 * .45) + (tf * .2);

    if (mediaFinal < 6.0)
    {
        float recuperacaoFinal;
        printf("Nota final antes da recuperacao: %.1f", mediaFinal);
        printf("\nInforme a nota da Recuperacao: ");
        scanf("%f", &recuperacaoFinal);
        mediaFinal = (recuperacaoFinal + mediaFinal) / 2.0;
    }

    printf("\nO aluno ");
    if (mediaFinal >= 6.0)
    {
        printf("foi aprovado com nota ");
    }
    else
    {
        printf("reprovou, com media ");
    }
    printf("%.1f e conceito ", mediaFinal);

    if (mediaFinal >= 8.5)
    {
        printf("A");
    }
    else if (mediaFinal >= 7.5)
    {
        printf("B");
    }
    else if (mediaFinal >= 6.0)
    {
        printf("C");
    }
    else
    {
        printf("D");
    }

    return 0;
}