APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps
	
libed: \
	$(OBJ)/float_vector.o	\
	$(OBJ)/mytime.o


myapps:	\
	$(BIN)/app	\
	$(BIN)/app_com_mytime


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	 gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c 
	 gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run: 
	echo "Roda(ndo) um programa"
	$(OBJ)/app
	
clean:
	del /Q bin
	del /Q obj
	
