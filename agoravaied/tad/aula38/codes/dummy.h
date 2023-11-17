#ifndef DUMMY_H // existe essa macro definida?
#define DUMMY_H // não existe então definimos e inclua todos valores abaixo

// include guards -> serve para evitar que usamos multiplos includes iguais

typedef struct qualquer_struct{
    int val;
} QualquerStruct;

void hello();

#endif