/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 13 / EXERCÍCIO 13-A

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int encrypt(char name[TAM], int key);

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
    int key, encryptOrDecrypt;
    char name[TAM];

    printf("Informe o nome do arquivo: ");
    fgets(name, TAM, stdin);
    strtok(name, "\n");

    printf("Informe a chave de criptografia: ");
    scanf("%d", &key);

    printf("O que deseja fazer com este arquivo? [1] - Criptografar [2] - Descriptografar ");
    scanf("%d", &encryptOrDecrypt);
    if (encryptOrDecrypt == 1)
    {
        if (encrypt(name, key) == 1)
            printf("Operacao de criptografia concluida!");
    }
    else if (encryptOrDecrypt == 2)
    {
        if (encrypt(name, key * -1) == 1)
            printf("Operacao de descriptografia concluida!");
    }
    return 0;
}

/**
 * encrypt method
 * 
 * realiza a criptografia do arquivo
 * 
 * @return int 
*/
int encrypt(char name[TAM], int key)
{
    FILE *arquivo = fopen(name, "r");
    if (arquivo)
    {
        FILE *saida = fopen("SAIDA.txt", "w");
        char c;
        while ((c = fgetc(arquivo)) != EOF)
        {
            fputc(c == 10 ? c : (c + key), saida);
        }
        fclose(arquivo);
        fclose(saida);
        return 1;
    }
    printf("Impossivel de abrir arquivo [%s]. Fatal.\n", name);
    return 0;
}