#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node{
    struct _node *next;
    struct _node *prev;
    int val;
} Node;

typedef struct _queue{
    Node *begin;
    Node *end;
    size_t size;
} Queue;

Node* node_create(int val){
    Node *newNode = (Node*) calloc(1, sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = val;

    return newNode;
}

Queue* queue_create(){
    Queue* newQueue = (Queue*) calloc(1, sizeof(Queue));
    newQueue->begin = NULL;
    newQueue->end = NULL;

    return newQueue;
}

void queue_print(const Queue *Q){
    
    if(Q->begin == NULL){
        printf("(print) List is empty\n");
        return;
    }

    int i = 0;
    printf("Queue -> ");
    for(Node *aux = Q->begin; i < Q->size; i++, aux = aux->next)
        printf("[%d] -> ", aux->val);
    printf("NULL\n");

    printf("Q->begin= %d\n", Q->begin->val);
    printf("Q->end = %d\n", Q->end->val);
    printf("Q->size = %d\n", Q->size);
}

void queue_search(Queue *Q, int val){
    if(Q->begin == NULL){
        printf("(search) Queue is empty\n");
        return;
    }
    int i = 0;
    for(Node *aux = Q->begin; i < Q->size; i++, aux = aux->next){
        if(aux->val == val){
            printf("The value %d, is in the queue!\n", val);
            return;
        }
    }
    printf("The value %d, isn't in the queue!\n", val);
}

void enqueue(Queue *Q, int val){
    Node *newNode = node_create(val);
    if(Q->begin == NULL)
        Q->begin = newNode;
    else{
    Q->end->next = newNode;
    newNode->prev = Q->end;
    }
    Q->end = newNode;
    Q->size++;
}

void dequeue(Queue *Q){
    if(Q->begin == NULL){
        printf("(dequeue) List is empty\n");
        return;
    }
    if(Q->size == 1){
        free(Q->begin);
        Q->begin = NULL;
        Q->end = NULL;
        Q->size--;
        return;
    }
    Node *aux = Q->begin;
    Q->begin = Q->begin->next;
    Q->begin->prev = NULL;
    free(aux);
    Q->size--;
}

void queue_update(Queue *Q, int index, int val){
    if(index < 0 || index > Q->size){
        printf("Invalid index: %d\n", index);
        return;
    }
    int i = 0;
    for(Node *aux = Q->begin; i <= index; i++, aux = aux->next){
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
    Queue *L = queue_create();
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
            enqueue(L, value);
            break;
        case 2:
            printf("Removing... \n");
            dequeue(L);
            break;
        case 3:
            printf("Type an index and an intenger value to update: ");
            scanf("%d %d", &index, &value);
            queue_update(L, index, value);
            break;
        case 4:
            queue_print(L);
            break;
        case 5:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            queue_search(L, value);
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



