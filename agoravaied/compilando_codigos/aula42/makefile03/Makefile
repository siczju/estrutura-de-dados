APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: 
	echo "Compila todos os arquivos da nossa biblioteca"	
	gcc -c ${SRC}/float_vector.c -I ${INCLUDE} -o ${OBJ}/float_vector.o
	gcc -c  ${SRC}/mytime.c -I ${INCLUDE} -o ${OBJ}/mytime.o 
	gcc ${APPS}/app.c ${OBJ}/*.o -I ${INCLUDE} -o ${BIN}/app 
	gcc ${APPS}/app_com_mytime.c ${OBJ}/*.o -I ${INCLUDE} -o ${BIN}/app_com_mytime

run: 
	echo "Roda(ndo) um programa"
	./bin/app_com_mytime
	
clean:
	del /Q bin
	del /Q obj
	
