/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 06 / EXERCÍCIO 06-B

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 100

/**
 * Main method
 * 
 * replace the chosen char in the string for empty and print the result
 * 
 * @return int 
*/
int main()
{
    system("cls");
    char word[TAMANHO], newWord[TAMANHO] = "", c;
    printf("Informe uma string: ");
    fgets(word, TAMANHO, stdin);
    printf("Informe o caracter a ser removido da string: ");
    c = getchar();

    int i = 0;
    while (word[i] != '\0')
    {
        if (word[i] != c && word[i] != '\n')
        {
            char cToStr[2];
            cToStr[1] = '\0';
            cToStr[0] = word[i];
            strcat(newWord, cToStr);
        }
        i++;
    }

    printf("A string original sem o caractere [%c] eh [%s]", c, newWord);

    return 0;
}