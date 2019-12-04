#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <cstring>
#include "constants.h"
#include "king.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "knight.h"
#include "pawn.h"
#include "piece.h"

using namespace std;

class ChessBoard
{
public:
  ChessBoard()
  {
    cout << "A new chess game is started!" << endl;
    resetBoard();
  }
  void resetBoard();
  void submitMove(string source_square, string destination_square);
  //declare a piece and then let the others INHERIT from the piece
  Piece* chessBoard[8][8];
private:
  void setEmptyBoard();
  void placePieces();
  bool validateInput(string input);
  bool pieceBelongsToEnemy(int sourceSquare);
  bool sourceSquareEmpty(int sourceSquare);
  bool destinationSquareEmpty(int destinationSquare);
  bool pieceAllowedMoveToSquare();
  int parseMove(string input);
  void movePiece(int sourceSquare, int destinationSquare);
  void updateTurn();
  void resetTurn();
  void printBoard();
  string printPieceName(int pieceNumber);
  string printOpponentTurn();
  // string parseSquare(int Square);
  int TURN = 15;
protected:
};

#endif
