// também criarei uma pasta chamada include, onde colocarei todos os arquivos de cabeçalho ".h"
// agora não podemos compilar igual pois o cabeçalho está em outra pasta, teremos que adicionar mais uma coisa na compilação
// gcc -c float_vector.c -I include/ -o obj/float_vector.o // informamos por meio do -I procurar dependencias do floatvector na pasta include
// também podemos deixar diretamente no include "#include "../include/float_vector.h"