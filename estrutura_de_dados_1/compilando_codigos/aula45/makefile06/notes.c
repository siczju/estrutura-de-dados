/*

mesma coisa que fizemos no libed só que agora no myapps

make ./bin/app
.bin/app: ./apps/app.c 
% ==> app

$(BIN)/%: $(APPS)/%.c 
	 gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@
	 gcc ./apps/app.c ./pbj/*.o -I ./include -o ./bin/app

*/