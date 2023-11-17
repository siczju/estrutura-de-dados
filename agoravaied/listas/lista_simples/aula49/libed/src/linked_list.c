#include "linked_list.h"

#include <stdlib.h>

typedef struct _snode{
    int val;
    struct _snode *next;
    } SNode; // Simple Node
    
typedef struct _linked_list{
    SNode *begin;
} LinkedList;

SNode *SNode_create(int val){
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val = val;
    snode ->next = NULL; // pois não tem proximo nó, so quando criarmos dnv
}

// Cria e aloca uma nova lista
LinkedList *LinkedList_create(LinkedList list){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL;

    return L;
}

