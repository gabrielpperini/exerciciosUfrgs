/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 04 / EXERCÍCIO 04-B

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>

/**
 * CalculateTurn
 * 
 * Request a turn entry and exit time and calculate the interval
 * 
*/
int calculateTurn(char *turn)
{
    int inHour, inMin, outHour, outMin;
    printf("Informe o horario de entrada e saida do %s turno: ", turn);
    scanf("%d %d %d %d", &inHour, &inMin, &outHour, &outMin);
    int total = ((outHour - inHour) * 60) + (outMin - inMin);

    return total;
}

/**
 * Main method
 * 
 * Request all the times from entry and exit from the five employees
 * 
 * @return int 
*/
int main()
{
    system("cls");
    int totalTime = 0;
    int totalExtraTime = 0;

    for (int i = 1; i <= 5; i++)
    {
        printf("\nFuncionario %d:\n", i);
        int first = calculateTurn("primeiro");
        int second = calculateTurn("segundo");
        int total = first + second;

        printf("\nTotal de minutos trabalhados pelo funcionario %d: %d minutos ", i, total);
        int extraTime = 0;
        if ((total / 60.0) > 8)
        {
            extraTime = total - (8 * 60);
            printf("(%d minutos extra)\n", extraTime);
        }
        printf("\n");

        totalTime += total;
        totalExtraTime += extraTime;
    }

    printf("TOTAL DE MINUTOS TRABALHADOS: %d minutos\n", totalTime);
    if (totalExtraTime > 0)
        printf("MINUTOS EXTRAS QUE FORAM TRABALHADOS: %d minutos", totalExtraTime);
    return 0;
}