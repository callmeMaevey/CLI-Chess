
#include <stdlib.h>
#include <stdio.h>

typedef enum { Red, Black } Color;
typedef enum { Pawn, Bishop, Knight, Rook, Queen, King } PieceType ;

char char_of_PieceType ( PieceType* piece){
  switch (*piece) {
    case Pawn:    return 'P';
    case Bishop:  return 'B';
    case Knight:  return 'K';
    case Rook:    return 'R';
    case Queen:   return 'Q';
    case King:    return 'K';
  }

}


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
        PieceType curr = state -> tiles[i][j] -> piece -> type;
        //printf(" [%c] ", char_of_PieceType(&curr) );
      }
      
    }
  }
}








