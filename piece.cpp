#include "piece.h"

using namespace std;

int Piece::parseMove(string input)
{
   //review if C cast v CPP cast should be used.
   int column = (-1)*(((int)(input[1]) - 48)-8) ;
   int row = (int)(input[0]) - 65;
   return ((column*10) + row);
}

int Piece::columnDiff(int sourceSquare, int destinationSquare)
{
  int difference = (sourceSquare/10) - (destinationSquare/10);
  return abs(difference);
}

int Piece::rowDiff(int sourceSquare, int destinationSquare)
{
  int difference = (sourceSquare%10) - (destinationSquare%10);
  return abs(difference);
}

//CHECK AGAIN. REMEMBER THAT IT NEEDS TO ACCOM BOTH +VE AND 0VE
bool Piece::noObstructingRows(Piece* Board[8][8], int sourceSquare,
  int destinationSquare)
{
    int sourceColumn = sourceSquare/10;
    int sourceRow = sourceRow%10;
    int destinationRow = destinationSquare%10;
    int destinationColumn = destinationSquare/10;
    for (int sourceRowIterator = sourceRow+1;
      sourceRowIterator < destinationColumn; sourceRowIterator++)
    {
      if(Board[sourceColumn][sourceRowIterator]!=NULL)
      {
        cerr << "Position: " << sourceColumn
        << sourceRowIterator << " is filled." << endl;
        return false;
      }
    }
}

//CHECK AGAIN. REMEMBER THAT IT NEEDS TO ACCOM BOTH +VE AND 0VE
bool Piece::noObstructingColumns(Piece* Board[8][8], int sourceSquare,
  int destinationSquare)
{
  cout << "Piece function called. " << endl;
  int sourceColumn = sourceSquare/10;
  int sourceRow = sourceSquare%10;
  int destinationRow = destinationSquare%10;
  int destinationColumn = destinationSquare/10;
  if (sourceColumn < destinationColumn)
  {
    for (int sourceColumnIterator = sourceColumn+1;
      sourceColumnIterator < destinationColumn; sourceColumnIterator++)
      {
        if(Board[sourceColumnIterator][sourceRow]!=NULL)
        {
          cerr << "Position: " << sourceColumnIterator
          << sourceRow << " is filled." << endl;
          return false;
        }
      }
  }
  else if (destinationColumn < sourceColumn)
  {
    for (int sourceColumnIterator = sourceColumn-1;
      destinationColumn < sourceColumnIterator; sourceColumnIterator--)
      {
        if(Board[sourceColumnIterator][sourceRow]!=NULL)
        {
          cerr << "Position: " << sourceColumnIterator
          << sourceRow << " is filled." << endl;
          return false;
        }
      }
  }
  return true;
}

//complete this next.
bool Piece::noObstructingDiagonals(Piece* Board[8][8], int sourceSquare,
  int destinationSquare)
{
  int sourceColumn = sourceSquare/10;
  int sourceRow = sourceSquare%10;
  int destinationRow = destinationSquare%10;
  int destinationColumn = destinationSquare/10;
  //need to set the x and y-axis to ensure that review works properly.
  if (sourceColumn < destinationColumn && sourceRow < destinationRow)
  {
    //bottom right implementation
    cout << "field 1 " << endl;
    for (int ColumnIterator = sourceColumn + 1, rowIterator = sourceRow+ 1;
      ColumnIterator < destinationColumn; ColumnIterator++, rowIterator++)
    {
      if (Board[ColumnIterator][rowIterator] != NULL)
      {
        return false;
      }
    }
    return true;
  }
  if (sourceColumn < destinationColumn &&  destinationRow < sourceRow)
  {
    cout << "field 2 " << endl;
    for (int ColumnIterator = sourceColumn + 1, rowIterator = sourceRow - 1;
      ColumnIterator < destinationColumn; ColumnIterator++, rowIterator--)
    {
      if (Board[ColumnIterator][rowIterator] != NULL)
      {
        cout << "clash at " << ColumnIterator << " " << rowIterator << endl;
        return false;
      }
    }
    return true;
  }
  if (destinationColumn < sourceColumn && sourceRow < destinationRow)
  {
    cout << "field 3" << endl;
    for (int ColumnIterator = sourceColumn - 1, rowIterator = sourceRow + 1;
      destinationColumn < ColumnIterator; ColumnIterator--, rowIterator++)
    {
      if (Board[ColumnIterator][rowIterator] != NULL)
      {
        return false;
      }
    }
    return true;
  }
  if (destinationColumn < sourceColumn && destinationRow < sourceRow)
  {
    cout << "BS correct field " << endl;
    for (int ColumnIterator = sourceColumn - 1, rowIterator = sourceRow - 1;
      destinationColumn < ColumnIterator; ColumnIterator--, rowIterator++)
    {
      if (Board[ColumnIterator][rowIterator] != NULL)
      {
        return false;
      }
    }
    return true;
  }
}
