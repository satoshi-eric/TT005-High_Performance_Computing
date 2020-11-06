main: main.o
	gcc main.o multMatrix.o -o main -fopenmp

main.o: main.c
	gcc -c main.c -fopenmp

multMatrix.o: multMatrix.c multMatrix.h
	gcc -c multMatrix.c -fopenmp

clean:
	rm main main.o