#include <stdio.h>

void main(){

    typedef struct horario {
        int horas;
        int minutos;
        int segundos;
    } horas;

    horas agora;
    agora.horas = 15;
    printf("%d",agora.horas);


}