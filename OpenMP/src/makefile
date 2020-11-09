main: main.o
	gcc main.o -o ../bin/programa -fopenmp

main.o: main.c
	gcc -c main.c -fopenmp

clean:
	rm *.o