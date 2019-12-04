#include "rook.h"

using namespace std;

//use an override function to override previous virtual function.
bool Rook::makeMove(Piece* Board[8][8], string source_square, string destination_square)
{
  int sourceSquare = parseMove(source_square);
  int destinationSquare = parseMove(destination_square);
  //review. This should be found in the piece as functionality.
  //within range.
  if (moveWithinRange(sourceSquare, destinationSquare) == false)
  {
    return false;
  }
  //no blocking pieces.
  if(noObstructingPieces(Board, sourceSquare, destinationSquare) == false)
  {
    return false;
  }
  return false;
}

//question is HOW do you check if there is no one blocking? Seems that you need
//to access piece to make decision.

bool Rook::moveWithinRange(int sourceSquare, int destinationSquare)
{
  if ((columnDiff(sourceSquare, destinationSquare) == 0 &&
  rowDiff(sourceSquare, destinationSquare) > 0)
  ||(columnDiff(sourceSquare, destinationSquare) > 0 &&
  rowDiff(sourceSquare, destinationSquare) == 0))
  {
    return true;
  }
  else
    return false;
}

bool Rook::noObstructingPieces(Piece* Board[8][8], int sourceSquare, int destinationSquare)
{
  if (rowDiff(sourceSquare, destinationSquare) > 0)
  {
    if (noObstructingRows(Board, sourceSquare, destinationSquare) == false)
    {
      return false;
    }
  }
  if (columnDiff(sourceSquare, destinationSquare) > 0)
  {
    if(noObstructingColumns(Board,sourceSquare,destinationSquare) == false)
    {
      return false;
    }
  }
  return true;
}
