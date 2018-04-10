CXX=g++
CXXFLAGS= -std=c++11 -I .

chessboard: src/chessboard.o src/robotic_chess_ai.o
	$(CXX) -o build/chessboard src/chessboard.o src/robotic_chess_ai.o -std=c++11 -I .