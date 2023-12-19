#include "../include/linked_list.h"

void main(){
    LinkedList *L = LinkedList_create();

    LinkedList_add_first(L, 5);
    LinkedList_add_first(L, 4);
    LinkedList_add_first(L, 2);
    LinkedList_add_first(L, 10);

    LinkedList_print(L);

}