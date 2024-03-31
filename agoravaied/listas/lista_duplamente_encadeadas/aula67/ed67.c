// funções de criação e destruição das listas, criação do nó, e print da lista

#include <stdio.h>
#include <stdlib.h>

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

Node* Node_create(int val){
    Node *node = (Node*) calloc(1, sizeof(Node));

    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}

List* list_create()
{
    List *L = (List*)calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void list_destroy(List* L){
    Node *pos = L->begin;

    while(pos != NULL){
        Node *prev = pos;
        pos = pos->next;
        free(prev);
    }
    free(L);
}

 void list_print(List *L){

    printf("L ->");
    for(Node *pos = L->begin; pos != NULL; pos = pos->next){
        printf(" [%d] ->", pos->val);
    }
    printf(" NULL\n");

    printf("L->end = %d\n", L->end);
    printf("L->begin = %d\n", L->begin);
    printf("L->size = %d\n", L->size);

 }


void main(){
    List *L = list_create();


}