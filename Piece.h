//piece structs // enumst 
typedef enum { Pawn, Bishop, Knight, Rook, Queen, King } PieceType ;
typedef enum { Red, Black } Color;

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


