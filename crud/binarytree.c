#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int val; // valor
    struct no *right, *left;
} Node;

typedef struct _binarytree
{
    No *root;
} ArvB;

ArvB* tree_create(){
    ArvB *newTree = (ArvB*) calloc(1, sizeof(ArvB));
    newTree->root = NULL;

    return newTree;
}

Node* node_create(int val){
    Node *newNode = (Node*) calloc(1, sizeof(Node));
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}
void insert(Node *newNode, int val){

    if(newNode == NULL)
        return node_create(val);
    else{
        if(val < newNode->val)
    }

}


