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

		#pragma acc parallel loop collapse(2) copyin(matrix3[0:lin3*col3])
		for ( i=0; i<lin1; i++ )
		{
			for ( j=0; j<col2; j++)
			{
				
				// Multiplicação de matrizes
				matrix3[posicao(i, j, col3)] = 0; 

			}
		}

		#pragma acc collapse(3)  data copyout(matrix3[0:lin3*col3]) copyin(matrix1[0:lin1*col1], matrix2[0:lin2*col2]) 
		for (i=0; i<lin1; i++)
		{
			for (j=0; j<col2; j++)
			{
				for (k=0; k<col1; k++)
				{
					matrix3[posicao(i, j, col3)] += matrix1[posicao(i, k, col1)] * matrix2[posicao(k, j, col2)];
				}
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

	#pragma acc parallel loop reduction(+:sum)
	// Itrando pelos elementos da matriz
	for (int i = 0; i < lin*col; i++)
	{	
		sum += matrix[i];
	}

	return sum;
}
