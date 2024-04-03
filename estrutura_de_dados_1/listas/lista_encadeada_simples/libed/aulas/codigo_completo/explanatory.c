#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura do nó da lista
typedef struct _snode
{
    int val;             // Valor armazenado no nó
    struct _snode *next; // Ponteiro para o próximo nó
} SNode;

// Definição da estrutura da lista encadeada
typedef struct _linkedlist
{
    SNode *begin; // Ponteiro para o primeiro nó da lista
    SNode *end;   // Ponteiro para o último nó da lista
    size_t size;  // Tamanho da lista
} LinkedList;

// Função para criar um novo nó com um valor específico
SNode *SNode_create(int val)
{
    // Aloca memória para o novo nó
    SNode *node = (SNode *)calloc(1, sizeof(SNode));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Define o valor do nó e o próximo nó como NULL
    node->val = val;
    node->next = NULL;

    return node;
}

// Função para criar uma nova lista encadeada vazia
LinkedList *list_create()
{
    // Aloca memória para a nova lista
    LinkedList *list = (LinkedList *)calloc(1, sizeof(LinkedList));
    if (list == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa os ponteiros de início e fim da lista como NULL e o tamanho como 0
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

// Função para imprimir os elementos da lista encadeada
void list_print(const LinkedList *L)
{
    printf("L -> ");

    // Percorre a lista e imprime os valores de cada nó
    for (SNode *prev = L->begin; prev != NULL; prev = prev->next)
    {
        printf("[%d] -> ", prev->val);
    }
    printf("NULL\n");

    // Imprime o valor do último nó, se existir
    if (L->end == NULL)
        printf("L->end = NULL\n");
    if (L->end != NULL)
        printf("L->end = %d\n", L->end->val);

    // Imprime o tamanho da lista
    printf("L->size = %zu\n", L->size);
}

// Função para verificar se a lista está vazia
bool list_isEmpty(LinkedList *L)
{
    return L->size == 0;
}

// Função para retornar o tamanho da lista
size_t list_size(const LinkedList *L)
{
    return L->size;
}

// Função para adicionar um novo nó no início da lista
void list_addFirst(LinkedList *L, int val)
{
    // Cria um novo nó com o valor especificado
    SNode *node = SNode_create(val);

    // Se a lista estiver vazia, o novo nó será o início e o fim da lista
    if (list_isEmpty(L))
        L->begin = L->end = node;
    // Caso contrário, o novo nó será adicionado no início da lista
    else
    {
        node->next = L->begin; // O próximo nó do novo nó será o atual início da lista
        L->begin = node;       // O novo nó será o novo início da lista
    }
    L->size++; // Incrementa o tamanho da lista
}

// Função para adicionar um novo nó no final da lista
void list_addLast(LinkedList *L, int val)
{
    // Cria um novo nó com o valor especificado
    SNode *node = SNode_create(val);

    // Se a lista estiver vazia, o novo nó será o início e o fim da lista
    if (list_isEmpty(L))
        L->begin = L->end = node;
    // Caso contrário, o novo nó será adicionado no final da lista
    else
    {
        L->end->next = node; // O próximo nó do atual último nó será o novo nó
        L->end = node;       // O novo nó será o novo fim da lista
    }
    L->size++; // Incrementa o tamanho da lista
}

// Função para remover o primeiro nó com um valor específico da lista
void list_removeNode(LinkedList *L, int value)
{
    SNode *prev = NULL; // Ponteiro para o nó anterior
    SNode *pos = L->begin; // Ponteiro para o nó atual

    // Percorre a lista até encontrar o nó com o valor especificado ou o final da lista
    while (pos != NULL && pos->val != value)
    {
        prev = pos; // Atualiza o ponteiro para o nó anterior
        pos = pos->next; // Avança para o próximo nó
    }

    // Verifica se o nó com o valor especificado foi encontrado na lista
    if (pos == NULL)
    {
        printf("Node with value %d not found in the list\n", value);
        return;
    }

    // Verifica se o nó a ser removido é o primeiro nó da lista
    if (prev == NULL)
        L->begin = pos->next; // Atualiza o início da lista para o próximo nó
    else
        prev->next = pos->next; // Atualiza o ponteiro do nó anterior para o próximo nó, pulando o nó a ser removido

    // Verifica se o nó a ser removido é o último nó da lista
    if (pos->next == NULL)
        L->end = prev; // Atualiza o fim da lista para o nó anterior, pois ele se tornará o último nó

    L->size--; // Decrementa o tamanho da lista
    free(pos); // Libera a memória alocada para o nó removido
}

void list_destroy(LinkedList *L)
{
    SNode *remove = NULL;
    SNode *p = L->begin;

    // Percorre a lista e libera a memória de cada nó
    while (p != NULL)
    {
        remove = p;
        p = p->next;
        free(remove);
    }
    free(L); // Libera a memória alocada para a estrutura da lista
}

// Função para inserir um elemento em uma posição escolhida pelo usuário
void list_insertElementInUserChoose(LinkedList *L, int index, int value)
{
    // Verifica se a lista está vazia
    if (list_isEmpty(L))
    {
        printf("List is empty\n");
        return;
    }
    // Verifica se o índice fornecido pelo usuário está dentro dos limites da lista
    if (index < 0 || index > list_size(L))
    {
        printf("Invalid Index: %d\n", index);
        return;
    }

    // Caso o índice seja 0, insere o elemento no início da lista
    if (index == 0)
    {
        list_addFirst(L, value);
        return;
    }
    // Caso o índice seja igual ao tamanho da lista, insere o elemento no final da lista
    if (index == L->size)
    {
        list_addLast(L, value);
        return;
    }

    // Percorre a lista até encontrar a posição desejada
    SNode *p = L->begin;
    SNode *aux = NULL;
    SNode *newnode = SNode_create(value);
    int i = 0;

    while (index != i)
    {
        aux = p;
        p = p->next;
        i++;
    }
    aux->next = newnode; // Atualiza o ponteiro next do nó anterior para apontar para o novo nó
    newnode->next = p;   // Atualiza o ponteiro next do novo nó para apontar para o nó seguinte
    L->size++;           // Incrementa o tamanho da lista
}

// Função para inverter a ordem dos elementos da lista
void list_reverse(LinkedList *L)
{
    LinkedList *aux = list_create(); // Cria uma lista auxiliar

    SNode *pL = L->begin; // Inicia a variável pL no início da lista original

    // Percorre a lista original do final para o início
    for (int i = L->size - 1; i >= 0; i--)
    {
        list_addFirst(aux, pL->val); // Adiciona cada elemento no início da lista auxiliar
        pL = pL->next;                // Avança para o próximo elemento da lista original
    }

    // Atualiza os ponteiros da lista original para os ponteiros da lista auxiliar
    L->begin = aux->begin;
    L->end = aux->end;
    L->size = aux->size;

    free(aux); // Libera a memória alocada para a lista auxiliar
}

// Função para clonar uma lista
LinkedList *list_clone(const LinkedList *L)
{
    LinkedList *clone = list_create(); // Cria uma nova lista para armazenar o clone
    SNode *current = L->begin;         // Inicia a variável current no início da lista original

    // Percorre a lista original e adiciona cada elemento na lista clone
    while (current != NULL)
    {
        list_addLast(clone, current->val);
        current = current->next;
    }
    return clone;
}

// Função para remover todos os nós de uma lista
void list_removeAllNodes(LinkedList *L)
{
    SNode *current = L->begin; // Inicia a variável current no início da lista

    // Percorre os nós da lista e remove cada nó usando list_removeNode
    while (current != NULL)
    {
        SNode *temp = current;         // Salva uma referência ao nó atual
        current = current->next;       // Avança para o próximo nó
        list_removeNode(L, temp->val); // Remove o nó atual usando list_removeNode
    }
}

// Função para concatenar duas listas
void list_concatenate(LinkedList *L1, LinkedList *L2)
{
    // Verifica se alguma das listas está vazia
    if (list_isEmpty(L1) || list_isEmpty(L2))
    {
        printf("Cannot concatenate empty lists\n");
        return;
    }

    SNode *p = L1->end; // Inicia a variável p no último nó da lista L1
    p = L2->begin;       // Atualiza a variável p para o início da lista L2
    L1->end = L2->end;   // Atualiza o ponteiro de fim da lista L1 para o fim da lista L2
    L1->size += L2->size; // Atualiza o tamanho da lista L1 somando o tamanho da lista L2

    list_destroy(L2); // Libera a memória alocada para a lista L2
}

// Função para inserir um elemento de forma ordenada em uma lista
void list_insertOrdered(LinkedList *L, int value)
{
    SNode *newNode = SNode_create(value); // Cria um novo nó com o valor fornecido

    // Verifica se a lista está vazia ou se o valor é menor que o valor do primeiro nó
    if (list_isEmpty(L) || value < L->begin->val)
    {
        list_addFirst(L, value); // Adiciona o elemento no início da lista
        return;
    }

    SNode *prev = NULL;
    SNode *pos = L->begin;

    // Percorre a lista até encontrar a posição correta para inserir o novo nó
    while (pos != NULL && value > pos->val)
    {
        prev = pos;
        pos = pos->next;
    }
    newNode->next = pos; // Atualiza o ponteiro next do novo nó para apontar para o nó seguinte
    prev->next = newNode; // Atualiza o ponteiro next do nó anterior para apontar para o novo nó

    // Se o nó atual for nulo, significa que o novo nó foi inserido no final da lista
    if (pos == NULL)
        L->end = pos;

    L->size++; // Incrementa o tamanho da lista
}

// Função para ordenar uma lista
void list_sort(LinkedList *L)
{
    // Verifica se a lista possui tamanho 1 ou menos, que já está ordenada
    if (L->size <= 1)
        return;

    LinkedList *aux = list_create(); // Cria uma lista auxiliar para armazenar os elementos ordenados

    // Percorre a lista original e insere cada elemento na lista auxiliar de forma ordenada
    for (SNode *p = L->begin; p != NULL; p = p->next)
        list_insertOrdered(aux, p->val);

    list_destroy(L); // Libera a memória da lista original

    // Atualiza os ponteiros da lista original para os ponteiros da lista auxiliar
    L->begin = aux->begin;
    L->end = aux->end;

    free(aux); // Libera a memória alocada para a lista auxiliar
}

// Função principal
void main()
{
    LinkedList *L = list_create(); // Cria uma lista

    // Adiciona alguns elementos à lista
    list_addFirst(L, 12);
    list_addLast(L, 14);
    list_addFirst(L, 21);
    list_addLast(L, 45);

    list_removeNode(L, 12); // Remove um nó da lista

    // Insere um elemento na posição especificada pelo usuário
    list_insertElementInUserChoose(L, 1, 3);

    list_reverse(L); // Inverte a ordem dos elementos da lista

    // list_userValue(L, 2); // A função list_userValue não está implementada

    list_sort(L); // Ordena a lista

    list_print(L); // Imprime a lista
}
