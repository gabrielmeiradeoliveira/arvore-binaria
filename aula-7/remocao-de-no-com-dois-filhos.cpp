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

int busca(No *raiz, int chave) {
    if(raiz == NULL) {
        return -1;
    } else {
        if(raiz->conteudo == chave)
            return raiz->conteudo;
        else {
            if(raiz->conteudo > chave)
                return busca(raiz->esquerda, chave);
            else
                return busca(raiz->direita, chave);
        }            
    }
}

No* Remover(No* raiz, int chave){
    if(raiz == NULL)
        return NULL;
    else {
        if(raiz->conteudo == chave) {
            //remove nós folhas(nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            } else {
                //remove nós que possuem apenas 1 filho
                if(raiz->esquerda == NULL || raiz->direita == NULL) {
                    No *auxiliar;
                    if(raiz->esquerda != NULL)
                        auxiliar = raiz->esquerda;
                    else
                        auxiliar = raiz->direita;

                    free(raiz);
                    return auxiliar;
                } else {
                    No *auxiliar = raiz->esquerda;

                    while(auxiliar->direita != NULL)
                        auxiliar = auxiliar->direita;
                    
                    raiz->conteudo = auxiliar->conteudo;
                    auxiliar->conteudo = chave;
                    raiz->esquerda = Remover(raiz->esquerda, chave);

                    return raiz;
                }
            }
        } else {
            if(raiz->conteudo > chave)
               raiz->esquerda = Remover(raiz->esquerda, chave);
            else 
              raiz->direita =  Remover(raiz->direita, chave);

            return raiz;
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
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3 - buscar\n4 - remover\n");
        printf("\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("\nDigite um valor a ser inserido: ");
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
        case 4:
            printf("\nDigite um valor a ser removido: ");
            scanf("%d", &valor);
            raiz = Remover(raiz, valor);
            break;
        default:
            printf("\nOpção invalida\n");
            break;
        }
    } while (op != 0);
    
}
