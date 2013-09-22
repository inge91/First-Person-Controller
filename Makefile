CC = g++
LD_FLAGS = -lglut -lGLU -lGL 

all:
	$(CC) main.cpp $(LD_FLAGS) -o main
