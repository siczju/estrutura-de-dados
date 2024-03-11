#include <stdio.h>
#include <stdlib.h>

int main(){

/*
struct horario {
    int horas;
    int minutos; 
    int segundos;
} agora; // ja instanciei uma struct por aqui
*/

struct horario {
    int horas;
    int minutos; 
    int segundos;
} agora = {10, 20, 30}; // ou ja coloco os valores por aqui
// struct horario agora = {10, 20, 30};

    /*struct horario agora;
    agora.horas = 15;
    agora.minutos = 17;
    agora.segundos = 30;
    */ 

    printf("%i:%i:%i\n", agora.horas, agora.minutos, agora.segundos);
 
    return 0;
}
