/*

 Se vc muda somente um arquivo, e agora quer compilar ele novamente, tem um jeito de compilar somente ele e não a biblioteca inteira com ele:
  No makefile se vc definiu um target (all libed myapps %.o:) com o nome de um arquivo compilado, ela só será chamada em duas situações:
  1º O arquivo nao existir e a lista de dependencias esta completa ou seja nao tem dependencias, ela será chamada.
  2º Se o arquivo existir só sera chamada se ao menos 1 dos arquivos de dependencias tiver sido alterado depois da ultima compilação

  Assim impedimos que ele seja compilado varias vezes sem precisar. Essa explicação acima foi baseada no código que fizemos no makefile na aula passada

    $(OBJ)/%.o:
    com esse código agora podemos usar:
    ./obj/float_vector.o
*/