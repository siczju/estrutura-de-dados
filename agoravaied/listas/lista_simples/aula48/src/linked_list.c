#include "linked_list.h"
#include <stdio.h>

typedef struct _snode{
    int val;
    struct _snode *next;
    } SNode; // Simple Node
    
typedef struct _linked_list{
    SNode *begin;
} LinkedList;
