#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include "../auxMatrix/MatrixIO.h"
#include "multMatrix.h"

/**
 * A y x w 
 * B w x v 
 * C v x 1
 * D y x 1
 * 
 * ./main y w v arqA.dat arqB.dat arqC.dat arqD.dat 
 * 
 * y é o número de linhas da primeira matriz. 
 * w é o número de colunas da primeira matriz e de linhas da segunda matriz. 
 * v é o número de colunas da segunda matriz e de linhas da terceira matriz. 
 * arqA.dat é o nome do arquivo que contém a primeira matriz. 
 * arqB.dat é o nome do arquivo que contém a segunda matriz. 
 * arqC.dat é o nome do arquivo que contém a terceira matriz. 
 * arqD.dat é o nome do arquivo que contém a matriz resultante da computação
 * 
 */
// https://moodle.ggte.unicamp.br/pluginfile.php/1080242/mod_resource/content/3/EspecificacaoLaboratorios.pdf
// https://github.com/gradvohl/TT005_Laboratorios

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

        if (y < 1 || w < 1 || v < 1)
        {
            fprintf(stderr, "numero de linhas das matrizes incorreto\n");
        }
        else
        {
            char *filename1 = (char *)malloc(100 * sizeof(char));
            char *filename2 = (char *)malloc(100 * sizeof(char));
            char *filename3 = (char *)malloc(100 * sizeof(char));
            char *filenameOut = (char *)malloc(100 * sizeof(char));

            strcpy(filename1, argv[4]);
            strcpy(filename2, argv[5]);
            strcpy(filename3, argv[6]);
            strcpy(filenameOut, argv[7]);

            double *matrix1 = readMatrixDouble(y, w, filename1);
            double *matrix2 = readMatrixDouble(w, v, filename2);
            double *matrix3 = readMatrixDouble(v, 1, filename3);

            /**
             * A y x w 
             * B w x v 
             * C v x 1
             * D y x 1
             */

            double *matrix4 = multMatrix(y, w, matrix1, w, v, matrix2);
            double *matrixRes = multMatrix(y, v, matrix4, v, 1, matrix3);

            printMatrixDouble(matrixRes, y, 1, filenameOut);
        }
    }
    

    return 0;
}