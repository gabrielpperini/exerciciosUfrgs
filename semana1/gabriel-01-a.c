/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 01 / EXERCÍCIO 01-b

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <string.h>

int main()
{
    char nome[256];
    printf("Digite seu nome: ");
    scanf("%[0-9a-zA-Z ]",&nome);
    int tamanho = strlen(nome);
    char line[100] = "";
    for (int i = 0; i < (tamanho + 2); i++)
    {
        strcat(line,"=");
    }
    
    printf("/%s\\\n| %s |\n\\%s/", line, nome, line);
    return 0;
}