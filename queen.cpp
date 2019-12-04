#include "queen.h"

using namespace std;

bool Queen::makeMove(Piece* Board[8][8], string source_square,
string destination_square)
{
  int sourceSquare = parseMove(source_square);
  int destinationSquare = parseMove(destination_square);
  if (Rook::moveWithinRange(sourceSquare, destinationSquare)== true
  ||bishopMoveWithinRange(sourceSquare, destinationSquare)==true)
      {}
  else
  {
    return false;
  }
  if (noObstructingPieces(Board, sourceSquare, destinationSquare) == false)
    {
      return false;
    }
  return true;
}

bool Queen::noObstructingPieces(Piece* Board[8][8],int sourceSquare,
  int destinationSquare)
  {
    //check if move is diagonal
    if (columnDiff(sourceSquare, destinationSquare) > 0 &&
    rowDiff(sourceSquare, destinationSquare) > 0)
    {
      if(bishopNoObstructingPieces(Board, sourceSquare, destinationSquare)
      == false)
      {
        return false;
      }
    }
    //if move is along rank and file
    else
    {
        if (Rook::noObstructingPieces(Board, sourceSquare, destinationSquare)
        == false)
        {
          return false;
        }
    }
    return true;
  }

bool Queen::bishopMoveWithinRange(int sourceSquare, int destinationSquare)
{
  if(rowDiff(sourceSquare, destinationSquare) ==
    columnDiff(sourceSquare, destinationSquare))
    {
      return true;
    }
    return false;
}

bool Queen::bishopNoObstructingPieces(Piece* Board[8][8], int sourceSquare,
int destinationSquare)
{
  if (noObstructingDiagonals(Board, sourceSquare, destinationSquare) == false)
  {
    return false;
  }
  return true;
}
