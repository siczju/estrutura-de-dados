//      Função EFICIENTE de inserção na cauda (fim) da lista
#include <stdio.h>
#include <stdlib.h>

typedef struct _snode{
    int val;
    struct _snode *next;
} SNode;

typedef struct _linked_list{
    SNode *begin;
    SNode *end;                 // NEW  
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
    L->end = NULL;

    return L;
}

void LinkedList_add_first(LinkedList *L, int val){
    SNode *snode = SNode_create(val);

    if (L->begin == NULL) 
       L->end = snode;

    snode->next = L->begin;
    L->begin = snode;
}

void LinkedList_print(const LinkedList *L){
        printf("L ->");
        
    for(SNode *p = L->begin; p != NULL; p = p->next)
        printf(" [%d] -> ", p->val);

        printf("NULL\n");
}

void LinkedList_add_last_slow(LinkedList *L, int val){
    SNode *snode = SNode_create(val);

    if(L->begin == NULL){
        L->begin = snode;
    } else{
        SNode *p = L->begin;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = snode;
    }
}

// temos um ponteiro pro começo da lista (begin), que tal termos um ponteiro para o final(end*) dela? Assim se for inserir outro elemento no final da lista, n precisaria percorrer ela toda (caso fosse varios nós)

void LinkedList_add_last_fast(LinkedList *L, int val){
    SNode *snode = SNode_create(val);

//      se a lista tiver vazia L Begin e L End terão o mesmo valor, pois o ultimo tb é o primeiro
    if(L->begin == NULL){
        L->begin = snode;
        L->end = snode;
    }else{
        L->end->next = snode;
        L->end = snode;
    }
}


void main() {

    LinkedList *L = LinkedList_create();

    LinkedList_add_last_fast(L, 10);
    LinkedList_add_first(L, 5);
    LinkedList_add_first(L, 25);
    LinkedList_add_last_slow(L, 15);
    // vai dar erro se chamar a função slow antes da fast, pois na funcao slow n instancia o end pra nenhum lugar ou seja ele n apontara pra nenhum lugar, por isso da erro, mas se chamar a addfirst primeiro ele apontará para o primeiro nó que pode ser o ultimo em breve, porém se vc usar o add_last_slow ele virará o ultimo mas o end ainda apontará para o penultimo, eh dificil de entender mas eh isso.
     
    LinkedList_print(L);


}
