#include "board.h"

//////////////////// untested /////////////////// maybe should be in its own header? will need ifndef

int** addMoveToArray ( int** movesArray, int* move) {
  // dymaically reallocate movesArray
  if ( movesArray == null ) {
    movesArray = (int**)malloc(sizeof(int*)*2);
    movesArray[0] = move;
    movesArray[1] = '\0';
  }

  int index = 0;
  while ( movesArray[index] != '\0' ) { index++; }
  //deep copy logic
  int** newMovesArray = (int**) malloc( sizeof(int*) * index );
  index = 0;
  while ( movesArray[index] != '\0' ) { //derefrence might need to go to the underlying pointer
    *newMovesArray[index] = *movesArray[index]; // copy pointers location
    free( *( movesArray[index] ) ); //free pointer underneath
    free( movesArray[index] ); // free pointer in array
    index++ ;
  }

  free(movesArray); // free array

  return newMovesArray; //return newly allocated Array

}

int** getValidMoves ( Board* state, int i, int j ) {
  PieceType pieceType = state -> tiles[i][j] -> type;
  Color pieceColor = state -> tiles[i][j] -> type;
  int** moves;
  int** currentMoveIndex = &moves;

// I think it would be better to just use a function that takes
// a null terminated moves-Array and a move-to-add and returns 
// a new nullterminated moves-Array with taht move.
// it should also free the old one and all its child moves 
// after a deep-copy of course.
  switch (pieceType) {

    case Pawn:
      //if color = red and pos=[X][1] : can move once or twice
      //same if color = black and pos=[0][6] but the other way
      //if enemy piece exists on diags, can move there
      //if piece in front, canot move straight up
      // -> also en'pessant?
      if(pieceColor == Red){
        int* move = (int*)malloc(sizeof(int)*2);
        *currentMoveIndex = (int*)malloc(sizeof(int));
        *currentMoveIndex = &move; //pointer logic going too hard here

        currentMoveIndex++;

      } else {
        
      }
      break;
  }
}
