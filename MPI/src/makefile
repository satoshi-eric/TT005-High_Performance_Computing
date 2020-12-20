main: main.o MatrixIO.o  multMatrix.o
	gcc main.c -o ../bin/main

main.o: main.c
	gcc -c main.c

MatrixIO.o: MatrixIO.c MatrixIO.h
	gcc -c MatrixIO.c
  
multMatrix.o: multMatrix.c multMatrix.h
	mpirun -n 4 -hostfile ../hosts ../bin/multMatrix

clean:
	rm *.o main
