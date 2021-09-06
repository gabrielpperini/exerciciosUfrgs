/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 04 / EXERCÍCIO 04-A

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <math.h>

char menu()
{
    char letter;

    printf("A - Area do trapezio\n");
    printf("B - Equacao do segundo grau\n");
    printf("C - Media Geometrica\n");
    printf("D - Soma do Intervalo\n");

    printf("\nInforme o codigo i: ");
    scanf("%c", &letter);

    return letter;
}

void areaTrapezio(int a, int b, int c)
{
    float area = ((a + b) * c) / 2.00;
    printf("A area do trapezio de bases %d e %d, com altura %d eh: %.2f", a, b, c, area);
}

void pitagoras(int a, int b, int c)
{
    float delta = sqrt(pow(b, 2) - 4 * a * c);
    if (delta > 0)
    {
        float raiz1 = (-b + delta) / (2.00 * a);
        float raiz2 = (-b - delta) / (2.00 * a);
        printf("A equacao %dx^2 + %dx + %d = 0 possui duas raizes: %.2f e %.2f", a, b, c, raiz1, raiz2);
    }
    else
    {
        printf("A equacao %dx^2 + %dx + %d = 0 nao possui raizes", a, b, c);
    }
}

void mediaGeometrica(int a, int b, int c)
{
    float media = cbrt(a * b * c);
    printf("A media geometrica dos valores [%d, %d, %d] eh: %.2f", a, b, c, media);
}

void somaIntervalo(int a, int b, int c)
{
    int sum = 0;
    for (int i = a; i <= b; i += c)
    {
        sum += i;
    }
    printf("A soma dos valores de %d ate %d (de %d em %d) eh %d", a, b, c, c, sum);
}

/**
 * Main method
 * 
 * 
 * 
 * @return int 
*/
int main()
{
    system("cls");
    int a, b, c;
    char letter = menu();
    printf("Entre com os valores a, b e c: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a < 0 || b < 0 || c < 0 || a >= b)
    {
        printf("Valores inconsistentes!");
        return 0;
    }

    switch (letter)
    {
    case 'A':
    case 'a':
        areaTrapezio(a, b, c);
        break;
    case 'B':
    case 'b':
        pitagoras(a, b, c);
        break;
    case 'C':
    case 'c':
        mediaGeometrica(a, b, c);
        break;
    case 'D':
    case 'd':
        somaIntervalo(a, b, c);
        break;
    default:
        printf("O codigo informado eh invalido!");
        break;
    }
    return 0;
}