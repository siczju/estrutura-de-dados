/*
    Filas dinâmicas -> não sabe o tamanho máximo, use fila dinâmica, com listas encadeadas, não se preocupando com o tamanho máximo de elementos.
        enfileirar (enqueue) -> adicionar um nó no final com o elemento y no final da lista.
        consultar (peek) -> retornar o valor do nó inicial da lista
        desenfileirar (dequeue) -> remover o nó inicial da lista retornando seu valor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _queue_node
{
    struct _queue_node *next;
    struct _queue_node *prev;
    int val;
} QueueNode, Node;

typedef struct _queue_linkedlist
{
    QueueNode *begin;
    QueueNode *end;
    size_t size;
} QueueLinkedList, Queue;

Node *Node_create(int val)
{
    Node *node = (Node *)calloc(1, sizeof(Node));

    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}

Queue *Queue_create()
{
    Queue *L = (Queue *)calloc(1, sizeof(Queue));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void Queue_destroy(Queue *L)
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

bool Queue_isEmpty(const Queue *L)
{
    return L->size == 0;
}

void Queue_print(Queue *L)
{

    printf("L ->");
    for (Node *pos = L->begin; pos != NULL; pos = pos->next)
    {
        printf(" [%d] ->", pos->val);
    }
    printf(" NULL\n");

    if (Queue_isEmpty(L))
    {
        printf("L->end = NULL\n");
        printf("L->begin = NULL\n");
    }
    else
    {
        printf("L->end = %d\n", L->end->val);
        printf("L->begin = %d\n", L->begin->val);
    }
    printf("L->size = %d\n\n", L->size);
}
void Queue_invertedPrint(Queue *L)
{

    printf("L->end ->");
    for (Node *pos = L->end; pos != NULL; pos = pos->prev)
    {
        printf(" [%d] ->", pos->val);
    }
    printf(" NULL\n");

    if (Queue_isEmpty(L))
    {
        printf("L->end = NULL\n");
        printf("L->begin = NULL\n");
    }
    else
    {
        printf("L->end = %d\n", L->end->val);
        printf("L->begin = %d\n", L->begin->val);
    }
    printf("L->size = %d\n\n", L->size);
}

int Queue_peek(const Queue *q){
    if(Queue_isEmpty(q)){
        printf("(peek) queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return q->begin->val;
}

void Queue_enqueue(Queue *L, int val)
{
    if (Queue_isEmpty(L))
        L->begin = L->end = Node_create(val);
    else
    {
        Node *p = L->end;
        L->end->next = L->end = Node_create(val);
        L->end->prev = p;
    }
    L->size++;
}

int Queue_dequeue(Queue *L)
{
    if(Queue_isEmpty(L)){
        printf("(dequeue) queue is empty\n");
        exit(EXIT_FAILURE);
    }
            Node *p = L->begin;

            // a lista possui apenas 1 unico elemento
            if (L->begin == L->end)
            {
                L->begin = L->end = NULL;
            // possui mais de um elemento
            }else
            {
                L->begin = L->begin->next;
                L->begin->prev = NULL;
            }
            int val = p->val;
            free(p);
            L->size--;
            return val;
        }

void main(){
    Queue *Q = Queue_create();
    int val;

    Queue_print(Q);
 
    // val = Queue_peek(Q);
    // val = Queue_dequeue(Q);

    puts("enqueue: 10");
    Queue_enqueue(Q, 10);
    Queue_print(Q);

    puts("\ndequeue");
    val = Queue_dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);


    puts("enqueue: 10, 20, 30");
    Queue_enqueue(Q, 10);
    Queue_enqueue(Q, 20);
    Queue_enqueue(Q, 30);
    Queue_print(Q);

    puts("\npeek");
    val = Queue_peek(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\ndequeue");
    val = Queue_dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\nenqueue: 40, 50");
    Queue_enqueue(Q, 40);
    Queue_enqueue(Q, 50);
    Queue_print(Q);

    puts("\ndequeue");
    val = Queue_dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\nenqueue: 100, 200");
    Queue_enqueue(Q, 100);
    Queue_enqueue(Q, 200);
    Queue_print(Q);

    Queue_destroy(Q);

}