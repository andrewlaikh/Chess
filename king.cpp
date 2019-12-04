#include "king.h"

using namespace std;

bool King::makeMove (Piece* Board[8][8], string source_square, string destination_square)
{
  if(moveWithinRange(source_square, destination_square)==false)
  {
    return false;
  }
  //no need to check for obstructing pieces bc king can only move one spot.
}

bool King::moveWithinRange(string source_square, string destination_square)
{
  int sourceSquare = parseMove(source_square);
  int destinationSquare = parseMove(destination_square);
  if (columnDiff(sourceSquare, destinationSquare) <= 1 &&
    rowDiff(sourceSquare,destinationSquare)<=1)
  {
    return true;
  }
  else
  {
    return false;
  }
  return true;
}
