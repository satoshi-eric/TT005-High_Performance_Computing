main: main.o MatrixIO.o  multMatrix.o
	mpicc main.c -o ../bin/main

main.o: main.c
	mpicc -c main.c

MatrixIO.o: MatrixIO.c MatrixIO.h
	gcc -c MatrixIO.c
  
multMatrix.o: multMatrix.c multMatrix.h
	mpicc -c multMatrix.c

clean:
	rm  ../bin/main
