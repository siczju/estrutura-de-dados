#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int val; // valor
    struct _node *right, *left;
} Node;

typedef struct _binarytree
{
    Node *root;
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

void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->val);
        printTree(root->right);
    }
    else{
        printf("(print) Binary tree is empty!\n");
    }
}

Node* insert(Node *newNode, int val){

    if(newNode == NULL)
        return node_create(val);
    else{
        if(val < newNode->val)
            newNode->left = insert(newNode->left, val);
        if(val > newNode->val)
            newNode->right = insert(newNode->right, val);
        return newNode;
    }

}

Node *removeNode(Node *root, int val){

    if(root == NULL)
        return NULL;
    else {
    if(val < root->val)
        root->left = removeNode(root->left, val);
    if(val > root->val)
        root->right = removeNode(root->right, val);
    else{
    // ver se tem 0 ou 1 filhos
    if(root->left == NULL){
        Node *aux = root->right;
        free(root);
        return aux;
    }
    if(root->right == NULL){
        Node *aux = root->left;
        free(root);
        return aux;
    }
    // ver se tem 2 filhos
    else{
        Node *aux = root->left;
        while(aux->right != NULL)
            aux = aux->right;
        root->val = aux->val;
        aux->val = val;
        root->left = removeNode(root->left, val);
        return root;
    }
    }
    return root;
    }
}


