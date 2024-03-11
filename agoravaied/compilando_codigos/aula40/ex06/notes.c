/*

  pasta include -> deixar os arquivos de cabeçalhos .h
  pasta obj -> deixar todos arquivos compilados do tad .o
  pasta src (source = fonte) -> deixar os arquivos fontes (implementação do tipo abstratos de dados)
  pasta apps -> colocar todos os programas da nossa biblioteca, todos os executaveis
  pasta bin  -> guarda todos os programas compilados -> arquivos binários dos programas

remover arquivo (rm) -> rm obj/* -> irá remover todos os arquivos da pasta obj
  ver a arvore (tree) -> ver arvore do seu projeto

  mover arquivo para uma pasta (mv) -> mv mytime.h include/
                                       mv mytime.c src/

  ver o codigo de um arquivo (cat) -> cat apps/app.c

  logo após eu passar o código fonte do programa pra ser compilado, eu informo os arquivos obj que eu quero usar na compilação:
  -> gcc ./apps/app.c ./obj/float_vector.o -I ./include/ -o ./bin/app
  -> "./apps/app.c ./obj/float_vector.o"
  -> faço isso pois senão seria sem as funções implementadas, só as declaradas no .h, não as feitas no .c (que está compilada no .o)

  ai para executar -> ./bin/app

  ultima compilação:
  -> gcc ./apps/app_com_mytime.c ./obj/float_vector.o ./obj/mytime.o -I ./include -o ./bin/app_com_mytime 
    ou
  -> gcc ./apps/app_com_mytime.c ./obj/*.o -I ./include -o ./bin/app_com_mytime 
  
*/