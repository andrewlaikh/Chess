#ifndef KING_H
#define KING_H

#include "piece.h"
#include "constants.h"

//declare king class and place the items INSIDE the king class.
class King:public Piece
{
public:
  King(int pieceName, string identifier):Piece(pieceName, identifier)
  {
    if (pieceName == WHITE_KING)
    {
      uniCode = "♔";
    }
    if (pieceName == BLACK_KING)
    {
      uniCode = "♚";
    }
  };
  bool makeMove (Piece* Board[8][8], string source_square,
    string destination_square) override;
private:
  bool moveWithinRange(string source_square, string destination_square); 
protected:
};

#endif
