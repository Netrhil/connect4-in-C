#include <stdio.h>
#include <stdlib.h>
#include "connect4.h"



int main(int argc, char *argv[]) { 
    
    inicializar();

    char Player1[] = "Cosme";
    char figuraPlayer1 =  'A';
    
    char Player2[] = "Fulanito";
    char figuraPlayer2 = 'B';

    int turnos = 42;

    while (turnos > 0)
    {   
        printf( "%i", verificarVictoria(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '_'));
        if(turnos % 2 == 0) {
            //juega player 1

         } else {
            //juega player 2
            
        }
        turnos --;
         
    }

    printf("\n Ha ocurrido un empate");

    return 0;
}
