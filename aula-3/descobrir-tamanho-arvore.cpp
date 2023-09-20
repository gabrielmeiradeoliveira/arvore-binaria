#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvoreBinaria;

//Verifica o tamanho da arvore
int tamanho(No* raiz) {
    if(raiz == NULL)
        return 0;
    else 
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

No* inserir(No *raiz, int valor) {
    if(raiz == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->direita = NULL;
        novoNo->esquerda = NULL;
        return novoNo;
    } else {
        if(valor < raiz->conteudo)
            raiz->esquerda = inserir(raiz->esquerda, valor);

        if(valor > raiz->conteudo)
            raiz->direita = inserir(raiz->direita, valor);

        return raiz;
    }
}

void imprimir(No *raiz)
{
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int main ()
{
    int op, valor;
    ArvoreBinaria arvore;
    No *raiz = NULL;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n");
        printf("\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("\nImpreção da arvore binaria\n");
            imprimir(raiz);
            printf("\n");
            printf("Tamanho: %d", tamanho(raiz));
            printf("\n");
            break;
        
        default:
            printf("\nOpção invalida\n");
            break;
        }
    } while (op != 0);
    
}
