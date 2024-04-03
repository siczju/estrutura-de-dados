#include <stdio.h>
#include <stdlib.h>

struct horario {// struct global se nao nao da pra fazer uma função com structs(pois não saberá que ela existe)
    int horas;
    int minutos;
    int segundos;
};

int main(){

    struct horario teste(struct horario x);

    struct horario agora;
    agora.horas = 15;
    agora.minutos = 17;
    agora.segundos = 30;

    struct horario proxima;
    proxima = teste(agora);
    printf("%i:%i:%i\n", proxima.horas, proxima.minutos, proxima.segundos);


    return 0;
}

struct horario teste(struct horario x){

    printf("%i:%i:%i\n", x.horas, x.minutos, x.segundos);
    x.horas = 100;
    x.minutos = 100;
    x.segundos = 100;
    return x;
 }