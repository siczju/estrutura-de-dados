#include <stdio.h>
#include <stdlib.h>

typedef struct _staticqueue{
    size_t size;
    struct _staticqueue *begin;
    struct _staticqueue *end;
} StaticQueue, Queue;