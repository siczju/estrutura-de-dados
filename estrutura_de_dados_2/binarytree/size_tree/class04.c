#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo; // valor
    struct no *direita, *esquerda;
} No;

typedef struct
{
    No *raiz;
} ArvB;

No *no_create(int valor)
{
    No *novo = (No *)calloc(1, sizeof(No));
    novo->conteudo = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

void inserirEsquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    { // n tem ninguem na esquerda do nó
        No *novo = no_create(valor);
        no->esquerda = novo;
    }
    else
    { // ja tem alguem na esquerda
        if (valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        if (valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}
void inserirDireita(No *no, int valor)
{
    if (no->direita == NULL)
    { // n tem ninguem na direita do nó
        No *novo = no_create(valor);
        no->direita = novo;
    }
    else{ // ja tem alguem na direita
        if (valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if (valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
}

void inserir(ArvB *arv, int valor)
{
    if (arv->raiz == NULL)
    { // vazia
        No *novo = no_create(valor);
        arv->raiz = novo;
    }
    else
    { // tem pelomenos 1 nó na arvore.
        if (valor < arv->raiz->conteudo)
            inserirEsquerda(arv->raiz, valor);
        if (valor > arv->raiz->conteudo)
            inserirDireita(arv->raiz, valor);
    }
}

No* inserirNovaVersao(No *raiz, int valor){
    if(raiz == NULL){
        return no_create(valor);
    }
    else{
        if(valor < raiz->conteudo)
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        if(valor > raiz->conteudo)
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        return raiz;
    }
}

int tamanho(No *raiz){
    if(raiz == NULL)
        return 0;
    else    
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

void main()
{
    int opcao, valor;
    ArvB arv;
    arv.raiz = NULL;

    do {
        printf("\n 0 - sair\n 1 - inserir\n 2 - imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: 
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                arv.raiz = inserirNovaVersao(arv.raiz, valor);
                // inserir(&arv, valor);
                break;
            case 2: 
                printf("\nImpressao da arvore binaria:\n");
                imprimir(arv.raiz);
                puts("");
                printf("Tamanho: %d\n", tamanho(arv.raiz));
                break;
            default:
                printf("\nOpcao invalida...\n");
        }
    } while(opcao != 0);
}