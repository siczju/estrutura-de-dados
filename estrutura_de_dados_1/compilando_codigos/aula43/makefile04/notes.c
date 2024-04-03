/*

rapaz é um negocio muito doido.
mas vo tentar explicar:

make float_vector.o
% ==> float_vector (não necessariamente vai ser o float_vector, pode ser qualquer um como o mytime.c)

$< = usado pra acessar a primeira dependencia, que nesse caso por queremos compilar o float_vector.o é o = float_vector.c
$@ = usado pra acessar exatamente o nome da target que falamos no inicio (make float_vector.o)  que é    = float_vector.o

%.o: $(SRC)/%.c $(INCLUDE)/%.h
	 gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@

-> é tipo um if else, se tem .o no final, verifica se na pasta src tem o .c do mesmo arquivo, ou seja se ele colocou make mytime.o, o programa vai verificar se tem mytime.c na pasta src e o mesmo na pasta include, mas procurando o arquivo mytime.h.

-> ai se tiver os dois arquivos na pasta src e na include, ele vai rodar:
    gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@
            que é a mesma coisa que:
    gcc -c $(SRC)/float_vector.c -I $(INCLUDE) -o $(OBJ)/float_vector.o

-> ai colocamos o float_vector.o e o mytime.o na frente do libed que não precisará dos codigos anteriores pois rodará sozinho graças a essas dependencias ai novas.
*/