/*

  pasta include -> deixar os arquivos de cabeçalhos .h
  pasta obj -> deixar todos arquivos compilados do tad .o
  pasta src (source = fonte) -> deixar os arquivos fontes (implementação do tipo abstratos de dados)

  para compilar -> na outra aula tinhamos que passar o "gcc -c" pois não tem main, porém agora nosso arquivo não está mais no diretório root
  ele está na pasta source -> src/float_vector.c -> ficaria "gcc -c ./src/float_vector.c -I ./include -o ./obj/float_vector.o" 

  -I -> considere buscar arquivos que são complementares pro meu .c nessa tal pasta
  ./ -> diretório atual
  -c -> considere que não é um arquivo executavel(não tem main)
  -o -> gere o arquivo compilado nesta pasta e com esse nome
  
*/