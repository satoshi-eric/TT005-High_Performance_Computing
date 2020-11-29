#include "multMatrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <openacc.h>

#define posicao(I, J, COLUNAS) (I*COLUNAS + J)


/**
 * Função para multiplicar matrizes
 *
 * @param lin1 número de linhas da matriz1
 * @param col1 número de colunas da matriz1
 * @param matrix1 ponteiro para a matriz1 
 * @param lin2 número de linhas da matriz2
 * @param col2 número de colunas da matriz2
 * @param matrix2 ponteiro para a matriz2
 *
 * @return ponteiro para resultado da multiplicação das matrizes matrix3
 */ 
float *multMatrix ( int lin1, int col1, float *matrix1, int lin2, int col2, float *matrix2)
{
	/* Verificando se é possível multiplicar as 2 matrizes */
	if (col1 != lin2)
	{
		fprintf(stderr, "The number of columns in matrix1 is different from the number of rows in matrix2\n");
	}
	else
	{
		// Variáveis para a matriz 3: resultado
		int lin3 = lin1;
		int col3 = col2;
		float *matrix3 = (float *) malloc(lin3 * col3 * sizeof(float));

		// Contadores
		int i, j, k;

		#pragma acc parallel loop
		for ( i=0; i<lin1; i++ )
		{
			// Inicializando matriz3
			matrix3[posicao(i, j, col3)] = 0;
			for ( j=0; j<col2; j++)
			{
				// Multiplicação de matrizes
				matrix3[posicao(i, j, col3)] += matrix1[posicao(i, j, col3)] * matrix3[posicao(i, j, col3)]; 

			}
		}
		return matrix3;
	}	
}

/**
 * Fun��o para somar todos os elementos da matriz
 * 
 * @param lin n�mero de linhas da matriz
 * @param col n�mero de colunas da matriz
 * @param matrix ponteiro para a matriz 
 * 
 * @return Soma de todos os elementos da matriz
 */ 
float reductionSum(int lin, int col, float *matrix)
{
    float sum = 0;

	#pragma acc parallel loop
	// Itrando pelos elementos da matriz
	for (int i = 0; i < lin*col; i++)
	{	
		sum += matrix[i];
	}

	return sum;
}