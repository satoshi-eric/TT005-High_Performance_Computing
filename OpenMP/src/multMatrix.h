#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define posicao(I, J, COLUNAS) ((I)*(COLUNAS) + (J))

/**
 * Funcao para multiplicar matrizes alocadas em uma única etapa
 * 
 * @param lin1 número de linhas da primeira matriz
 * @param col1 número de colunas de primeira matriz
 * @param matrix1 endereço da primeira matriz
 * @param lin2 número de linhas da segunda matriz
 * @param col2 número de colunas da segunda matriz
 * @param matrix2 endereço da segunda matriz
 * 
 * @return Endereço para a matriz multiplicação das mmatrizes matrix1 e matrix2
 * 
 */ 
float *multMatrix(int lin1, int col1, float *matrix1, int lin2, int col2, float *matrix2)
{
    /* Verificando se é possível multiplicar as 2 matrizes */
    if (col1 != lin2)
    {
        printf("The number of matrix 1 columns is different to number of matrix 2 lines \n");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Variáveis para a matriz matrix3
        int lin3 = lin1;
        int col3 = col2;
        float *matrix3 = (float *)malloc(lin3 * col3 * sizeof(float));

        //Contadores
        int i, j, k;

        #pragma omp parallel for num_threads(4) private(i, j, k)
        // Percorre as linhas da matriz1
        for (i = 0; i < lin1; i++)
        {
            // Percorre as colunas da matriz2
            for (j = 0; j < col2; j++)
            {
                 matrix3[posicao(i, j, col3)] = 0;
                // Somatório de cada elemento da multiplicação de matrizes
                for (k = 0; k < col1; k++)
                {
                    matrix3[posicao(i, j, col3)] += (matrix1[posicao(i, k, col1)] * matrix2[posicao(k, j, col2)]);
                }
            }
        }

        return matrix3;
    }
}

/**
 * Função para somar todos os elementos da matriz
 * 
 * @param lin número de linhas da matriz
 * @param col número de colunas da matriz
 * @param matrix ponteiro para a matriz 
 * 
 * @return Soma de todos os elementos da matriz
 */ 
float reductionSum(int lin, int col, float *matrix)
{
    float sum = 0;

    #pragma parallel for num_threads(4) reduction(+:sum)
    // Itrando pelos elementos da matriz
    for (int i = 0; i < lin*col; i++)
    {
        sum += matrix[i];
    }

    return sum;
}