/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 10 / EXERCÍCIO 10-B

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>

/**
 * isBissexto method
 * 
 * Verica se o ano é bissexto
 * 
 * @return int 
*/
int isBissexto(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

/**
 * monthLength method
 * 
 * retorna o número de dias do mês
 * 
 * @return int 
*/
int monthLength(int month, int year)
{
    if (month == 2)
    {
        return isBissexto(year) == 1 ? 29 : 28;
    }

    if (month > 7)
    {
        return month % 2 == 0 ? 31 : 30;
    }
    else
    {
        return month % 2 == 0 ? 30 : 31;
    }
}

/**
 * nextDay method
 * 
 * imprime o dia seguinte
 * 
*/
void nextDay(int day, int month, int year)
{
    int nDay, nMonth, nYear;
    int daysMonth = monthLength(month, year);

    if (daysMonth == day)
    {
        nDay = 1;
        nMonth = month == 12 ? 1 : (month + 1);
        nYear = month == 12 ? (year + 1) : year;
    }
    else
    {
        nDay = day + 1;
        nMonth = month;
        nYear = year;
    }

    printf("O dia seguinte de %d/%d/%d eh %d/%d/%d\n\n", day, month, year, nDay, nMonth, nYear);
}

/**
 * validDate method
 * 
 * valida a data
 * 
 * @return int 
*/
int validDate(int day, int month, int year)
{
    if (year < 1900 || year > 2100)
        return 0;
    if (month < 1 || month > 12)
        return 0;

    int daysMonth = monthLength(month, year);
    if (day < 1 || day > daysMonth)
        return 0;

    return 1;
}

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
    int nDates;
    printf("Informe a quantidade de datas que serao lidas: ");
    scanf("%d", &nDates);

    int i = 0;
    while (i < nDates)
    {
        int day, month, year;
        printf("Informe o dia, mes e ano: ");
        scanf("%d %d %d", &day, &month, &year);
        if(validDate(day, month, year) == 1){
            nextDay(day, month, year);
            i++;
        }else{
            printf("Data Invalida! Informe novamente...\n");
        }
    }

    return 0;
}
