#include <stdio.h> 

void main(){
    puts("Hello");
}

// gcc test.c -o qualquercoisa -> compila
// ./qualquercoisa -> mostra no terminal

// porém nesse curso depois do -o sempre usaremos o nome do arquivo sem ".", ou seja só test
// gcc test.c -o test

// gcc -c float_vector.c -> usamos o "-c" quando não tem main, qnd n é um arquivo de execução

// para copiar arquivos para sua pasta -> "cp ../nomedoarquivo"