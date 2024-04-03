//      Função para printar a Lista
#include <stdio.h>
#include <stdlib.h>

typedef struct _snode{
    int val;
    struct _snode *next;
} SNode;

typedef struct _linked_list{
    SNode *begin;
} LinkedList;

SNode *SNode_create(int val){
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
} 

LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL;

    return L;
}

LinkedList *LinkedList_add_first(LinkedList *L, int val){
    SNode *snode = SNode_create(val);

    snode->next = L->begin;
    L->begin = snode;
}

void LinkedList_print(const LinkedList *L){
        printf("L ->");
        
    for(SNode *p = L->begin; p != NULL; p = p->next)
        printf(" [%d] -> ", p->val);

        printf("NULL\n");
}

void main() {

    LinkedList *L = LinkedList_create();

    LinkedList_add_first(L, 5);
    LinkedList_add_first(L, 4);
    LinkedList_add_first(L, 2);
    LinkedList_add_first(L, 10);

    LinkedList_print(L);

}
