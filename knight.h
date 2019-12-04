#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "constants.h"

class Knight:public Piece
{
public:
  //ALSO need to check for INCLUDING the base class initializer as well.
  Knight(int pieceName, string identifier):Piece(pieceName, identifier)
  {
    if (pieceName == WHITE_KNIGHT)
    {
      uniCode = "♘";
    }
    if (pieceName == BLACK_KNIGHT)
    {
      uniCode = "♞";
    }
  }
  bool makeMove (Piece* Board[8][8], string source_square,
    string destination_square) override;
private:
  bool moveWithinRange(int sourceSquare, int destinationSquare);

protected:

};

#endif
