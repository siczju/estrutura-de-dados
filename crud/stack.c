#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    struct _node *right; // next
    struct _node *left;  // prev
    int val;
} Node;
typedef struct _stack
{
    Node *begin;
    Node *end;
    int size;
} Stack;

Node* node_create(int val){
    Node *newNode = (Node*) calloc(1, sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;

    return newNode;
}

Stack* stack_create(){
    Stack* newStack = (Stack*) calloc(1, sizeof(newStack));
    newStack->begin = NULL;
    newStack->end = NULL;

    return newStack;
}

void stack_print(Stack* S){

    if(S->begin == NULL){
        printf("(print) List is empty\n");
        return;
    }
    if(S->size == 1){
        printf("Stack -> [%d] -> ", S->begin->val);
        printf("NULL");
        return;
    }

    Node *aux = S->begin;
    printf("Stack -> ");
    for(int i = 0; i < S->size; i++, aux = aux->right)
        printf("[%d] -> ", aux->val);
    printf("NULL");
}

void stack_pop(Stack* S){
    if(S->begin == NULL){
        printf("(pop) List is empty");
        return;
    }
    if(S->size == 1){
        free(S->begin);
        S->begin = S->end = NULL;
        S->size--;
        return;
    }
    Node *aux = S->end->left;
    aux->right = NULL;
    free(S->end);
    S->end = aux;
    S->size--;
}
void stack_push(Stack *S, int val){
    Node *newNode = node_create(val);
    if(S->begin == NULL){
        S->begin = S->end = newNode;
        S->size++;
        return;
    }
    if(S->size == 1){
        S->begin->right = newNode;
        newNode->left = S->begin;
        S->end = newNode;
        S->size++;
        return;
    }
    S->end->right = newNode;
    newNode->left = S->end;
    S->end = newNode;
    S->size++;
}
void stack_search(Stack *S, int val){
    if(S->begin == NULL){
        printf("(search) Stack is empty\n");
        return;
    }
    int i = 0;
    for(Node *aux = S->begin; i < S->size; i++, aux = aux->right){
        if(aux->val == val){
            printf("The value %d, is in the stack!\n", val);
            return;
        }
    }
    printf("The value %d, isn't in the stack!\n", val);
}

void stack_update(Stack *S, int index, int val){
    if(index < 0 || index > S->size){
        printf("Invalid index: %d\n", index);
        return;
    }
    int i = 0;
    for(Node *aux = S->begin; i <= index; i++, aux = aux->right){
        if(i == index){
            aux->val = val;
        }
    }
}

void print_menu()
{
    printf("\nMenu:\n");
    printf("1 - Insert\n");
    printf("2 - Remove\n");
    printf("3 - Update\n");
    printf("4 - Print\n");
    printf("5 - Search\n");
    printf("0 - Exit\n");
    printf("Enter your choice: ");
}
int main()
{
    Stack *S = stack_create();
    int choice, index, value;

    do
    {
        print_menu();
        scanf("%d", &choice);
        puts("");

        switch (choice)
        {
        case 1:
            printf("Type an integer value to insert in the queue: ");
            scanf("%d", &value);
            stack_push(S, value);
            break;
        case 2:
            printf("Removing... \n");
            stack_pop(S);
            break;
        case 3:
            printf("Type an index and an intenger value to update: ");
            scanf("%d %d", &index, &value);
            stack_update(S, index, value);
            break;
        case 4:
            stack_print(S);
            break;
        case 5:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            stack_search(S, value);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

