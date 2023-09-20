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

No* Remover(No *raiz, int chave){
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

No* Inserir(No *raiz, int valor) {
    if(raiz == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->direita = NULL;
        novoNo->esquerda = NULL;
        return novoNo;
    } else {
        if(valor < raiz->conteudo)
            raiz->esquerda = Inserir(raiz->esquerda, valor);

        if(valor > raiz->conteudo)
            raiz->direita = Inserir(raiz->direita, valor);

        return raiz;
    }
}

int Buscar(No *raiz, int chave) {
    if(raiz == NULL) {
        return -1;
    } else {
        if(raiz->conteudo == chave)
            return raiz->conteudo;
        else {
            if(raiz->conteudo > chave)
                return Buscar(raiz->esquerda, chave);
            else
                return Buscar(raiz->direita, chave);
        }            
    }
}

No* BuscarNo(No *raiz, int chave) {
    if(raiz == NULL) {
        return NULL;
    } else {
        if(raiz->conteudo == chave)
            return raiz;
        else {
            if(raiz->conteudo > chave)
                return BuscarNo(raiz->esquerda, chave);
            else
                return BuscarNo(raiz->direita, chave);
        }            
    }
}

int Tamanho(No *raiz) {
    if(raiz == NULL)
        return 0;
    else 
        return 1 + Tamanho(raiz->esquerda) + Tamanho(raiz->direita);
}

int AlturaArvore(No *raiz) {
    if(raiz == NULL || raiz->direita == NULL && raiz->esquerda == NULL){
        return 0;
    }
    else{
        int esq = 1 + AlturaArvore(raiz->esquerda);
        int dir = 1 + AlturaArvore(raiz->direita);
        if(esq > dir)
            return esq;
        else
            return dir;
    }
}

int AlturaSubArvore(No *raiz, int chave) {
    No *no = BuscarNo(raiz, chave);
    if(no)
        return AlturaArvore(no);
    else
        return -1; //codigo de erro
}

void Imprimir(No *raiz)
{
    if(raiz != NULL){
        Imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        Imprimir(raiz->direita);
    }
}

int main()
{
    int op, valor;
    ArvoreBinaria arvore;
    No *raiz = NULL;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3 - buscar\n4 - remover\n5 - altura\n6 - altura subarvore\n");
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
            raiz = Inserir(raiz, valor);
            break;
        case 2:
            printf("\nImpreção da arvore binaria\n");
            Imprimir(raiz);
            printf("\n");
            printf("Tamanho: %d", Tamanho(raiz));
            printf("\n");
            break;
        case 3:
            printf("\nDigite o valor deseja buscar:\n");
            scanf("%d", &valor);
            printf("Resultado da busca: %d\n", Buscar(raiz, valor));
            break;
        case 4:
            printf("\nDigite um valor a ser removido: ");
            scanf("%d", &valor);
            raiz = Remover(raiz, valor);
            break;
        case 5:
            printf("\nAltura da arvore e: %d\n", AlturaArvore(raiz));
            break;
        case 6:
            printf("\nDigite o valor deseja calcular a altura:\n");
            scanf("%d", &valor);
            printf("Altura e: %d\n", AlturaSubArvore(raiz, valor));
            break;
        default:
            printf("\nOpção invalida\n");
            break;
        }
    } while (op != 0);
    
}
