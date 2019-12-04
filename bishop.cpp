#include "bishop.h"

using namespace std;

bool Bishop::makeMove (Piece* Board[8][8], string source_square,
  string destination_square)
{
  int sourceSquare = parseMove(source_square);
  cout << "top source square: " << sourceSquare << endl;
  int destinationSquare = parseMove(destination_square);
  if(moveWithinRange(sourceSquare, destinationSquare)==false)
  {
    return false;
  }
  if (noObstructingPieces(Board, sourceSquare, destinationSquare)==false)
  {
    cout << "obstruction issue " << endl;
    return false;
  }
  return true;
}

//i don't think that the rowDiff is correct?
bool Bishop::moveWithinRange(int sourceSquare, int destinationSquare)
{
  if(rowDiff(sourceSquare, destinationSquare) ==
  columnDiff(sourceSquare, destinationSquare))
  {
    return true;
  }
  return false;
}

bool Bishop::noObstructingPieces(Piece* Board[8][8], int sourceSquare,
int destinationSquare)
{
  if (noObstructingDiagonals(Board, sourceSquare, destinationSquare) == false)
  {
    return false;
  }
  return true;
}
