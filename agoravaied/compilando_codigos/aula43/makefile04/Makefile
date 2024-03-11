APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps
	echo "Chama e executa os dois targets (libed e myapps)"	 
	
libed: float_vector.o mytime.o
	echo "Compila os arquivos das bibliotecas"

myapps:	
	echo "Compila todos os programas executaveis(aplicativos)"	 
	gcc ${APPS}/app.c ${OBJ}/*.o -I ${INCLUDE} -o ${BIN}/app 
	gcc ${APPS}/app_com_mytime.c ${OBJ}/*.o -I ${INCLUDE} -o ${BIN}/app_com_mytime

%.o: $(SRC)/%.c $(INCLUDE)/%.h
	 gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@

run: 
	echo "Roda(ndo) um programa"
	./bin/app_com_mytime
	
clean:
	del /Q bin
	del /Q obj
	
