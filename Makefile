CC=g++ -O2

all: run

run: case.o main.o
	$(CC) case.o main.o -o run

main.o: case.o
	$(CC) -c main.cpp

case.o: 
	$(CC) -c case.cpp
