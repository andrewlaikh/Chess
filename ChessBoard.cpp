#include "ChessBoard.h"

using namespace std;

void ChessBoard::resetBoard()
{
  setEmptyBoard();
  placePieces();
  resetTurn();
  printBoard();
}

void ChessBoard::setEmptyBoard()
{
  int columnSize = 8;
  int rowSize = 8;
  for (int columnIterator = 0; columnIterator < columnSize; columnIterator++)
  {
    for (int rowIterator = 0; rowIterator < rowSize; rowIterator++)
    {
       chessBoard[columnIterator][rowIterator] = NULL;
    }
  }
}

void ChessBoard::placePieces()
{
  chessBoard[0][3] = new King(BLACK_KING, "E8");
  chessBoard[7][3] = new King(WHITE_KING, "E1");
  //place pawns
  int A(65);
  for (int rowIterator = 0; rowIterator < 8; rowIterator++,
  A++)
  {
    string row = string(1, A);
    string blackPawnInput = row + "7";
    chessBoard[1][rowIterator] = new Pawn(BLACK_PAWN, blackPawnInput, true);
    string whitePawnInput = row + "2";
    chessBoard[6][rowIterator] = new Pawn(WHITE_PAWN, whitePawnInput, true);
  }
  //place bishop
  chessBoard[0][2] = new Bishop(BLACK_BISHOP, "C8");
  chessBoard[0][5] = new Bishop(BLACK_BISHOP, "G8");
  chessBoard[7][2] = new Bishop(WHITE_BISHOP, "C1");
  chessBoard[7][5] = new Bishop(WHITE_BISHOP, "C8");
  //place rook
  chessBoard[0][0] = new Rook(BLACK_ROOK, "A8");
  chessBoard[0][7] = new Rook(BLACK_ROOK, "H8");
  chessBoard[7][0] = new Rook(WHITE_ROOK, "A1");
  chessBoard[7][7] = new Rook(WHITE_ROOK, "H1");
  //place knight
  chessBoard[0][1] = new Knight(BLACK_KNIGHT, "B8");
  chessBoard[0][6] = new Knight(BLACK_KNIGHT, "G8");
  chessBoard[7][1] = new Knight(WHITE_KNIGHT, "B1");
  chessBoard[7][6] = new Knight(WHITE_KNIGHT, "G1");
  //place Queen (is there a more sophisticated solution since movement from
  chessBoard[0][4] = new Queen(BLACK_QUEEN, "E8");
  chessBoard[7][4] = new Queen(WHITE_QUEEN, "E1");
}

void ChessBoard::submitMove(string source_square, string destination_square)
{
  bool checkMate = false;
  bool staleMate = false;
  if (validateInput(destination_square) == false)
  {
    return;
  }
  if (validateInput(source_square) == false)
  {
    return;
  }
  int sourceSquare = parseMove(source_square);
  int destinationSquare = parseMove(destination_square);
  if (sourceSquareEmpty(sourceSquare)== true)
  {
    cerr << "There is no piece at position " << source_square << "!" << endl;
    return;
  }
  //review whether piece belongs to enemy
  if (pieceBelongsToEnemy(sourceSquare)==true)
  {
    cerr << "It is not " << printOpponentTurn() << "turn to move!" << endl;
    return;
  }
  //review whether destination square is filled with existing entry
  if (destinationSquareEmpty(destinationSquare)==false &&
  pieceBelongsToEnemy(destinationSquare)==false)
  {
    cerr << "Destination square " << destination_square << " already "
    << "has a piece. Choose again. " << endl;
    return;
  }
  int takenPieceNumber;
  int destinationColumn = destinationSquare/10;
  int destinationRow = destinationSquare%10;
  bool takePiece = false;
  if(destinationSquareEmpty(destinationSquare)==false &&
  pieceBelongsToEnemy(destinationSquare)==true)
  {
    takenPieceNumber = chessBoard[destinationColumn][destinationRow]->pieceName;
    //somehow deleting the piece causes a seg fault?? (not any longer)
    delete chessBoard[destinationColumn][destinationRow];
    takePiece = true;
  }

  //review whether destination square is filled with enemy (piece to be eaten)
  int sourceColumn = sourceSquare/10;
  int sourceRow = sourceSquare%10;
  if (chessBoard[sourceColumn][sourceRow]->makeMove(chessBoard, source_square,
    destination_square) == false)
  {
    int sourcePiece = chessBoard[sourceColumn][sourceRow]-> pieceName;
    cerr << printPieceName(sourcePiece) << "cannot move to "
    << destination_square << "!" << endl;
    return;
  }
  int movingPieceNumber = chessBoard[sourceColumn][sourceRow]-> pieceName;
  movePiece(sourceSquare, destinationSquare);
  cout << printPieceName(movingPieceNumber) << "moves from " << source_square
  << " to " << destination_square << endl;
  //need to reflect if consequence of move is that it's a checkmate or draw.
    //for check, you need to verify ALL Possible moves to ensure that king
    //is not in check.
    //otherwise, you need to make sure that the pieces are intact.
  // if (checkMate()==true)
  // {
  //   cout << Colour << "is in check. " << endl;
  // }
  if (takePiece==true)
  {
    cout << printPieceName(movingPieceNumber)<< "moves from " << source_square
    << " to " << destination_square << " taking "
    << printPieceName(takenPieceNumber) << endl;
  }
}

