#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct float_vector{
    int capacity; // numero maximo de elementos do vetor
    int size; // qtde de elementos armazenados atualmente
    float *data; // vetor de floats
};

//      INTERFACE PRIVADA

// função privada -> não está disponível para usuários/programas ou outros arquivos que usam o float_vector.h 
bool _FloatVector_isFull(const FloatVector *vec){ // para identificar que a função é privada colocamos _ no começo (só como exemplo)
    return vec->size == vec->capacity;
}

//      INTERFACE PÚBLICA

/**
 * @brief Cria ou aloca um vetor de floats com uma dada capacidade
 * 
 * @param capacity Capacidade do vetor.
 * @return FloatVector* retorna um vetor de floats alocado/criado
 */
FloatVector *FloatVector_create(int capacity){
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));
    
    return vec;
}

void FloatVector_destroy(FloatVector **vec_ref){
    FloatVector *vec = *vec_ref;
    
    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

void FloatVector_append(FloatVector *vec, float val){

    if(vec-> size == vec->capacity){
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE);
    }
    vec->data[vec->size] = val;
    vec->size++;
    }
    void FloatVector_print(const FloatVector *vec){
        puts("----------------");
     
        printf("Size: %d %d\n", vec->size);
        printf("Capacity: %d\n", vec->capacity);
        puts("---");

        for(int i = 0; i < vec->size; i++)
        printf("[%d] = %f\n", i, vec->data[i]);

        puts("----------------\n");
    }

    int FloatVector_size(const FloatVector *vec){ // retorna o número de elementos do vetor
        return vec->size;
    }

    int FloatVector_capacity(const FloatVector *vec){
        return vec->capacity;
    }

    float FloatVector_at(const FloatVector *vec, int index){
            if(_FloatVector_isFull(vec)){ //if(index < 0 || index >= vec->size){
            fprintf(stderr, "ERROR in 'at'\n");
            fprintf(stderr, "Index[%d] is out of bounds: [0, %d]\n", index, vec->size - 1);
            exit(EXIT_FAILURE); // termina o programa com código de erro -> está na biblioteca <stdlib.h>
        }
        return vec->data[index];
    }

    float FloatVector_get(const FloatVector *vec, int index){ // mais performance doq o at, porém menos segurança doq o at
        return vec->data[index];
    }

void FloatVector_set(FloatVector *vec, int index, float val){
        if(_FloatVector_isFull(vec)){// if(index < 0 || index >= vec->size){
            fprintf(stderr, "ERROR in 'set'\n");
            fprintf(stderr, "Index[%d] is out of bounds: [0, %d]\n", index, vec->size - 1);
            exit(EXIT_FAILURE); // termina o programa com código de erro -> está na biblioteca <stdlib.h>
        }
        vec->data[index] = val;
}
     
