/*

  para copiar de uma pasta para a outra -> cp -R ../../aula40/ex06/* . -> voce tem que estar dentro da pasta que você quer colar os arquivos
  dar o comando "cp -R (e o endereço da pasta que você quer copiar) ."


  Makefile:

  all: // comando padrão
  echo "" // printf -> tem q ter indentação obrigatoriamente com tab, exemplo:
all:
  echo "Oi oi oi"  

  make -> executa o makefile

  além do "all" que é padrão podemos fazer os nossos proprios, o all é tipo o main e o outros são funções diferentes

  make -> executa só a primeira função (all)
  para executar as outras funções temos que colocar o nome na frente, por exemplo se tivermos uma função chamada hello: make hello
*/