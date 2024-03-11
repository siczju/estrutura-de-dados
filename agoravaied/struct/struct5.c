#include <stdio.h>

void main(){

    struct horario {
        int horas;
        int minutos;
        int segundos;
    };

    struct horario teste[5]; // vetor de struct

    teste[0].horas = 10;
    teste[3].minutos = 20;
    teste[5].segundos = 30;

    printf("%i:%i:%i", teste[0].horas, teste[3].minutos, teste[5].segundos);

}