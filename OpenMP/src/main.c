#include <stdio.h>
#include <stdlib.h>
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
        printf("%s <numero de linhas> <numero de colunas> <numero de colunas> <arquivo A> <arquivo B> <arquivo C> <arquivo D>", argv[0]);
    }
    else
    {
        int *matrixA = readMatrix(10, 10, "arqD.dat");
        printMatrix(matrixA, 10, 10, NULL);
    }

    int *matrixA = readMatrix(10, 10, "arqD.dat");
    printMatrix(matrixA, 10, 10, NULL);

    return 0;
}