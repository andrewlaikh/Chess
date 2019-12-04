#include "pawn.h"

using namespace std;

//need to check for DIAGONAL as well WHEN piece is available

bool Pawn::makeMove(Piece* Board[8][8], string source_square,
string destination_square)
{
    int sourceSquare = parseMove(source_square);
    int destinationSquare = parseMove(destination_square);
    if(firstMove == true)
    {
      if (firstMoveWithinRange(sourceSquare, destinationSquare)==false)
      {
        return false;
      }
      firstMove = false;
    }
    else if(firstMove == false)
    {
      if (moveWithinRange(sourceSquare, destinationSquare) == false)
      {
        return false;
      }
    }
    //recent addition.
    if (noObstructingPieces(Board, sourceSquare, destinationSquare)== false)
    {
      return false;
    }
    return true;
}

bool Pawn::firstMoveWithinRange(int sourceSquare, int destinationSquare)
{
  if ((columnDiff(sourceSquare, destinationSquare) == 0 &&
  (rowDiff(sourceSquare, destinationSquare) > 0 &&
  rowDiff(sourceSquare, destinationSquare) <= 2))
  ||((columnDiff(sourceSquare, destinationSquare) > 0 &&
  columnDiff(sourceSquare, destinationSquare) <= 2) &&
  rowDiff(sourceSquare, destinationSquare) == 0))
  {
    return true;
  }
  else
    return false;
}

bool Pawn::moveWithinRange(int sourceSquare, int destinationSquare)
{
  if ((columnDiff(sourceSquare, destinationSquare) == 0 &&
  rowDiff(sourceSquare, destinationSquare) == 1)
  ||(columnDiff(sourceSquare, destinationSquare) <= 0 &&
  rowDiff(sourceSquare, destinationSquare) == 0))
  {
    return true;
  }
  else
    return false;
}

bool Pawn::noObstructingPieces(Piece* Board[8][8], int sourceSquare,
  int destinationSquare)
{
  //write the temporary code here first, review if it can work or not.
  int sourceColumn = sourceSquare/10;
  int sourceRow = sourceRow%10;
  int destinationRow = destinationSquare%10;
  int destinationColumn = destinationSquare/10;
  if (columnDiff(sourceSquare, destinationSquare) > 1)
  {
    if (noObstructingColumns(Board, sourceSquare, destinationSquare) == false)
    {
      return false;
    }
  }
  else if (rowDiff(sourceSquare, destinationSquare)>1)
  {
    if(noObstructingRows(Board, sourceSquare, destinationSquare) == false)
    {
      return false;
    }
  }
  return true;
}
