main: main.o
	gcc main.o -o main -fopenmp

main.o: main.c
	gcc -c main.c -fopenmp

clean:
	rm *.o main