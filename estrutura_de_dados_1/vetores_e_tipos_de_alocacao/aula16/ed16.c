//      Alocação dinâmica na prática

/*

  calloc -> irmão do malloc -> aloca um bloco de bytes consecutivos na memória heap e inicializa todos os valores com 0 (NULL p ponteiros) 
  ou seja se você quer alocar um bloco (vetor) de 10 inteiros, por padrão o calloc ele vai colocar o valor 0 lá, enquanto no malloc
  ele aloca mas deixa o lixo lá já no calloc pra evitar acessar coisas que não foram atribuidas (lixo) o calloc ele ja atribue 0 pra todos.
  no caso de int = 0; float = 0.0; ponteiro = NULL... E a estrutura da função do calloc é um pouco diferente enquanto no malloc você tem
  que fazer n (tamanho do vetor) vezes o tamanho do tipo da variavel para saber quantos bytes ele tem que armazenar na memória para alocar
  esses valores, no calloc você passa dois parâmetros calloc(qtd de elementos, tamanho dos elementos) -> tipo* v = calloc(n, sizeof(tipo)); 

  ex: alocar na memória heap um vetor de  5 floats
  -> float *v = (float*) calloc(5, sizeof(float));

  -> calloc assim como o malloc ele retorna o endereço base,

          |  H220  
          |  H216 [0.0] 4 /
    Heap  |  H212 [0.0] 3 /
          |  H208 [0.0] 2 / - -> float *v = (float*) calloc(5, sizeof(float)
          |  H204 [0.0] 1 /
          |  H200 [0.0] 0 / v[3] -> (v + 3) -> (v + (3 * sizeof(float)) -> (v + (3 * 4)) -> (H200 + 12) -> H212 -> v[3] 

   Stack  | S100 [H200] v

    Sumário!
    -> alocar na memória heap -> calloc e malloc (estão na biblioteca <stdlib.h)
    -> nós só conseguimos acessar a região de memória heap através de ponteiros (por causa dos endereços), já na stack ja acessamos 
       diretamente na variáveis que são declaradas la

*/
#include <stdio.h>
#include <stdlib.h> // contém o NULL, calloc, malloc, free

void main(){

    // alocacao de um vetor estático (memória stack)
    int vstack[5] = {0, 10, 20, 40, 50};
    
    puts("--- vetor estatico ---");
    printf("&vs = %p, vs = %p\n", &vstack, vstack);

    for(int i = 0; i < 5; i++)
        printf("&vstack[%d] = %p, vstack[%d] = %d\n", i, &vstack[i], i, vstack[i]);

    puts("\n"); // pular linha 2 vezes pois o puts pula uma automaticamente
    
    // alocacao de um vetor dinâmica (memória heap)
    int *vheap = (int*) calloc(5, sizeof(int)); 
    vheap[2] = 2; // muda o valor normalmente

    puts("--- vetor dinamico ---");
    printf("&vheap = %p, vheap = %p\n", &vheap, vheap);

    for(int i = 0; i < 5; i++)
        printf("&vheap[%d] = %p, vheap[%d] = %d\n", i, &vheap[i], i, vheap[i]);

}