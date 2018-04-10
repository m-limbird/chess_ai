CC=g++
CFLAGS=-I.

hellomake: src/hello_world.cpp
	$(CC) -o build/hellomake src/hello_world.cpp -I .