bool ChessBoard::validateInput(string input)
{
  while (input.size()!=2)
  {
    cerr << "Input " << input << " needs to have 2 characters." << endl
    << "Submit move again. " << endl;
    return false;
    //intuitively, best alternative is to stop and ask user to resubmit moves
  }
  char row = input[0];
  int A(65), H(72);
  while ((int) row > H || (int) row < A)
  {
    cerr << "Row input " << row << " is not valid. " << endl
    << "Row input needs to be between A-H. " << endl;
    return false;
  }
  char column = input[1];
  int ONE = 49;
  int EIGHT = 56;
  while ((int) column > EIGHT || (int) column < ONE)
  {
    cerr << "Column input " << column << " is not valid. " << endl
    << "Column input needs to be between 1-8. " << endl;
    return false;
  }
  return true;
}

int ChessBoard::parseMove(string input)
{
   //review if C cast v CPP cast should be used.
   int column = (-1)*(((int)(input[1]) - 48)-8) ;
   int row = (int)(input[0]) - 65;
   return ((column*10) + row);
}

bool ChessBoard::sourceSquareEmpty(int sourceSquare)
{
  int column = sourceSquare/10;
  int row = sourceSquare%10;
  if(chessBoard[column][row]==NULL)
    return true;
  else
    return false;
}

bool ChessBoard::pieceBelongsToEnemy(int sourceSquare)
{
  int column = sourceSquare/10;
  int row = sourceSquare%10;
  //if it's  white's turn
  if(TURN > 0 && chessBoard[column][row]->pieceName > WHITE_PAWN)
  {
    return true;
  }
  //if it  black's turn
  if (TURN < 0 && chessBoard[column][row]->pieceName < BLACK_KING)
  {
    return true;
  }
  return false;
}

bool ChessBoard::destinationSquareEmpty(int destinationSquare)
{
  int column = destinationSquare/10;
  int row = destinationSquare%10;
  if(chessBoard[column][row] != NULL)
    return false;
  else
    return true;
}

void ChessBoard::movePiece(int sourceSquare, int destinationSquare)
{
  int sourceColumn = sourceSquare/10;
  int sourceRow = sourceSquare%10;
  int destinationColumn = destinationSquare/10;
  int destinationRow = destinationSquare%10;
  chessBoard[destinationColumn][destinationRow] =
  chessBoard[sourceColumn][sourceRow];
  chessBoard[sourceColumn][sourceRow] = NULL;
  updateTurn();
  printBoard();
}

void ChessBoard::updateTurn()
{
  TURN = TURN * (-1);
}

void ChessBoard::printBoard()
{
  cout << "Output: " << endl;
  cout << "   A  B  C  D  E  F  G  H  " << endl;
  for (int columnIterator = 0, column = 8; column > 0; column--,columnIterator++)
  {
    cout << column << "  ";
    for (int row = 0; row < 8; row++)
    {
      if (chessBoard[columnIterator][row] == NULL)
      {
        cout << "   ";
        continue;
      }
      cout << chessBoard[columnIterator][row]-> uniCode << "  ";
    }
    cout << endl;
  }
}

//question is HOW do you define number to return a specific string?
string ChessBoard::printPieceName(int pieceNumber)
{
  if (pieceNumber == WHITE_KING)
    return "White's King ";
  else if(pieceNumber == WHITE_ROOK)
    return "White's Rook ";
  else if(pieceNumber == WHITE_BISHOP)
    return "White's Bishop ";
  else if(pieceNumber == WHITE_QUEEN)
    return "White's Queen ";
  else if(pieceNumber == WHITE_KNIGHT)
    return "White's Knight ";
  else if(pieceNumber == WHITE_PAWN)
    return "White's Pawn ";
  else if(pieceNumber == BLACK_KING)
    return "Black's King ";
  else if(pieceNumber == BLACK_ROOK)
    return "Black's Rook ";
  else if(pieceNumber == BLACK_BISHOP)
    return "Black's Bishop ";
  else if(pieceNumber == BLACK_QUEEN)
    return "Black's Queen ";
  else if(pieceNumber == BLACK_KNIGHT)
    return "Black's Knight ";
  else if(pieceNumber == BLACK_PAWN)
    return "Black's Pawn ";
  else
    return "Unknown piece number ";
}

string ChessBoard::printOpponentTurn()
{
  //if white's turn
  if (TURN > 0 )
  {
    return "Black's ";
  }
  //if black's turn
  if (TURN < 0)
  {
    return "White's ";
  }
}

void ChessBoard::resetTurn()
{
  //Set White's turn
  TURN = 15;
}
