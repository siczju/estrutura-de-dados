#include <stdio.h>
#include <stdlib.h>

    struct horario {
        int horas;
        int minutos;
        int segundos;
    };


void main(){

    void giveValue(struct horario now[5]);
    void readStruct(struct horario now[5]);

    struct horario now[5];

    giveValue(now); // quando for digitar os horarios, digite em 11:22:33
    readStruct(now); 

}

    void giveValue(struct horario now[5]){
        int i;
        for(i = 0; i < 5; i++){
            printf("Digite o %i horario (hh:mm:ss):", i + 1);
            scanf("%i:%i:%i", &now[i].horas, 
                              &now[i].minutos,
                              &now[i].segundos);
            puts("");
        }
    }

    void readStruct(struct horario now[5]){
        int i;
        for(i = 0; i < 5; i++){
            printf("O %i horario e = %i:%i:%i\n", i + 1,
                                                  now[i].horas,
                                                  now[i].minutos,
                                                  now[i].segundos);
        }
    }