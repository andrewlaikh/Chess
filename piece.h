#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Piece {
public:
  Piece(){};
  Piece(int pieceName, string identifier): pieceName(pieceName),
  identifier(identifier){};
  int pieceName;
  virtual bool makeMove(Piece* Board[8][8], string source_square,
    string destination_square) = 0;
  //REMOVE unicode entry before submission.
  string uniCode;
private:
protected:
  string identifier;
  int positionNumber;
  int parseMove(string position);
  int columnDiff(int sourceSquare, int destinationSquare);
  int rowDiff(int sourceSquare, int destinationSquare);
  bool noObstructingRows(Piece* Board[8][8], int sourceSquare,
    int destinationSquare);
  bool noObstructingColumns(Piece* Board[8][8], int sourceSquare,
    int destinationSquare);
  bool noObstructingDiagonals(Piece* Board[8][8], int sourceSquare,
    int destinationSquare);
};

#endif
