
#include <stdlib.h>
#include <stdio.h> //for printing the board
#include "piece.h" //Has the Color Enum in it too
// for the chess board and piece logic

typedef struct {
  Color color;
  Piece* piece;
} Tile;

typedef struct { Tile* tiles[8][8]; } Board;

Piece* startingPiece( int i, int j ){
  Piece* newPiece = (Piece*)malloc(sizeof(Piece));
  switch (j){
    //Rooks
    case 0:
    case 7: newPiece -> type = Rook; break;
    //Knights
    case 1:
    case 6: newPiece -> type = Knight; break;
    //Bishops
    case 2:
    case 5: newPiece -> type = Bishop; break;
    //King+Queen
    case 3: newPiece -> type = Queen; break;
    case 4: newPiece -> type = King; break;
  }
  switch (i){
    case 0: newPiece -> color = Red; break;
    case 7: newPiece -> color = Black; break;
    //Red Pawns
    case 1:
      newPiece -> color = Red;
      newPiece -> type = Pawn;
      break;
    //Black Pawns
    case 6:
      newPiece -> color = Black;
      newPiece -> type = Pawn;
      break;
    //Empty Tile
    default: free(newPiece); return NULL;
  }
  return newPiece;
}


Board* newBoard() {
  Board* board = (Board*)malloc(sizeof(Board));
  for(int i = 0; i < 8; i++){
   for(int j = 0; j < 8; j++){
    //new tile with new piece
    Tile* newTile = (Tile*)malloc(sizeof(Tile));
    newTile -> piece = startingPiece( i,j );

    board -> tiles[i][j] = newTile;

    //determine tile colors
    if( (i+j) % 2 ) board -> tiles[i][j] -> color = Black;
    else board -> tiles[i][j] -> color = Red;
    
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

