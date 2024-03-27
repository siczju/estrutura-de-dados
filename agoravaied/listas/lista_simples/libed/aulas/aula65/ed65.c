//      Retornar o primeiro elemento, retornar o ultimo elemento e retornar o elemento na posição i

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
    size_t size;
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
    L->size = 0;

    return L;
}

void LinkedList_print(const LinkedList *L)
{
    printf("L ->");

    for (SNode *p = L->begin; p != NULL; p = p->next)
        printf(" [%d] -> ", p->val);

    printf("NULL\n");

    if (L->end == NULL)
    {
        printf("L->end = NULL\n");
    }
    else
    {
        printf("L->end = %d\n", L->end->val);
    }

    printf("size: %d\n", L->size);
}

bool LinkedList_isEmpty(LinkedList *L)
{
    return L->size == 0;
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
    L->size++;
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
    L->size++;
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

    L->size++;
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
/*
void LinkedList_remove(LinkedList *L, int val)
{
    SNode *p = L->begin;

    if (LinkedList_isEmpty(L))
    {
        printf("Elemento %d nao encontrado na lista.\n", val);
        return;
    }
    else if (L->begin->val == val)
    { // caso o elemento estiver na cabeça da lista
        L->begin = L->begin->next;

        if (L->end == L->begin) // caso a lista tiver apenas um nó (se nao tivesse essa linha o end iria apontar para uma região inexistente)
            L->end = NULL;

        free(p);
    }
    else
    { // elemento no meio da lista
        SNode *previous = L->begin; // previous -> anterior
        p = L->begin->next;
        while (p != NULL && p->val != val)
        {
            previous = p; // previous = previous->next
            p = p->next;
        }
        if (p != NULL)
        { // valor "val" foi encontrado
            previous->next = p->next;
            free(p);
        }
        if (p == L->end)
            L->end = previous;
        free(p);
    }
        L->size--;
}
*/

void LinkedList_remove(LinkedList *L, int val)
{
    if (!LinkedList_isEmpty(L))
    {
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while (pos != NULL && pos->val != val)
        {
            prev = pos;
            pos = pos->next;
        }

        // se achou um nó com valor val
        if (pos != NULL)
        {
            if (L->end == pos)
            {
                L->end = prev;
            }
            if (L->begin == pos)
            {
                L->begin = L->begin->next;
            }
            else
            {
                prev->next = pos->next;
            }

            free(pos);
            L->size--;
        }
    }
}

void LinkedList_destroy(LinkedList **L_ref)
{

    LinkedList *L = *L_ref;
    SNode *p = L->begin;
    SNode *aux = NULL;

    while (p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
} // a qtde de calloc q existe na lista tem que ser a mesma qtde para frees

// size_t -> qnd quer guardar tamanho de algo, é um apelido para unsigned long
size_t LinkedList_size_slow(const LinkedList *L)
{
    size_t size = 0;

    for (SNode *p = L->begin; p != NULL; p = p->next)
        size++;

    return size;
}

size_t LinkedList_size(const LinkedList *L)
{
    return L->size;
}

int LinkedList_first_val(const LinkedList *L)
{
    if (LinkedList_isEmpty(L))
    {
        printf("The LinkedList is empty\n");
        return;
    }
    return L->begin->val;
}

int LinkedList_last_val(const LinkedList *L)
{
    if (LinkedList_isEmpty(L))
    {
        printf("The LinkedList is empty\n");
        return;
    }
    return L->end->val;
}
int LinkedList_getValOfIndex(const LinkedList *L, int index)
{
    if (index > LinkedList_size(L) || index < 0)
    {
        printf("Invalid Index: %d\n", index);
        printf("Try and index within [0, %d]\n", LinkedList_size(L) - 1);
        return NULL;
    }
    if (LinkedList_isEmpty(L))
    {
        printf("The list is empty");
        return NULL;
    }

    SNode *p = L->begin;
    int i;
    for (i = 0; i < index; i++)
    {
        p = p->next;
    }
    printf("The index value of Linked List is: %d\n", p->val);
    return p->val;
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
    // printf("size: %d", LinkedList_size_slow(L));

    printf("The first value of Linked List is: %d\n", LinkedList_first_val(L));
    printf("The last value of Linked List is: %d\n", LinkedList_last_val(L));
    LinkedList_getValOfIndex(L, 2);

    LinkedList_destroy(&L);
}
