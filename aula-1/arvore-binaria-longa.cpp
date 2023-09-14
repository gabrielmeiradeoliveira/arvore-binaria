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

void inserirDireita(No *no, int valor);

void inserirEsquerda(No *no, int valor)
{
    if(no->esquerda == NULL) {
        No *novoNo = (No*)malloc(sizeof(No)); //Alocando memoria para o novo nó

        //Preenchendo valores do novo nó
        novoNo->conteudo = valor;
        novoNo->direita = NULL;
        novoNo->esquerda = NULL;

        no->esquerda = novoNo; //Salvando novo nó a esquerda
    }  else {
         if(valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda,valor);
         if(valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda,valor);
    }
}

void inserirDireita(No *no, int valor)
{
    if(no->direita == NULL) {
        No *novoNo = (No*)malloc(sizeof(No)); //Alocando memoria para o novo nó

        //Preenchendo valores do novo nó
        novoNo->conteudo = valor;
        novoNo->direita = NULL;
        novoNo->esquerda = NULL;

        no->direita = novoNo; //Salvando novo nó a esquerda
    } else {
         if(valor < no->direita->conteudo)
            inserirEsquerda(no->direita,valor);
        if(valor > no->direita->conteudo)
            inserirDireita(no->direita,valor);
    }
}

void inserir(ArvoreBinaria *arvore, int valor)
{
    if(arvore->raiz == NULL) {
        No *novoNo = (No*)malloc(sizeof(No)); //Alocando memoria para o novo nó
        
        //Preenchendo valores do novo nó
        novoNo->conteudo = valor;
        novoNo->direita = NULL;
        novoNo->esquerda = NULL;

        arvore->raiz = novoNo; //variavel (raiz) recebe a variavel (novoNo)
    } else {
        if(valor < arvore->raiz->conteudo)
            inserirEsquerda(arvore->raiz,valor);
         if(valor > arvore->raiz->conteudo)
            inserirDireita(arvore->raiz,valor);
    }
}

void imprimir(No *raiz)
{
    if(raiz != NULL){
        //Exibe valor ordenado
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int main ()
{
    int op, valor;
    ArvoreBinaria arvore;
    arvore.raiz = NULL;

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
            printf("\nDigite um valor\n");
            scanf("%d", &valor);
            inserir(&arvore, valor);
            break;
        case 2:
            printf("\nImpreção da arvore binaria\n");
            imprimir(arvore.raiz);
            printf("\n");
            break;
        
        default:
            printf("\nOpção invalida\n");
            break;
        }
    } while (op != 0);
    
}

//quando estiver manipulando ponteiro usar ->
//quando estiver manipulando objeto usar .
