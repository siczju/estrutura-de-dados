#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

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
    snode->next = NULL; // pois não tem proximo nó, so quando criarmos dnv

    return snode;
}

// Cria e aloca uma nova lista
LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL;

    return L;
}

