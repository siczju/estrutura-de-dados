/*
    Listas Circulares -> Variação da lista duplamente encadeada
    -> o nó anterior ao nó inicial é o nó final.
    -> o próximo nó do final é o nó inicial.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _circ_node
{
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
} CircNode, Node;
typedef struct _circ_list
{
    size_t size;
    CircNode *begin;
    CircNode *end;
} CircList, List;

Node *node_create(int val)
{
    Node *newNode = (Node *)calloc(1, sizeof(Node));

    newNode->next = newNode;
    newNode->prev = newNode;
    newNode->val = val;

    return newNode;
}
CircList *list_create()
{
    CircList *L = (CircList *)calloc(1, sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}
bool list_isEmpty(CircList *L)
{
    return L->size == 0;
}
void list_print(CircList *L)
{
    Node *p = L->begin;
    if (list_isEmpty(L))
        printf("L -> NULL\n");
    else
    {
        printf("L ->");
        for (int i = 0; i < L->size; i++)
        {
            printf(" [%d] ->", p->val);
            p = p->next;
        }

        printf(" NULL\n");

        printf("L->begin = %d\n", L->begin->val);
        printf("L->end= %d\n", L->end->val);
    }

    printf("L->size= %d\n", L->size);
}
void list_invertedPrint(const CircList *L)
{
    if (list_isEmpty(L))
    {
        printf("L -> NULL\n");
    }
    else
    {
        CircNode *p = L->end;
        printf("L->end -> ");
        for (int i = 0; i < L->size; i++)
        {
            printf("[%d] -> ", p->val);
            p = p->prev;
        }
        printf(" NULL");

        printf("\nL->begin -> %d", L->begin->val);
        printf("\nL->end -> %d\n", L->end->val);
    }

    printf("L->size: %d\n\n", L->size);
}

void list_destroy(CircList *L)
{
    Node *p = L->begin;
    Node *aux = NULL;
    for (int i = 0; i < L->size; i++)
    { // não pode ser mais p != NULL, pois nao tem mais NULL
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);
}

void list_addFirst(CircList *L, int value)
{
    Node *newNode = node_create(value);
    if (list_isEmpty(L))
    {
        L->begin = L->end = newNode;
    }
    else
    {
        newNode->next = L->begin;
        L->begin->prev = L->begin = newNode; // o antigo nó que apontava para o final agora apontará para o novo primeiro nó
        newNode->prev = L->end;
        L->end->next = newNode;
    }
    L->size++;
}
void list_addLast(CircList *L, int value)
{
    Node *newNode = node_create(value);
    if (list_isEmpty(L))
    {
        L->begin = L->end = newNode;
    }
    else
    {
        L->end->next = L->begin->prev = newNode;
        newNode->prev = L->end;
        newNode->next = L->begin;
    }
    L->end = newNode;
    L->size++;
}
void list_remove(CircList *L, int value)
{
    if (!list_isEmpty(L))
    {
        Node *p = L->begin;

        for (int i = 0; i <= L->size; i++)
        {
            if (p->val == value)
            {
                // caso 1 - head
                if (value == L->begin->val)
                {
                    if (L->begin == L->end)
                    { // caso a lista possui apenas um único elemento
                        free(L->begin);
                        L->begin = L->end = NULL;
                    }
                    else
                    { // caso a lista possui mais de um elemento
                        Node *aux = L->begin->next;
                        free(L->begin);
                        L->end->next = L->begin = aux;
                        aux->prev = L->end;
                    }
                    L->size--;
                }
                else if (L->end == p)
                { // caso 3 - end
                    Node *aux = L->end->prev;
                    free(L->end);
                    L->end = aux;
                    L->begin->prev = L->end;
                    L->end->next = L->begin;
                    L->size--;
                    break;
                }
                else
                { // caso 2 - mid
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    free(p);
                    L->size--;
                    break;
                }
            }
            p = p->next;
        }
        return;
    }
    else
        printf("Invalid value: %d\n", value);
}

void main()
{
    CircList *L = list_create();

    list_print(L);
    list_invertedPrint(L);

    puts("Remove 99");
    list_remove(L, 99);
    list_print(L);
    list_invertedPrint(L);

    puts("add_last 10, 7, 2, 4, 7");
    list_addLast(L, 10);
    list_addLast(L, 7);
    list_addLast(L, 2);
    list_addLast(L, 4);
    list_addLast(L, 7);
    list_print(L);
    list_invertedPrint(L);

    puts("Remove 99");
    list_remove(L, 99);
    list_print(L);
    list_invertedPrint(L);

    puts("Remove 7");
    list_remove(L, 7);
    list_print(L);
    list_invertedPrint(L);

    puts("Remove 10");
    list_remove(L, 10);
    list_print(L);
    list_invertedPrint(L);

    puts("Remove 4");
    list_remove(L, 4);
    list_print(L);
    list_invertedPrint(L);

    puts("Remove 7");
    list_remove(L, 7);
    list_print(L);
    list_invertedPrint(L);

    puts("Remove 2");
    list_remove(L, 2);
    list_print(L);
    list_invertedPrint(L);
}
