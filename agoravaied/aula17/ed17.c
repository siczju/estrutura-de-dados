//          Funções com vetores estáticos e dinâmico
/*

    exercicios:

                Vetores Estáticos
    -> criar função que recebe o ponteiro de um vetor e seu tamanho e imprima os elementos do vetor
    -> criar função que recebe o ponteiro de um vetor via colchetes[] e seu tamanho e imprima os elementos do vetor
    -> Imprima os endereços de memória e valores do vetor na main e dentro de cada função

                Vetores Dinâmicos
    -> criar função que recebe o ponteiro de um vetor e seu tamanho e imprima os elementos do vetor
    -> criar função que recebe o ponteiro de um vetor via colchetes[] e seu tamanho e imprima os elementos do vetor
    -> imprima os endereços de memoria e valores do vetor na main e dentro de cada função;

*/
    // como passar um vetor como parâmetro p uma função

#include <stdio.h>
#include <stdlib.h>

    void soma_vetor_com_escalar(int v[], int n, int escalar){ // "n" -> tamanho // int v[] = int *v -> ta passando o endereço base do vetor
        for(int i = 0; i < n;  i++) v[i] += escalar;
    }

    void print_vetor(const int *v, int n){ // "n" -> tamanho // const para não mudar o valor do vetor sem querer
        for(int i = 0; i < n;  i++){
            printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
            // v[i]++; // v[i] + 1 == *(v + i) + 1 // daria erro pq ta tentando mudar o valor da constante 
        }
        puts("");
    }

void main(){

    puts("--- vetor estático ---");
    int vs[5] = {0, 10, 20, 30, 40};

    print_vetor(vs, 5); // vs -> armazena o endereço do primeiro indice então n precisamos passar &vs
    soma_vetor_com_escalar(vs, 5, 9);
    print_vetor(vs, 5);

    puts("--- vetor dinâmico ---");
    int *vh = (int*) calloc(5, sizeof(int));

    for(int i = 0; i < 5; i++)
        vh[i] = i * 100;

    print_vetor(vh, 5);
    soma_vetor_com_escalar(vh, 5, 9);
    print_vetor(vh, 5);

    free(vh); // desalocando o vetor dinâmico
    vh = NULL; // boa prática

}