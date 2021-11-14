/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    SEMANA 12 / EXERCÍCIO 12-A

    ALUNO: Gabriel Prestes Perini
    MATRÍCULA: 00334582

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TAM_NAME 40
#define FPACIENTES "pacientes_semana12.bin"
#define LINE "-----------------------------------------\n"

typedef struct Paciente
{
    char nome[TAM_NAME]; /* nome do paciente */
    int idade;     /* idade em anos */
    char sexo;     /* sexo: (M)asculino ou (F)eminino */
    float altura;  /* altura do paciente (em metros) */
    int peso;      /* peso (em kg) */
} t_paciente;

void salva_pacientes(t_paciente pacientes[TAM], int n);
void le_pacientes(t_paciente pacientes[TAM], int *n);
void escreve_pacientes(t_paciente pacientes[TAM], int n);

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

    int continua = 1;
    int index = 0;
    t_paciente pacientes[TAM];

    while (continua == 1)
    {
        printf("INFORMACOES DO PACIENTE:\n");
        printf("\tNOME: ");
        fgets((pacientes + index)->nome, TAM_NAME, stdin);
        strtok((pacientes + index)->nome, "\n");
        printf("\tIDADE: ");
        scanf("%d", &(pacientes + index)->idade);
        printf("\tSEXO: ");
        getchar();
        (pacientes + index)->sexo = getchar();
        printf("\tALTURA: ");
        scanf("%f", &(pacientes + index)->altura);
        printf("\tPESO: ");
        scanf("%d", &(pacientes + index)->peso);
        printf("Deseja cadastrar outro paciente? [0] NAO [1] SIM ");
        scanf("%d", &continua);
        index++;
        getchar();
    }

    // salva o arquivo binário
    salva_pacientes(pacientes, index);
    printf("\nSalvei %d pacientes!\n", index);

    // pega os dados do arquivo binario
    t_paciente pacientesFromFile[TAM];
    int sizePac;
    le_pacientes(pacientesFromFile, &sizePac);

    // renderiza na tela
    escreve_pacientes(pacientesFromFile, sizePac);

    return 0;
}

/**
 * salva_pacientes method
 * 
 * salva os dados dos pacientes no arquivo
 * 
*/
void salva_pacientes(t_paciente pacientes[TAM], int n)
{
    FILE *arquivo = fopen(FPACIENTES, "w");
    if (arquivo)
    {
        fwrite(&n, sizeof(int), 1, arquivo);
        fwrite(pacientes, sizeof(t_paciente), TAM, arquivo);
        fclose(arquivo);
    }
    else
    {
        printf("Impossível de abrir arquivo [%s]. Fatal.\n", FPACIENTES);
    }
}

/**
 * le_pacientes method
 * 
 * pega os dados dos pacientes no arquivo
 * 
*/
void le_pacientes(t_paciente pacientes[TAM], int *n)
{
    FILE *arquivo = fopen(FPACIENTES, "r");
    if (arquivo)
    {
        fread(n, sizeof(int), 1, arquivo);
        fread(pacientes, sizeof(t_paciente), TAM, arquivo);
        fclose(arquivo);
    }
    else
    {
        printf("Impossível de abrir arquivo [%s]. Fatal.\n", FPACIENTES);
    }
}

/**
 * escreve_pacientes method
 * 
 * renderiza na tela os dados dos pacientes
 * 
*/
void escreve_pacientes(t_paciente pacientes[TAM], int n)
{
    printf(LINE);
    printf("LISTA DE PACIENTES\n");
    printf(LINE);
    for (int i = 0; i < n; i++)
    {
        t_paciente pacTemp = pacientes[i];
        printf("NOME      :%s\n", pacTemp.nome);
        printf("IDADE     :%d\n", pacTemp.idade);
        printf("SEXO      :%c\n", pacTemp.sexo);
        printf("ALTURA    :%.2f\n", pacTemp.altura);
        printf("PESO      :%d\n", pacTemp.peso);
        printf(LINE);
    }
}