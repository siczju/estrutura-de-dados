// Função para desalocar vetores dinâmicos

#include <stdio.h>
#include <stdlib.h>

void desaloca_vetor(int **v){
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

    desaloca_vetor(vh);

    puts("--- depois de desalocar o vetor e deixar ele null");
    printf("&vh = %p, vh = %p", &vh, vh);

}