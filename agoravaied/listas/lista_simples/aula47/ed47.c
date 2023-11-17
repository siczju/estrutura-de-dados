//              Listas Encadeadas Simples | Linked List
/*

    Problema nos vetores:
    -> suponha que queremos armazenar uma lista de alunos em um array, sabendo, inicialmente, que a qtde de alunos é 5. Então alocamos um
    vetor de 5 posições e inserimos os alunos

    Aluno **alunos = (Aluno**) calloc(5, sizeof(Aluno*));
    for(int i = 0; i < 5; i++)
        alunos[i] = create_aluno();

    Agora suponha que queremos adicionar um novo aluno, porém o vetor não tem espaço suficiente, o que fazer?
    -> Opção 1 -> Usar a função "realloc" que realoca um espaço de memória(comando perigoso) se mal usado, acarretará em perda de dados
    -> Opção 2 -> Criar um novo vetor com 6 posições e copiar todos os valores do antigo vetor e adicionar o novo aluno    
                  porém tem problemas, a cada aluno novo precisaremos alocar um novo vetor (ineficiente)     


    Listas Encadeadas:
    -> representação de uma sequência de elementos/objetos na memória do computador, os elementos(nós da lista) são armazenados em posições
       quaisquer da memória e são ligados por ponteiros.
    -> Logo, elementos consecutivos da lista não ficam necessariamente em posições consecutivas na memória
    -> sequencia de nós(struct) encadeados, onde esse nó vai ter um campo que terá um ponteiro que apontará pro próximo elemento
    -> para indicar o fim da lista, não tem um elemento para indicar que é o fim, não tem próximo elemento, acabou, apontará pra NULL
    -> cada nó contem um elemento/objeto de determinado tipo e um ponteiro para o próximo elemento da lista

    -> as setas "->" são ponteiros
    -> os números entre colchetes são os "nós", que armazenam valor inteiro

    L ->  [10] ->  [2] ->  [4]   ->   [5]  ->  [7]
    L -> [Jão] -> [Zé] -> [Felp] -> [Juca] -> [Lili]

    -> Listas circulares -> loop, o ultimo nó apontará pro primeiro elemento da lista

     L ->  [10]  ->  [2]    ->  [4]  
     L -> [Zelo] -> [Cezin] -> [Felipe]
           ^ - - - - - - - - - - - - ^

    -> Listas duplamente encadeadas -> cada nó tem um ponteiro que aponta pro próximo elemento e pro anterior   
    -> tendo dois ponteiros um pra indicar o próximo elemento e um para indicar o anterior
    -> no primeiro nó da lista o ponteiro que aponta para o anterior É NULO (porque não tem valor anterior ao primeiro)
    -> no ultimo nó da lista o ponteiro que aponta para o posterior É NULO (porque não tem valor posterior ao ultimo)
    
       L -> [10] -> [2] -> [4]  
       L -> [10] <- [2] <- [4]

     -> listas circulares duplamente encadeadas -> mesma coisa que a duplamente mesclada com a circular onde:
     -> no ultimo nó o ponteiro posterior apontará pro primeiro nó
     -> no primeiro nó o ponteiro anterior apontará pro ultimo nó

            | - - - - - - - - - - |
     L ->  [10]  ->  [2]    ->  [4]  
     L -> [Zelo] -> [Cezin] -> [Felipe]  
            | - - - - - - - - - - - |
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    
}
