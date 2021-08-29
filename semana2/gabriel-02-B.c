/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 02 / EXERCÍCIO 02-B

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>

/**
 * Main method
 * 
 * Request the bag weight of cat food and its day portions to calculate the amount after 5 days  
 * 
 * @return int 
*/
int main()
{
    int peso, qtdgato1, qtdgato2;
    // get cat food bag weight 
    printf("Informe o peso do saco de racao (em Kg): ");
    scanf("%d", &peso);
    // get day portion of each cat
    printf("Informe a quantidade de racao diaria fornecida a cada gato (em gramas): ");
    scanf("%d %d", &qtdgato1, &qtdgato2);

    // process data and print the result
    double rest = peso - ((float)(qtdgato1 + qtdgato2) * 5 / 1000);
    rest = rest >= 0 ? rest : 0;
    printf("Apos 5 dias restarao no saco %.1f kg de racao", rest);
    return 0;
}