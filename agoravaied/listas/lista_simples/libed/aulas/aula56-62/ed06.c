//      Remover elementos da lista

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _snode
{
    int val;
    struct _snode *next;
} SNode;

typedef struct _linked_list
{
    SNode *begin;
    SNode *end;
} LinkedList;

SNode *SNode_create(int val)
{
    SNode *snode = (SNode *)calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}

LinkedList *LinkedList_create()
{
    LinkedList *L = (LinkedList *)calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
}

void LinkedList_print(const LinkedList *L)
{
    printf("L ->");

    for (SNode *p = L->begin; p != NULL; p = p->next)
        printf(" [%d] -> ", p->val);

    printf("NULL\n");
}

bool LinkedList_isEmpty(LinkedList *L)
{ //      NEW
    return (L->begin == NULL && L->end == NULL);
}

/*
void LinkedList_add_first(LinkedList *L, int val){
    SNode *snode = SNode_create(val);

    snode->next = L->begin;
    L->begin = snode;
}
*/

void LinkedList_add_first(LinkedList *L, int val)
{
    SNode *snode = SNode_create(val);

    if (LinkedList_isEmpty(L)) // por causa do *end
        L->end = snode;

    snode->next = L->begin;
    L->begin = snode;
}

void LinkedList_add_last_slow(LinkedList *L, int val)
{
    SNode *snode = SNode_create(val);

    if (LinkedList_isEmpty(L))
    {
        L->begin = snode;
    }
    else
    {
        SNode *p = L->begin;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = snode;
    }
}

// temos um ponteiro pro começo da lista (begin), que tal termos um ponteiro para o final(end*) dela? Assim se for inserir outro elemento no final da lista, n precisaria percorrer ela toda (caso fosse varios nós)

void LinkedList_add_last_fast(LinkedList *L, int val)
{
    SNode *snode = SNode_create(val);

    //      se a lista tiver vazia L Begin e L End terão o mesmo valor, pois o ultimo tb é o primeiro
    if (LinkedList_isEmpty(L))
        L->begin = L->end = snode;
    else
        L->end->next = L->end = snode;
}

/*
void LinkedList_remove(LinkedList *L, int val){
    SNode *p = L->begin;
    int i = 0;

    while(p->val != val && p != NULL){
     p = p->next;
     i++;
    }

    if(p == NULL){
    printf("Elemento %d não encontrado na lista.\n", val);
    return;
    }

    SNode *aux = p->next;

    p = L->begin;
    i--;
    while(i > 0){
     p = p->next;
     i--;
    }
    p->next = aux;
}
*/

void LinkedList_remove(LinkedList *L, int val)
{
    SNode *p = L->begin;

    if (LinkedList_isEmpty(L))
    {
        printf("Elemento %d nao encontrado na lista.\n", val);
        return;
    }else if(L->begin->val == val) { // caso o elemento estiver na cabeça da lista
        L->begin = L->begin->next;

        if(L->end = L->begin) // caso a lista tiver apenas um nó (se nao tivesse essa linha o end iria apontar para uma região inexistente)
           L->end = NULL;

        free(p);
    }else{ // elemento no meio da lista
    
        SNode *previous = L->begin; // previous -> anterior
        p = L->begin->next;
    while (p != NULL && p->val != val)
    {
        previous = p; // previous = previous->next
        p = p->next;
    }
    if(p != NULL){ // valor "val" foi encontrado
        previous->next = p->next;
        free(p);
    }
        if(p == L->end) L->end = previous;
        free(p);
    }
    
    }


void main()
{

    LinkedList *L = LinkedList_create();

    LinkedList_add_last_fast(L, 10);
    LinkedList_remove(L, 5);
    LinkedList_add_first(L, 5);
    LinkedList_add_first(L, 25);
    LinkedList_add_last_slow(L, 15);
    LinkedList_remove(L, 15);

    LinkedList_print(L);
}
