#include "knight.h"

using namespace std;

bool Knight::makeMove(Piece* Board[8][8], string source_square,
string destination_square)
{
  int sourceSquare = parseMove(source_square);
  int destinationSquare = parseMove(destination_square);
  if(moveWithinRange(sourceSquare, destinationSquare)==false)
  {
    return false;
  }
  //no need to check for jumping over bc knight can jump over.
  return true;
}

//basically clear that the path is alright for within.
bool Knight::moveWithinRange(int sourceSquare, int destinationSquare)
{
  //somehow columnDiff NOT returning the right answer
  if ((columnDiff(sourceSquare, destinationSquare) == 2 &&
    rowDiff(sourceSquare, destinationSquare) == 1) ||
    (columnDiff(sourceSquare, destinationSquare) == 1
    && rowDiff(sourceSquare,destinationSquare) == 2))
    {
      return true;
    }
  return false;
}
