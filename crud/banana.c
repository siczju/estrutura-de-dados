#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    struct _node *right; // next
    struct _node *left;  // prev
    int val;
} Node;
typedef struct _linkedlist
{
    Node *begin;
    Node *end;
    size_t size;
} LinkedList, Stack, Queue, ArvB;

// linked list

Node *node_create(int val)
{
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;

    return newNode;
}

LinkedList *list_create()
{
    LinkedList *L = (LinkedList *)calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
}

void list_print(LinkedList *L)
{

    if(L->begin == NULL){
        printf("(imprimir) List is empty!\n");
        return;
    } else if(L->begin->right == NULL){
        printf("L -> %d\n", L->begin->val);
        return;
    }
    printf("L -> ");
    Node *aux = L->begin;
    for(int i = 0; i < L->size; aux = aux->right, i++)
        printf("[%d] -> ", aux->val);

    printf("NULL\n");

    printf("L->end = %d\n", L->end->val);
    printf("L->begin = %d\n", L->begin->val);
    printf("L->size = %d\n\n", L->size);
    
}

void list_insert(LinkedList *L, int index, int val)
{
    Node *newNode = node_create(val);
    if (index < 0 || index > L->size)
    {
        printf("Invalid Index: %d\n", index);
        return;
    }
    if (L->begin == NULL)
    { // empty list
        L->begin = L->end = newNode;
        L->size++;
        return;
    }
    if (index == 0)
    { // first node
        newNode->right = L->begin;
        L->begin->left = newNode;
        L->begin = newNode;
        L->size++;
    }
    if (index == L->size)
    { // last node
        newNode->left = L->end;
        L->end->right = newNode;
        L->end = newNode;
        L->size++;
    }
    else
    { // mid node
        Node *aux = L->begin;
        for (int i = 0; i <= index; i++)
            aux = aux->right;

        aux->left->right = newNode;
        newNode->left = aux->left;
        newNode->right = aux;
        aux->left = newNode;
        L->size++;
    }
}

void list_remove(LinkedList *L, int index){
    if(L->begin == NULL){
        printf("(remove) List is empty!");
        return;
    }
    if(L->begin == L->end){ // only one element
        free(L->begin);
        L->begin = L->end = NULL;
        L->size--;
    }
    if(index == (L->size - 1)){ // last element
        Node *aux =  L->end->left;
        aux->right = NULL;
        free(L->end);
        L->end = aux;
        L->size--;
    }
    if(index == 0){ // first element
        Node *aux = L->begin;
        L->begin = aux->right;
        L->begin->left = NULL;
        free(aux);
        L->size--;
    }
    else if(index > 0 && index < L->size - 1){ // mid element
        Node *aux = L->begin;
        for(int i = 0; i < index; aux = aux->right, i++);
        aux->left->right = aux->right;
        aux->right->left = aux->left;
        free(aux);
        L->size--;
    }
}

void list_search(LinkedList *L, int value){
    if(L->begin == NULL){
        printf("(print) List is empty\n");
        return;
    }
    if(value < 0){
        printf("Invalid Value: %d\n", value);
        return;
    }
    int i = 0;
    for(Node *aux = L->begin; i < L->size; i++, aux = aux->right){
        if(value = aux->val){
            printf("The value: %d, is in the list, in the index: %d\n", value, i);
            return;
        }
    }
}

// stack
// queue
// binary tree
// 0 - sair\n 1 - inserir\n 2 - remover 3 - imprimir\n 4 - buscar\n

void main(){
    LinkedList *L = list_create();

    list_insert(L, 0, 12); 
    list_insert(L, 1, 13); 
    list_insert(L, 2, 14); 
    list_insert(L, 3, 15); 
    list_print(L);
    list_remove(L, 1); 
    list_print(L);
    list_search(L, 13);
}