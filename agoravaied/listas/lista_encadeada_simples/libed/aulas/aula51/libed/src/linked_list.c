#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

typedef struct _snode
{
    int val;
    struct _snode *next;
} SNode; // Simple Node

typedef struct _linked_list
{
    SNode *begin;
} LinkedList;

SNode *SNode_create(int val)
{
    SNode *snode = (SNode *)calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL; // pois não tem proximo nó, so quando criarmos dnv

    return snode;
}

// Cria e aloca uma nova lista
LinkedList *LinkedList_create()
{
    LinkedList *L = (LinkedList *)calloc(1, sizeof(LinkedList));
    L->begin = NULL;

    return L;
}

void Linkedlist_add_first(LinkedList *L, int val){
    SNode *p = SNode_create(val); // cria o nó
   p->next = L->begin;
   L->begin = p;
}

/* Imprimir a LinkedList

    1 - Criar um ponteiro p e faça-o apontar para o início da lista. (SNode *p = L->begin;)
    2- Enquanto a lista nao acaba (NULL) imprima os dados apontados por p e mova p para o próximo elemento da lista (p = p->next;)

*/
void LinkedList_print(const LinkedList *L){
    for(SNode *p = L->begin; p != NULL; p = p->next)
        printf(" [%d] ->", p->val);
}