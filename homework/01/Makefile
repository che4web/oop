
# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++ -O2
# #Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
all:run
#
run: test.o matrix.o 
	$(CC)  test.o matrix.o -o run 
test.o: test.cpp
	$(CC) -c test.cpp

matrix.o: matrix.cpp
	$(CC) -c matrix.cpp
clean:
	rm *.o


