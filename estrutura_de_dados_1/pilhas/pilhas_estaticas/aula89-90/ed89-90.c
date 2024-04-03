#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_estatica{
    size_t size;
    int top;
    int *array;
} StaticStack, Stack;

Stack* stack_create(size_t size){
    Stack *newStack = (Stack*) calloc(1, sizeof(Stack));
    newStack->size = size;
    newStack->array = (int*) calloc(newStack->size, sizeof(int)); // cria o vetor
    newStack->top = -1;

    return newStack;
}

void stack_destroy(Stack *s){
    free(s->array); // primeiro desaloca o vetor
    free(s); // depois a struct
}
bool stack_isEmpty(const Stack *s){
    return s->top == -1;
}
bool stack_isFull(const Stack *s){
    return s->top == s->size - 1;
}

void stack_push(Stack *s, int val){
    if(stack_isFull(s)){
        printf("(push) Stack is full\n");
        return;
    }
    s->array[++s->top] = val;
}
int stack_pop(Stack *s){
    if(stack_isEmpty(s)){
        printf("(pop) List is empty\n");
        return;
    }
    int val = s->array[s->top];
    s->top--;
    return val;
}
int stack_peek(const Stack *s){
    if(stack_isEmpty(s)){
        printf("(peek) List is empty\n");
        return;
    }
    return s->array[s->top];
}

void stack_print(const Stack *s){
    if(stack_isEmpty(s)){
        printf("(print) List is empty\n");
        return;
    }

    printf("size: %d\n", s->size);
    printf("top: %d\n", s->top + 1);
    
    for(int i = 0; i < s->top + 1; i++){
        printf("[%d] ", s->array[i]);
    }
    puts("");
}

int main() {
    StaticStack *S = stack_create(5);
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
    stack_print(S);

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

    return 0;
}