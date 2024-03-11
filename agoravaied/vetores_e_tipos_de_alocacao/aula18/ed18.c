// Função para desalocar vetores dinâmicos

#include <stdio.h>
#include <stdlib.h>

    /* 
        int *v = endereço que calloc retornou
        int **v = *v (endereço do vh)

        v = endereço de vh (não da pra dar free nisso pois esta na memoria stack)
        *v = valor que está atribuido a vh (endereço do vetor)
        **v = valor que está dentro do endereço do vetor
    */

void desaloca_vetor(int **v){ // se usasse só int *v, iriamos so alterar o vetor (na heap), mas queremos alterar o valor de vh(stack) também para NULL
    free(*v);
     *v = NULL; 
}

void main(){
  
    int *vh = (int*) calloc(5, sizeof(int));

    for(int i = 0; i < 5; i++)
        vh[i] = i * 100;

    // free(vh); // desalocando o vetor dinâmico
    // vh = NULL; // boa prática

    puts("--- antes de desalocar o vetor e deixar ele null");
    printf("&vh = %p, vh = %p\n\n", &vh, vh);

    desaloca_vetor(&vh);

    puts("--- depois de desalocar o vetor e deixar ele null");
    printf("&vh = %p, vh = %p", &vh, vh);

}