APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps
	echo "Chama e executa os dois targets (libed e myapps)"	 
	
libed:
	echo "Compila os arquivos das bibliotecas"
	gcc -c ${SRC}/float_vector.c -I ${INCLUDE} -o ${OBJ}/float_vector.o
	gcc -c  ${SRC}/mytime.c -I ${INCLUDE} -o ${OBJ}/mytime.o

myapps:	
	echo "Compila todos os programas executaveis(aplicativos)"	 
	gcc ${APPS}/app.c ${OBJ}/*.o -I ${INCLUDE} -o ${BIN}/app 
	gcc ${APPS}/app_com_mytime.c ${OBJ}/*.o -I ${INCLUDE} -o ${BIN}/app_com_mytime

run: 
	echo "Roda(ndo) um programa"
	./bin/app_com_mytime
	
clean:
	del /Q bin
	del /Q obj
	
