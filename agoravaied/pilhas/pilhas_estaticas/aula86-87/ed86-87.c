/*
    Pilha -> um elemento em cima do outro (pilha)
    -> onde se quisermos colocar um novo livro na pilha, a gente coloca ele no topo (empilhar), se a pilha 
    estiver vazia, empilhariamos o primeiro elemento. 
    -> mas se quisermos desimpilhar (remover elementos), o ideal seria pegar o primeiro elemento (do topo) e remover ele da pilha.

    -> em termos computacionais, uma pilha seria uma lista linear não necessariamente encadeada, uma sequência de elementos um atras do outros.
    -> na qual as funções de inserção e de remoção seria efetuadas sempre num mesmo extremo, denominado o topo a pilha, ou seja se quisermos desimpilhar, tira do topo, se quisermos empilhar inserimos no topo.

    -> LIFO -> Last In First Out (primeiro elemento a entrar, é o ultimo a sair)

    -> empilhar -> push (inserindo no topo)
    -> desimpilhar -> pop (removendo do topo)

    -> nunca conseguimos tirar ou colocar elementos no meio ou no começo da pilha, obrigatoriamente é no final.

        Tipos de Pilha:
    -> Pilhas Estáticas -> implementadas com vetores. -> então a sequência de elementos será um vetor de elementos. -> Nessa pilha você cria ela com um tamanho máximo ou seja n pode diminuir nem aumentar.
        [  ] ..
   topo [10] - 2
        [20] - 1
        [30] - 0
    
    -> terá uma váriavel topo que guarda o indice do ultimo elemento colocado na pilha, pois a pilha pode ter 100 espaços mas só 30 que armazenam algo, por isso guardar o indice do ultimo elemento.

    -> Pilhas dinâmicas -> Implementada com listas encadeadas -> Podem aumentar e diminuir dinâmicamente. -> Disponibilizando pro usuário apenas a função pop e push.
*/