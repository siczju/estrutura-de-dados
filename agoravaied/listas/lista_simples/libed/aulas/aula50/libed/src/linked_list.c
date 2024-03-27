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

/* na função add_first a gente quer adicionar um nó no começo da linkedlist

    L->[begin] -> [2] -> [4]
        disto para
    L->[begin] -> [NovoNó] -> [2] -> [4]

*/

void Linkedlist_add_first(LinkedList *L, int val){
    SNode *p = SNode_create(val); // cria o nó

    /* if (L->begin = NULL){ // lista está vazia?
        L->begin = p; // begin apontará pra onde P está apontando (vai ser o primeiro nó)
    }
    else{
        p->next = L->begin;
        L->begin = p;
    }
    */

   // podemos usar só a segunda parte do if que ja funcionaria a função

   p->next = L->begin;
   L->begin = p;
}
