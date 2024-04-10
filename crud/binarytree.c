#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int conteudo; // valor
    struct no *direita, *esquerda;
} No;

typedef struct
{
    No *raiz;
} ArvB;
