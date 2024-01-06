
#include <stdlib.h>
#include <stdio.h>

typedef enum { Red, Black } Color;
typedef enum { Pawn, Bishop, Knight, Rook, Queen, King } PieceType ;

typedef struct {
 //needs a function pointer for its available moves
  PieceType type;
  Color color;
} Piece ;

typedef struct {
  Color color;
  Piece* piece;
  
} Tile;

typedef struct {
  Tile* tiles[8][8];
} Board;


Board* newBoard() {
  Board* board = (Board*)malloc(sizeof(Board));
  for(int i = 0; i < 8; i++){
   for(int j = 0; j < 8; j++){
    board -> tiles[i][j] = (Tile*)malloc(sizeof(Tile));

    if( (i+j) % 2 ){
      board -> tiles[i][j] -> color = Black;
    }
    else {
      board -> tiles[i][j] -> color = Red;
    }
   }
  }
  return board;
}



void drawBoard( Board* state){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      
      if( j == 0 ) printf("\n");

      if( state -> tiles[i][j] -> color == Black ) {
        printf(" [b] ");
      }

      else {
        printf(" [r] ");
      }
      
    }
  }
}








