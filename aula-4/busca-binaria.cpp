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

int tamanho(No* raiz) {
    if(raiz == NULL)
        return 0;
    else 
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

//o retorno das linhas 27 e 31, verifica se o numero procurado esta na arvore (1) ou não (0)
/*
    o retorno das linhas 26 e 30, verificar se o numero procurado esta na arvore,
    caso esteja retorna o valor presente na (raiz->conteudo)
    caso não esteja o retorno será -1
*/
int busca(No *raiz, int chave) {
    if(raiz == NULL) {
        return -1;
        //return 0
    } else {
        if(raiz->conteudo == chave)
            return raiz->conteudo;
            //return 1
        else {
            if(raiz->conteudo > chave)
                return busca(raiz->esquerda, chave);
            else
                return busca(raiz->direita, chave);
        }            
    }

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
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3 - buscar\n");
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
        case 3:
            printf("\nDigite o valor que deseja buscar:\n");
            scanf("%d", &valor);
            printf("Resultado da busca: %d\n", busca(raiz, valor));
            break;
        
        default:
            printf("\nOpção invalida\n");
            break;
        }
    } while (op != 0);
    
}
