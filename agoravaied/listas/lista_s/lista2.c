//          Inserir no início da lista

#include <stdio.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

// procedimento para inserir no inicio
void inserirInicio(No **lista, int num ){
    No *novo = malloc(sizeof(No));
    if (novo){
        novo.valor = num;
    }else {
        printf("Erro ao alocar memória!\n");
    }
    
}

void main() {
    
}