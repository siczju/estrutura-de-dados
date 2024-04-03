// filas circulares estáticas
#include <stdio.h>
#include <stdlib.h>

/*
    Enfileirar (enqueue) um elemento y:
    Q[end] = y;
    end = (end + 1) % capacity;

    Consultar (peek) um elemento da fila sem remove-lo:
    x = Q[begin]

    Desinfileirar (dequeue) um elemento da fila:
    x = Q[begin]
    begin = (begin + 1) % capacity;
    
*/
/*
typedef struct _staticqueue{
    size_t size;
    struct _staticqueue *begin;
    struct _staticqueue *end;
} StaticQueue, Queue;

Queue* queue_create(int size){
    Queue *q = (Queue*) calloc(1, sizeof(Queue));
    q->size = size;
    q->begin = NULL;
    q->end = NULL;

    return q;
}

//  enqueue (enfileirar)
void enqueue(Queue *q, int val){
    if(queue_isEmpty(q)){
    //  q->data[begin] == val;
        q->end++;     
    } 
    if(q->end == q->size - 1){
        q->end = 0;
    } else{
   // q[end++] = val;
    }
}
    dequeue (desinfileirar) -> retorna  o valor do begin e pula ele pra próxima casa, ou seja:
    [#] [#] [begin] [3] [4] [end] []

    [#] [#] [#] [begin] [4] [end] []


void dequeue(Queue *q){
    
    // x = q[begin++];
    // return x;
    
}
*/