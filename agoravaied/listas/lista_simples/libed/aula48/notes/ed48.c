//          Listas Encadeadas - Definição dos Tipos

/*

    Uma lista encadeada é uma sequência de nós
    Se o ponteiro L aponta para o primeiro nó da Lista, podemos dizer que L é uma lista

    typedef struct _node{
        int val;
        struct _node *next; // não fizemos Node *next; -> pois ele ainda não sabia que chamava Node -> está embaixo
    } Node; // apelido da struct

    Representação da struct:

            NODE        NODE        NODE
    L -> [10(val)] -> [2(val)] -> [4(val)]

    -> outra implementação -> seria ter um tipo próprio [begin] para a Lista, que guardará um ponteiro para seu início
    -> e os nós seriao uma outra struct diferente
    -> além de tudo isso esse jeito de implementar da liberdade para guardamos outras informações, como o número de nós, outros ponteiros...

     typedef struct _node{  |   typedef struct _linked_list{}
        int val;            |       Node *begin;
        struct _node *next; |   } LinkedList;
    } Node;                 |


          LinkedList     NODE    NODE
    L -> [ begin ]  ->  [10] ->  [2]
    
*/