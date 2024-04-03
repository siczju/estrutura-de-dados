/*
    Pilhas dinâmicas:
     -> pilha implementada com lista encadeada, com as variações que quiser, nesse caso será com lista duplamente encadeada
     -> pq dinâmica? pra horas q vc n sabe a capacidade máxima q sua pilha pode suportar.
     -> não temos mais a variavel "top", pois não temos mais indices, agora o topo da lista será o L->end
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _dinamicnode
{
    struct _dinamicnode *next;
    struct _dinamicnode *prev;
    int val;
} dinamicNode, Node;

typedef struct _dinamicstack
{
    Node *begin;
    Node *end;
    size_t size;
} dinamicStack, Stack;

Node *Node_create(int val)
{
    Node *node = (Node *)calloc(1, sizeof(Node));

    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}

Stack *stack_create()
{
    Stack *s = (Stack *)calloc(1, sizeof(Stack));
    s->begin = NULL;
    s->end = NULL;
    s->size = 0;

    return s;
}

void stack_destroy(Stack *s)
{
    Node *pos = s->begin;

    while (pos != NULL)
    {
        Node *prev = pos;
        pos = pos->next;
        free(prev);
    }
    free(s);
}

bool stack_isEmpty(Stack *s)
{
    return s->size == 0;
}
size_t stack_size(Stack *s)
{
    return s->size;
}

// print | invertedPrint
void stack_print(Stack *s)
{
    if (stack_isEmpty(s))
    {
        printf("(print) list is empty\n");
        return;
    }

    printf("topo = %d\n\n", s->end->val);
    printf("s->size = %d\n\n", s->size);

    printf("s ->");
    for (Node *pos = s->begin; pos != NULL; pos = pos->next)
    {
        printf(" [%d] ->", pos->val);
    }
    printf(" NULL\n");
}
void stack_invertedPrint(Stack *s)
{
    printf("s->end ->");
    for (Node *pos = s->end; pos != NULL; pos = pos->prev)
    {
        printf(" [%d] ->", pos->val);
    }
    printf(" NULL\n");

    if (stack_isEmpty(s))
    {
        printf("s->end = NULL\n");
        printf("s->begin = NULL\n");
    }
    else
    {
        printf("s->end = %d\n", s->end->val);
        printf("s->begin = %d\n", s->begin->val);
    }
    printf("s->size = %d\n\n", s->size);
}

int stack_peek(Stack *s){
    if(stack_isEmpty(s)){
        printf("(peek) list is empty\n");
        return -1;
    }
    return s->end->val;
}

// push
void stack_push(Stack *s, int val)
{
    if (stack_isEmpty(s))
        s->begin = s->end = Node_create(val);
    else
    {
        Node *p = s->end;
        s->end->next = s->end = Node_create(val);
        s->end->prev = p;
    }
    s->size++;
}

int stack_pop(Stack *s)
{
    if (stack_isEmpty(s))
    {
        printf("(pop) list is empty\n");
        return -1;
    }else{
    int val = s->end->val;
    if (s->begin == s->end)
    {
        s->begin = s->end = NULL;
        s->size = 0;
    }
    else
    {
        Node *p = s->end->prev;
        free(s->end);
        s->end = p;
        p->next = NULL;
    }
    s->size--;

    return val;
    }
    return -1;
}

void main()
{
    Stack *S = stack_create();
    int top_val;

    stack_print(S);

     puts("\npeeking");
     top_val = stack_peek(S);
     printf("top_val = %d\n", top_val);

     puts("\npopping");
     top_val = stack_pop(S);
     printf("top_val = %d\n", top_val);
    
    puts("\npushing 0, 10, 20");
    stack_push(S, 0);
    stack_push(S, 10);
    stack_push(S, 20);
    stack_print(S);

    puts("\npeeking");
    top_val = stack_peek(S);
    printf("top_val = %d\n", top_val);

    puts("\npopping");
    top_val = stack_pop(S);
    printf("top_val = %d\n", top_val);
    stack_print(S);

    puts("\npushing 20, 30, 40");
    stack_push(S, 20);
    stack_push(S, 30);
    stack_push(S, 40);
    stack_print(S);

     puts("\npushing 50");
     stack_push(S, 50);
    stack_print(S);

    stack_destroy(S);
}
