
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
    case King:    return 'W';
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

Piece* startingPiece( int i, int j ){
  Piece* newPiece = (Piece*)malloc(sizeof(Piece));

  switch (j){

    case 0:
    case 7:
      newPiece -> type = Rook;
      break;

    case 1:
    case 6:
      newPiece -> type = Knight;
      break;

    case 2:
    case 5:
      newPiece -> type = Bishop;
      break;

    case 3:
      newPiece -> type = Queen;
      break;

    case 4:
      newPiece -> type = King;
      break;
  }

  switch (i){
    case 0: 
      newPiece -> color = Red;
      break;
    case 1:
      newPiece -> color = Red;
      newPiece -> type = Pawn;
      break;
    case 6:
      newPiece -> color = Black;
      newPiece -> type = Pawn;
      break;
    case 7:
      newPiece -> color = Black;
      break;
    default:
      free(newPiece);
      return NULL;

  }

  return newPiece;
}


Board* newBoard() {
  Board* board = (Board*)malloc(sizeof(Board));
  for(int i = 0; i < 8; i++){
   for(int j = 0; j < 8; j++){

    Tile* newTile = (Tile*)malloc(sizeof(Tile));
    newTile -> piece = startingPiece( i,j );

    board -> tiles[i][j] = newTile;

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
      if( state -> tiles[i][j] -> piece == NULL){
        if( state -> tiles[i][j] -> color == Black ) printf(" [=] ");
        if( state -> tiles[i][j] -> color == Red   ) printf(" [-] ");
      }

      else {
        PieceType curr = state -> tiles[i][j] -> piece -> type;
        printf(" [%c] ", char_of_PieceType(&curr) );
      }
      
    }
  }
}








