// Variação da lista encadeada simples -> o nó agora também aponta para seu antecessor -> o nó anterior do primeiro nó é NULL
// Vantagem de ter nó para o antecessor e para o sucessor é que agora a gente pode navegar pelas duas direções

#include <stdio.h>
#include <stdlib.h>

typedef struct _doubly_node {
    struct _doubly_node *next;
    struct _doubly_node *prev;
    int val;
} DoublyNode, Node;

typedef struct _linkedlist {
    DoublyNode *begin;
    DoublyNode *end;
    size_t size;
} DoublyLinkedList, List;

