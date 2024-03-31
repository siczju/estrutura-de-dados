// função de remover elementos (caso 2 e 3)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _doubly_node
{
    struct _doubly_node *next;
    struct _doubly_node *prev;
    int val;
} DoublyNode, Node;

typedef struct _linkedlist
{
    DoublyNode *begin;
    DoublyNode *end;
    size_t size;
} DoublyLinkedList, List;

Node *Node_create(int val)
{
    Node *node = (Node *)calloc(1, sizeof(Node));

    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}

List *list_create()
{
    List *L = (List *)calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void list_destroy(List *L)
{
    Node *pos = L->begin;

    while (pos != NULL)
    {
        Node *prev = pos;
        pos = pos->next;
        free(prev);
    }
    free(L);
}

bool list_isEmpty(List *L)
{
    return L->size == 0;
}

void list_print(List *L)
{

    printf("L ->");
    for (Node *pos = L->begin; pos != NULL; pos = pos->next)
    {
        printf(" [%d] ->", pos->val);
    }
    printf(" NULL\n");

    if (list_isEmpty(L))
    {
        printf("L->end = NULL\n");
        printf("L->begin = NULL\n");
    }
    else
    {
        printf("L->end = %d\n", L->end->val);
        printf("L->begin = %d\n", L->begin->val);
    }
    printf("L->size = %d\n", L->size);
}
void list_invertedPrint(List *L)
{

    printf("L->end ->");
    for (Node *pos = L->end; pos != NULL; pos = pos->prev)
    {
        printf(" [%d] ->", pos->val);
    }
    printf(" NULL\n");

    if (list_isEmpty(L))
    {
        printf("L->end = NULL\n");
        printf("L->begin = NULL\n");
    }
    else
    {
        printf("L->end = %d\n", L->end->val);
        printf("L->begin = %d\n", L->begin->val);
    }
    printf("L->size = %d\n", L->size);
}
void list_addFirst(List *L, int val)
{
    if (list_isEmpty(L))
        L->begin = L->end = Node_create(val);
    else
    {
        Node *p = L->begin;
        L->begin = Node_create(val);
        L->begin->next = p;
        p->prev = L->begin;
    }
    L->size++;
}
void list_addLast(List *L, int val)
{
    if (list_isEmpty(L))
        L->begin = L->end = Node_create(val);
    else
    {
        Node *p = L->end;
        L->end->next = L->end = Node_create(val);
        L->end->prev = p;
    }
    L->size++;
}

void list_remove(List *L, int val)
{
    if (!list_isEmpty(L))
    {
        // caso 1: o elemento está na cabeça da lista
        if (L->begin->val == val)
        {
            Node *p = L->begin;

            // a lista possui apenas 1 unico elemento
            if (L->begin == L->end)
            {
                L->begin = L->end = NULL;
            }
            // possui mais de um elemento
            else
            {
                L->begin = L->begin->next;
                L->begin->prev = NULL;
            }
            free(p);
            L->size--;
        }
        // caso 2: o elemento está no meio da lista ou
        // caso 3: o elemento está no final da lista
        else
        {
            Node *p = L->begin->next;
            while (p != NULL)
            {
                if (p->val == val)
                {
                    p->prev->next = p->next;
                    // caso 3
                    if (p->next == NULL)
                    {
                        L->end = p->prev;
                    }
                    // caso 2
                    else
                    {
                        p->next->prev = p->prev;
                    }
                    free(p);
                    p = NULL;
                    L->size--;
                }
                else
                    p = p->next;
            }
        }
    }
}

void main()
{
    List *L = list_create();

    list_addFirst(L, 12);
    list_addLast(L, 17);
    list_addFirst(L, 21);
    list_addLast(L, 42);

    list_remove(L, 17);

    list_print(L);
    list_invertedPrint(L);
}