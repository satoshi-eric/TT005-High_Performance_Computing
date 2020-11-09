main: main.o
	gcc main.o -o ../bin/main -fopenmp

main.o: main.c
	gcc -c main.c -fopenmp

clean:
	rm *.o