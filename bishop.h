#ifndef BISHOP_Hvirtual
#define BISHOP_H

#include "piece.h"
#include "constants.h"

using namespace std;

//virtual base class for double inheritance in queen
class Bishop: public Piece
{
public:
  Bishop(int pieceName, string identifier): Piece(pieceName, identifier)
  {
    if (pieceName == WHITE_BISHOP)
    {
      uniCode = "♗";
    }
    if (pieceName == BLACK_BISHOP)
    {
      uniCode = "♝";
    }
  };
  virtual bool makeMove (Piece* Board[8][8], string source_square,
    string destination_square) override;
protected:
  bool moveWithinRange(int sourceSquare, int destinationSquare);
  bool noObstructingPieces(Piece* Board[8][8], int sourceSquare,
    int destinationSquare);

private:

};

#endif
