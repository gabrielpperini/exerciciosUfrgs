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
    int idade;           /* idade em anos */
    char sexo;           /* sexo: (M)asculino ou (F)eminino */
    float altura;        /* altura do paciente (em metros) */
    int peso;            /* peso (em kg) */
} t_paciente;

void salva_pacientes(t_paciente pacientes[TAM], int n);
void le_pacientes(t_paciente pacientes[TAM], int *n);
void escreve_pacientes(t_paciente pacientes[TAM], int n);

void update_weight(void);
void list_overweight(void);
void list_all(void);

/**
 * Main method
 * 
 * executa o programa principal
 * 
 * @return int 
*/
int main()
{
    int option;
    do
    {
        printf("Informe a operacao desejada:\n");
        printf("\t[1] Atualizar Peso\n");
        printf("\t[2] Listar Pacientes acima do peso ideal\n");
        printf("\t[3] Listar todos os pacientes\n");
        printf("\t[4] Encerrar\n");
        printf("? ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            update_weight();
            break;
        case 2:
            list_overweight();
            break;
        case 3:
            list_all();
            break;
        }
    } while (option != 4);

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

/**
 * update_weight method
 * 
 * atualiza o peso de um paciente
 * 
*/
void update_weight(void)
{
    // pega os dados do arquivo binario
    t_paciente pacientesFromFile[TAM];
    int sizePac;
    le_pacientes(pacientesFromFile, &sizePac);

    char name[TAM_NAME];
    printf("Informe o nome do paciente: ");
    getchar();
    fgets(name, TAM_NAME, stdin);
    strtok(name, "\n");

    int find = 0;
    for (int i = 0; i < sizePac; i++)
    {
        t_paciente *tempPac = &pacientesFromFile[i];
        if (strcmp(tempPac->nome, name) == 0)
        {
            int newWeight;
            printf("Informe o novo peso do paciente %s: [Peso anterior %dKg] ", tempPac->nome, tempPac->peso);
            scanf("%d", &newWeight);
            tempPac->peso = newWeight;
            printf("Peso atualizado com sucesso!\n");
            find++;
            break;
        }
    }

    if (find == 1)
        salva_pacientes(pacientesFromFile, sizePac);
    else
        printf("Paciente nao encontrado\n");
}

/**
 * list_overweight method
 * 
 * renderiza na tela os dados dos pacientes acima do peso ideal contidos no binario
 * 
 */
void list_overweight(void)
{
    // pega os dados do arquivo binario
    t_paciente pacientesFromFile[TAM], pacientesOverweight[TAM];
    int sizePac, sizeOverPac = 0;
    le_pacientes(pacientesFromFile, &sizePac);

    for (int i = 0; i < sizePac; i++)
    {
        t_paciente *tempPac = &pacientesFromFile[i];
        double ideal;
        if (tempPac->sexo == 'M')
        {
            ideal = (72.7 * tempPac->altura) - 58;
        }
        else
        {
            ideal = (62.1 * tempPac->altura) - 44.7;
        }

        if (ideal < tempPac->peso)
        {
            pacientesOverweight[sizeOverPac] = *tempPac;
            sizeOverPac++;
        }
    }

    // renderiza na tela
    if (sizeOverPac > 0)
        escreve_pacientes(pacientesOverweight, sizeOverPac);
    else
        printf("Todos pacientes estao no peso ideal!\n");
}

/**
 * list_all method
 * 
 * renderiza na tela os dados dos pacientes contidos no binario
 * 
 */
void list_all(void)
{
    // pega os dados do arquivo binario
    t_paciente pacientesFromFile[TAM];
    int sizePac;
    le_pacientes(pacientesFromFile, &sizePac);

    // renderiza na tela
    escreve_pacientes(pacientesFromFile, sizePac);
}