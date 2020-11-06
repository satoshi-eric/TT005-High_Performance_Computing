#include <stdio.h>
#include <stdlib.h>
#include "../auxMatrix/MatrixIO.h"
#include "multMatrix.h"
#include <omp.h>

int main()
{
  int *matrix1 = readMatrix(2, 3, "arqA.dat");
  int *matrix2 = readMatrix(3, 2, "arqB.dat");
  int *matrix3 = multMatrix(2, 3, matrix1, 3, 2, matrix2);
  printMatrix(matrix3, 2, 2, "arqC.dat");

  #pragma omp parallel 
  {
    printf("Hello from thread %d\n", omp_get_thread_num());
  }
}