/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 13 / EXERCÍCIO 13-B

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define LINE_TAM 256

/**
 * hasWord method
 * 
 * verificar se a string possui a palavra 
 * 
 * @return int 
*/
int hasWord(const char str[LINE_TAM], char *word)
{
    char line[LINE_TAM];
    strcpy(line, str);
    int index = 0;
    char *pch = strtok(line, " ");
    if (strcmp(word, pch) == 0)
        return 1;
    while (pch != NULL)
    {
        index++;
        pch = strtok(NULL, " ");
        if (pch != NULL && strcmp(word, pch) == 0)
            return 1;
    }
    return 0;
}

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
    char name[TAM], word[TAM];

    printf("Informe o nome do arquivo: ");
    fgets(name, TAM, stdin);
    strtok(name, "\n");

    printf("Informe a palavra a ser encontrada: ");
    fgets(word, TAM, stdin);
    strtok(word, "\n");

    FILE *arquivo = fopen(name, "r");
    if (arquivo == NULL)
    {
        printf("Impossivel de abrir arquivo [%s]. Fatal.\n", name);
        return 0;
    }

    printf("\n");
    int count, find;
    count = find = 0;
    char line[LINE_TAM];
    char *wordsArr;
    while (fgets(line, LINE_TAM, arquivo) != NULL)
    {
        strtok(line, "\n");
        count++;
        if (hasWord(line, word) == 1)
        {
            printf("[Linha %d]: %s\n", count, line);
            find++;
        }
    }

    if (find > 0)
        printf("\n");
    printf("Foram encontradas %d ocorrencias de %s no arquivo %s", find, word, name);

    return 0;
}