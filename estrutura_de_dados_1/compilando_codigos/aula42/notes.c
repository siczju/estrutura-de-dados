/*

 para copiar os conteudos de uma pasta para a outra com o "cp -R pastacopy pastapaste", temos que estar dentro da pasta root
 copy que é a que você quer copiar e colar os conteudos para a outra, no caso da makefile01 é a aula41

 para apagar apagar no windows q nem o "rm", é so usar o del /Q

 primeiramente compilar os arquivos .h e .c pra depois compilar os programas 

 no makefile eu consigo ter variaveis:
 então se eu coloco "SRC = ./src"
 -> invés de fazer assim: gcc -c ./src/float_vector.c -I ./include -o ./obj/float_vector.o
 -> consigo fazer assim: gcc -c ${SRC}/float_vector.c -I ./include -o ./obj/float_vector.o
 -> ou seja tem q colocar a variavel entre ${} 

 invés de ficar escrevendo toda hora (make myapps e make libed) podemos colocalos na frente do all (all: libed myapps) que quando executarmos
 o all (make) executará os dois na sequência, sendo obrigatorio estar na mesma linha do all (all: libed myapps)

 libed -> biblioteca de estrutura de dados
*/