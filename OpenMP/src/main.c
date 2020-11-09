#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include "auxMatrix/MatrixIO.h"
#include "multMatrix.h"


int main (int argc, char *argv[])
{
    if (argc < 8)
    {
        printf("Uso:\n");
        printf("%s <numero de linhas da matriz A> <numero de linhas da matriz B> <numero de linhas da matriz C> <arquivo A> <arquivo B> <arquivo C> <arquivo D>\n", argv[0]);
    }
    else
    {
        // argv: ./main y w v arqA.dat arqB.dat arqC.dat arqD.dat 
        int y = atoi(argv[1]);
        int w = atoi(argv[2]);
        int v = atoi(argv[3]);

        // Tratamento de erro para valores de linhas menores ou iguais a 0
        if (y < 1 || w < 1 || v < 1)
        {
            fprintf(stderr, "numero de linhas das matrizes não pode ser menor ou igual a zero\n");
        }
        else
        {            
            // Lendo matrizes
            float *matrix1 = readMatrixFloat(y, w, argv[4]);
            float *matrix2 = readMatrixFloat(w, v, argv[5]);
            float *matrix3 = readMatrixFloat(v, 1, argv[6]);

            clock_t begin = clock();
            // Multiplicação de matrizes
            float *matrixRes = multMatrix(y, v, multMatrix(y, w, matrix1, w, v, matrix2), v, 1, matrix3);
            clock_t end = clock();

            double time = ((double) (end - begin)/ (CLOCKS_PER_SEC))/omp_get_num_threads();
            printf("%.2lf s\n", time);

            printMatrixFloat(matrixRes, y, 1, argv[7]);
        }
    }


    return 0;
}