#include <stdio.h> 

void main(){
    puts("Hello");
}

// gcc test.c -o qualquercoisa -> compila
// ./qualquercoisa -> mostra no terminal

// porém nesse curso depois do -o sempre usaremos o nome do arquivo sem ".", ou seja só test
// gcc test.c -o test

// se a gente compilar um arquivo .c que não tem MAIN a gente usa -c "gcc -c NomeDoArquivo -o"  e o resultado sera "NomeDoArquivo.o" 

// para copiar arquivos para sua pasta -> "cp ../nomedoarquivo"