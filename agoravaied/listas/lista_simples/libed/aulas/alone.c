#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _snode
{
    int val;
    struct _snode *next;
} SNode;

typedef struct _linkedlist
{
    SNode *begin;
    SNode *end;
    size_t size;
} LinkedList;

// create node
SNode *SNode_create(int val)
{
    SNode *node = (SNode *)calloc(1, sizeof(SNode));
    node->val = val;
    node->next = NULL;

    return node;
}
// create LinkedList
LinkedList *list_create()
{
    LinkedList *list = (LinkedList *)calloc(1, sizeof(LinkedList));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}
// print LinkedList
void list_print(const LinkedList *L)
{
    printf("L -> ");

    for (SNode *prev = L->begin; prev != NULL; prev = prev->next)
    {
        printf("[%d] -> ", prev->val);
    }
    printf("NULL\n");

    if (L->end == NULL)
        printf("L->end = NULL\n");
    if (L->end != NULL)
        printf("L->end = %d\n", L->end->val);

    printf("L->size = %d\n", L->size);
}
// list is empty or not?
bool list_isEmpty(LinkedList *L)
{
    return L->size == 0;
}
// list size
size_t list_size(const LinkedList *L)
{
    return L->size;
}
// adding a node in the beginning of the list
void list_addFirst(LinkedList *L, int val)
{
    SNode *node = SNode_create(val);

    if (list_isEmpty(L))
        L->begin = L->end = node;
    else
    {
        node->next = L->begin;
        L->begin = node;
    }
    L->size++;
}
// adding a node in the final of the list
void list_addLast(LinkedList *L, int val)
{
    SNode *node = SNode_create(val);

    if (list_isEmpty(L))
        L->begin = L->end = node;
    else
        L->end->next = L->end = node; // Temos que fazer o nó novo não perder a referencia com a lista, então fazemos (L->end->next = node), ai depois trocamos o L->end para o node.
    L->size++;
}
// return the first node value
int list_firstValue(const LinkedList *L)
{
    if (L->begin == NULL)
    {
        printf("The linked list's empty!\n");
        return;
    }
    return L->begin;
}
// return the last node value
int list_lastValue(const LinkedList *L)
{
    if (L->end == NULL)
    {
        printf("The linked list's empty!\n");
        return;
    }
    return L->end;
}
// return a value in 'n' position
int list_userValue(const LinkedList *L, int index)
{
    if (list_isEmpty(L))
    {
        printf("The list is empty!\n");
        return NULL;
    }
    if (index < 0 || index >= list_size(L))
    {
        printf("Error: The index %d is out of range!\n", index);
        printf("Please provide an index within [0, %zu]\n", list_size(L) - 1);
        return; // Retorna um valor especial indicando erro
    }
    int i = 0;
    SNode *p = L->begin;
    while (i != index)
    {
        p = p->next;
        i++;
    }
    printf("The index value of the list is: %d\n", p->val);
    return p->val;
}

void list_removeNode(LinkedList *L, int value)
{
    SNode *prev = NULL;
    SNode *pos = L->begin;

    while (pos != NULL && pos->val != value)
    {
        prev = pos;
        pos = pos->next;
    }

    if (pos == NULL)
    {
        printf("Node with value %d, not found in the list\n", value);
        return;
    }
    if (prev == NULL) // se chegou ate aqui é pq o pos achou o valor, então se o prev for NULL, é obviamente o primeiro nó da lista.
        L->begin = pos->next;
    else
        prev->next = pos->next; // atualiza o prev, agora podemos remover o nó pos sem problemas, não perdemos referencia.
    if (pos->next == NULL)
        L->end = prev;

    free(pos);
}

void list_destroy(LinkedList* L){
    SNode* remove = NULL;
    SNode* p = L->begin;

    while(p != NULL){
        remove = p;
        p = p->next;
        free(remove);
    }
    free(L);
}

void main()
{
    LinkedList *L = list_create();

    list_addFirst(L, 12);
    list_addLast(L, 14);
    list_addFirst(L, 21);
    list_removeNode(L, 12);
    list_addLast(L, 45);

    // list_userValue(L, -12);

    list_print(L);
}