main: main.o MatrixIO.o  multMatrix.o
	gcc -fopenacc main.o MatrixIO.o multMatrix.o -o main

main.o: main.c
	gcc  -c main.c

MatrixIO.o: MatrixIO.c MatrixIO.h
	gcc -c MatrixIO.c
  
multMatrix.o: multMatrix.c multMatrix.h
	gcc -c multMatrix.c -fopenacc
  
clean:
	rm *.o main
