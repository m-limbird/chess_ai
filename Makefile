CXX=g++
CXXFLAGS= -std=c++11 -Wall -g -I .

chessboard: src/chessboard.o src/robotic_chess_ai.o
	$(CXX) $(CXXFLAGS) -o build/chessboard src/chessboard.o src/robotic_chess_ai.o

