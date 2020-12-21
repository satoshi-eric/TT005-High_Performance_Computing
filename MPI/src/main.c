#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openacc.h>
#include <time.h>
//#include "MatrixIO.h"
//#include "multMatrix.h"
#include "multMatrix.c"
#include "MatrixIO.c"
#include "mpi.h"

#define TAMANHO 8


int main (int argc, char *argv[])
{
    // Tramento de erro de argumentos fornecidos pelo terminal
    if (argc < 8)
    {
        printf("Uso:\n");
        printf("%s <numero de linhas da matriz A> <numero de linhas da matriz B> <numero de linhas da matriz C> <arquivo A> <arquivo B> <arquivo C> <arquivo D>\n", argv[0]);
    }
    else
    {
        int numtasks, rank;

        // argv: ./main y w v arqA.dat arqB.dat arqC.dat arqD.dat 
        int y = atoi(argv[1]);
        int w = atoi(argv[2]);
        int v = atoi(argv[3]);

        // Tratamento de erro para valores de linhas menores ou iguais a 0
        if (y < 1 || w < 1 || v < 1)
        {
            fprintf(stderr, "numero de linhas das matrizes n�o pode ser menor ou igual a zero\n");
        }
        else
        {     
            MPI_Init(&argc, &argv);   
            MPI_Comm_rank(MPI_COMM_WORLD, &rank);
            MPI_Comm_size(MPI_COMM_WORLD, &numtasks);


        		if(numtasks == TAMANHO){
              int numThreads = 4;    
              // Lendo matrizes
              float *matrix1 = readMatrixFloat(y, w, argv[4]);
              float *matrix2 = readMatrixFloat(w, v, argv[5]);
              float *matrix3 = readMatrixFloat(v, 1, argv[6]);
              
              clock_t begin = clock(); // Calculando tempo de execu��o da multiplica��o
              
              float *matrixRes = multMatrix(y, v, multMatrix(y, w, matrix1, w, v, matrix2), v, 1, matrix3); // Multiplica��o de matrizes
  
              clock_t end = clock(); // Calculando tempo de execu��o da multiplica��o
  
              double time = ((double) (end - begin)/ (CLOCKS_PER_SEC)); // Tempo de execu��o da multiplica��o
              
              printf("Time to multiply the matrices %.8lf s\n", time);
  
              printf("Reduction sum: %.2f\n", reductionSum(y, 1, matrixRes));
  
              printMatrixFloat(matrixRes, y, 1, argv[7]);
  	        
              MPI_Finalize();
        		}else{
              printf("O programa requer %d processadores.\n",TAMANHO);
            }
        }
    }

    		
    return 0;
}
