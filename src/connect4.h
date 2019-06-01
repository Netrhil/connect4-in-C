#include <stdio.h>
#include <stdlib.h>


struct ficha { 
   char tipo;
};

struct ficha **tablero;

int i, j, n = 6, m = 7;

void inicializar(){
   tablero=( struct ficha**) malloc(sizeof( struct ficha*)*n);

   for(i=0;i<m;i++){
      tablero[i]=( struct ficha*) malloc(sizeof( struct ficha)*m);
   }

   for(i=0;i<n;i++){
      for(j=0;j<m;j++){
         tablero[i][j].tipo = '_';
      }
   }

   for(i=0;i<n;i++){
         printf("\n");
      for(j=0;j<m;j++){
         printf("%i ",tablero[i][j]);
      }
      printf("\n");
   }

	return;
}

int evaluarPunto(int x, int y, char tipo) {
   if (x < 0 && x > 7 && y < 0 && y > 6 ) return 0;
   else {
      if( tablero[x][y].tipo == tipo) return 1;
      else return 0;
   }
}

int verificarVictoria(int x1, int x2, int y1, int y2, int xConstante, int yConstante, int acumuladorVertical, int acumuladorHorizontal, int acumuladorDiagonalDerecha, int acumuladorDiagonalIzquierda, char tipo) {
   
   int acumuladorVerticalAux = acumuladorVertical;
   int acumuladorHorizontalAux = acumuladorHorizontal;
   int acumuladorDiagonalDerechaAux = acumuladorDiagonalDerecha;
   int acumuladorDiagonalIzquierdaAux = acumuladorDiagonalIzquierda;

   int x1Prox = x1 - 1;
   int x2Prox = x2 + 1;
   int y1Prox = y1 - 1;
   int y2Prox = y2 + 1;

   printf(" x1 : %i , x2 : %i , y1 : %i , y2 : %i  , xConstant : %i , yConstant : %i  , acumuladorVertical : %i , acumuladorHorizontal : %i , acumuladorDiagonalDerecha : %i , acumuladorDiagonalIzquierda : %i , tipo : %c \n" ,x1, x2, y1, y2, xConstante, yConstante, acumuladorVertical, acumuladorHorizontal, acumuladorDiagonalDerecha, acumuladorDiagonalIzquierda, tipo);
   printf("1 haaa\n");

   if(   acumuladorDiagonalDerecha == 3 ||
         acumuladorDiagonalIzquierda == 3 ||
         acumuladorHorizontal == 3 ||
         acumuladorVertical == 3
   ) return 1;

   if(x1 < 0 && x2 < 6 && y1 < 0 && y2 < 5 ) return 0;
   
   printf("2 haaa\n");
   //Evaluando condicional horizonral
   if(evaluarPunto(x1, yConstante, tipo)) acumuladorHorizontalAux++;
   if(evaluarPunto(x2, yConstante, tipo)) acumuladorHorizontalAux++;

   //Evaluando condicional diagonal derecha
   if(evaluarPunto(x1, y1, tipo)) acumuladorDiagonalDerechaAux++;
   if(evaluarPunto(x2, y2, tipo)) acumuladorDiagonalDerechaAux++;

   //Evaluando condicional diagonal izquierda
   if(evaluarPunto(x1, y2, tipo)) acumuladorDiagonalIzquierdaAux++;
   if(evaluarPunto(x2, y1, tipo)) acumuladorDiagonalIzquierdaAux++;

   return verificarVictoria(x1Prox, x1Prox, y1Prox, y2Prox, xConstante, yConstante, acumuladorVerticalAux, acumuladorHorizontalAux, acumuladorDiagonalDerechaAux, acumuladorDiagonalIzquierda, tipo);
}