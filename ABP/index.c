#include <stdio.h>
#include <stdlib.h>

struct TNodoA
{
    char info;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

pNodoA *InsereArvore(pNodoA *a, int ch)
{
    if (a == NULL)
    {
        a = (pNodoA *)malloc(sizeof(pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (ch < a->info)
        a->esq = InsereArvore(a->esq, ch);
    else
        a->dir = InsereArvore(a->dir, ch);
    return a;
}

void preFixado(pNodoA *a)
{
    if (a != NULL)
    {
        printf("%c\n", a->info);
        preFixado(a->esq);
        preFixado(a->dir);
    }
}

int countNodes(pNodoA *a)
{
    if (a == NULL)
        return 0;
    int i = 1;
    i += countNodes(a->dir);
    i += countNodes(a->esq);
    return i;
}

void imprimiArvore(pNodoA *a, int key)
{
    if (a != NULL)
    {
        int i;
        for (i = 0; i < key; i++)
            printf("=");
        printf("%c\n", a->info);
        imprimiArvore(a->esq, key + 1);
        imprimiArvore(a->dir, key + 1);
    }
}

int main()
{
    pNodoA *arvore = NULL;
    arvore = InsereArvore(arvore, '8');
    arvore = InsereArvore(arvore, '9');
    arvore->esq = InsereArvore(arvore->esq, '4');
    arvore->esq = InsereArvore(arvore->esq, '6');
    arvore->esq->esq = InsereArvore(arvore->esq->esq, '2');
    arvore->esq->esq->esq = InsereArvore(arvore->esq->esq->esq, '1');
    // int c = countNodes(arvore);
    // printf("\n%d\n", c);
    imprimiArvore(arvore, 1);
    return 0;
}
