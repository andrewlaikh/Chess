Executable = chess
CXX = g++
CXXFLAGS = -Wall -g
OBJ = ChessMain.o ChessBoard.o bishop.o king.o knight.o pawn.o piece.o queen.o rook.o

$(Executable): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

#check if should include clean inside this set of files
.PHONY: clean

clean :
	rm -f $(OBJ) $(EXE)
