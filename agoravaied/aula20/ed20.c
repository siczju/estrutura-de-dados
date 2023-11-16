// matrizes estáticas e dinâmicas

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
    S000 | [#] | [0] [0] -> &m == m = S000
    

*/

#include <stdio.h>
#include <stdlib.h>

void main(){

}