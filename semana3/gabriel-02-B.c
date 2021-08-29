/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 03 / EXERCÍCIO 03-B

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>

/**
 * Main method
 * 
 * 
 * 
 * @return int 
*/
int main()
{
    int GolI1, GolI2, GolG1, GolG2;
    printf("Informe o numero de gols do Internacional na primeira partida: ");
    scanf("%d", &GolI1);
    printf("Informe o numero de gols do Gremio na primeira partida: ");
    scanf("%d", &GolG1);
    printf("Informe o numero de gols do Internacional na segunda partida: ");
    scanf("%d", &GolI2);
    printf("Informe o numero de gols do Gremio na segunda partida: ");
    scanf("%d", &GolG2);

    int pointI = 0, pointG = 0;
    if (GolG1 == GolI1)
    {
        pointI++;
        pointG++;
    }
    else
    {
        pointI += GolI1 > GolG1 ? 3 : 0;
        pointG += GolG1 > GolI1 ? 3 : 0;
    }
    if (GolG2 == GolI2)
    {
        pointI++;
        pointG++;
    }
    else
    {
        pointI += GolI2 > GolG2 ? 3 : 0;
        pointG += GolG2 > GolI2 ? 3 : 0;
    }

    printf("\nPontuacao Final: \nInternacional: %d pontos \nGremio: %d pontos\n", pointI, pointG);

    if (pointG == pointI)
    {
        int GolIf, GolGf;
        printf("\nEmpate! Os times jogarao a partida final:");
        printf("\nInforme o numero de gols do Internacional: ");
        scanf("%d", &GolIf);
        printf("Informe o numero de gols do Gremio: ");
        scanf("%d", &GolGf);
        if (GolGf == GolIf)
        {
            pointI++;
            pointG++;
        }
        else
        {
            pointI += GolIf > GolGf ? 3 : 0;
            pointG += GolGf > GolIf ? 3 : 0;
        }
    }

    if (pointG == pointI)
    {
        printf("\nDeu Empate!");
        return 0;
    }

    printf("\nO Vencedor e o ");
    pointG > pointI ? printf("Gremio") : printf("Internacional");

    return 0;
}