// matrizes estáticas 

/*

    Alocação Estática

    int m[2][3];

     [2]      [3]
    linhas | Colunas

           0   1   2
    m = 0 [#] [#] [#]
        1 [#] [#] [#]
           - > -> ->

    S024
    S020 | [#] | [1] [2] 
    S016 | [#] | [1] [1]
    S012 | [#] | [1] [0] -> matriz na memória (24 bytes)
    S008 | [#] | [0] [2]
    S004 | [#] | [0] [1]
    S000 | [#] | [0] [0] -> &m == m = S000 = &m[0][0]
    
    int m[2][3] = {{0, 1, 2}, 
                   {3, 4, 5}};
     
           0   1   2
    m = 0 [0] [1] [2]
        1 [3] [4] [5]

*/

#include <stdio.h>
#include <stdlib.h>

void main(){

    // codifique um programa que aloque uma matriz estática e imprima o endereço de cada elemento da matriz

    int rows = 2;
    int cols = 3;

    int m[2][3] = {{0, 1, 2}, {3, 4, 5}};

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf(" %d", m[i][j]);
        }
        puts("");
    }


        puts("");

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf(" &m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }

}