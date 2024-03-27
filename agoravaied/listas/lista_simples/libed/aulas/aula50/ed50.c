// Listas Encadeadas Simples - Inserção na cabeça

/*

    Pra saber se a lista está vazia o ponteiro begin tem que ser null

*/

#include <stdio.h>

typedef struct _snode{
    int val;
    struct _snode *next;
} SNode;

typedef struct _linked_list{
    SNode *begin;
} LinkedList;

SNode *SNode_create(int val){
    SNode *snode = (SNode*) calloc(1, typedef(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
} 

LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList*) calloc(1, typedef(LinkedList));
    L->begin = NULL;

    return L;
}

LinkedList *LinkedList_add_first(LinkedList *L, int val){
    SNode *snode = SNode_create(val);

    snode->next = L->begin;
    L->begin = snode;
}

void main() {
//  nada ainda
}