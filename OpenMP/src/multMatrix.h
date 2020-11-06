#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

// Matrix 2x3 multplication Matrix 3x2 = Matrix 3x3
// Matrix num_linhas num_colunas

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
double *multMatrix(int lin1, int col1, double *matrix1, int lin2, int col2, double *matrix2)
{
    /* Verificando se é possível multiplicar as 2 matrizes */
    if (col1 != lin2)
    {
        printf("O numero de colunas da matriz 1 e diferente do numero de linhas da matriz 2\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Variáveis para a matriz matrix3
        int lin3 = lin1;
        int col3 = col2;
        int number_el = lin2;
        double *matrix3 = (double *)malloc(lin3 * col3 * sizeof(double));

        int begin = time(NULL);

        #pragma omp parallel for num_threads(4)
        for (int i = 0; i < lin1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                matrix3[col3*i + j] = 0;
                for (int k = 0; k < number_el; k++)
                {
                    matrix3[col3*i + j] += (matrix1[col1*i + k] * matrix2[col2*k + j]);
                }
            }
        }

        int end = time(NULL);
        printf("%d\n", end - begin);

        return matrix3;
    }
}

