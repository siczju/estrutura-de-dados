// filas circulares estáticas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _staticqueue
{
    int *array;
    long size;     // numero de elementos inseridos na fila
    long capacity; // capacidade máxima que o vetor tem para armazenar
    long begin;
    long end;
} StaticQueue, Queue;

bool queue_isEmpty(const Queue *q)
{
    return q->size == 0;
}
bool queue_isFull(const Queue *q)
{
    return q->size == q->capacity;
}
long queue_size(const Queue *q)
{
    return q->size;
}
void queue_print(const Queue *q)
{
    printf("capacity: %ld\n", q->capacity);
    printf("size: %ld\n", q->size);
    printf("begin: %ld\n", q->begin);
    printf("end: %ld\n\n", q->end);

    long s, i;
    for(s = 0, i = q->begin; s < q->size; s++, i = (i + 1) % q->capacity)
        printf("%d, ", q->array[i]);

    puts("");
}

Queue *queue_create(long capacity)
{
    Queue *q = (Queue *)calloc(1, sizeof(Queue));
    q->capacity = capacity;

    q->array = (int *)calloc(capacity, sizeof(int));
    q->size = 0;
    q->begin = 0;
    q->end = 0;

    return q;
}

void queue_destroy(Queue *q)
{
    free(q->array);
    free(q);
}

// peek
int queue_peek(const Queue *q)
{
    if (queue_isEmpty(q)){
        printf("(queue) list is empty");
        exit(EXIT_FAILURE);
}
    else
        return q->array[q->begin];
}

//  enqueue (enfileirar)
void enqueue(Queue *q, int val)
{
    if (queue_isFull(q))
    {
        printf("(enqueue) list is full\n");
        return;
    }
    else
    {
        q->array[q->end] = val;
        q->end = (q->end + 1) % q->capacity; // funciona qnd o array estorar [] [begin] [end] -> volta p comeco
        q->size++;
    }
}
// dequeue (desinfileirar)
int dequeue(Queue *q)
{

    if (queue_isEmpty(q))
    {
        printf("(dequeue) list is empty");
        exit(EXIT_FAILURE);
    }

    int val = q->array[q->begin];
    q->begin = (q->begin + 1) % q->capacity;
    q->size--;

    return val;
}

int main() {
    StaticQueue *Q = queue_create(5);
    int val;

    queue_print(Q);

     // val = queue_peek(Q);
     //val = dequeue(Q);

    puts("enqueue: 10, 20, 30");
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    queue_print(Q);

    puts("\npeek");
    val = queue_peek(Q);
    printf("val = %d\n", val);
    queue_print(Q);

    puts("\ndequeue");
    val = dequeue(Q);
    printf("val = %d\n", val);
    queue_print(Q);

    puts("\nenqueue: 40, 50");
    enqueue(Q, 40);
    enqueue(Q, 50);
    queue_print(Q);

    puts("\ndequeue");
    val = dequeue(Q);
    printf("val = %d\n", val);
    queue_print(Q);

    puts("\nenqueue: 100, 200");
    enqueue(Q, 100);
    enqueue(Q, 200);
    queue_print(Q);

     // puts("\nenqueue: 99");
     //enqueue(Q, 99);
     //queue_print(Q);

    queue_destroy(&Q);

    return 0;
}