/**
 * Programa para gerar um arquivo com uma matriz com valores inteiros.
 *
 * Autor Andre Leon S. Gradvohl, Dr.
 *
 * Ultima atualizacao: Sex 13 Out 2017 19:23:49 -03
 *
 * Observacao: os nomes das funcoes estao em ingles.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MatrixIO.h"

/**
 * Funcao para gerar uma matriz com numeros inteiros.
 *
 * @param lines Numero de linhas da matriz.
 * @param columns Numero de colunas da matriz.
 * @param lowerLimit Valor do menor inteiro na matriz.
 * @param upperLimit Valor do maior inteiro na matriz.
 *
 * @return Ponteiro para uma matriz com lines x columns
 */ 
int *generateRandomMatriz(unsigned int lines, unsigned int columns, int lowerLimit, int upperLimit)
{
 register unsigned int i, j;

 int *mat = (int *) malloc(sizeof(int) * lines * columns);

 if (mat == NULL)
 {
     perror("I cannot allocate memory\n");
     exit(EXIT_FAILURE);
     return NULL;
 }

 /* Cria a semente para a geração de numeros aleatorios.*/
 srand( time(NULL) );

 /* Preenche a matriz com numeros aleatorios entre o limite inferior e limite superior.*/
 for (i=0; i<lines; i++)
     for(j=0; j<columns; j++)
        mat[i*columns + j] = (rand() % ((upperLimit + 1) - lowerLimit)) + lowerLimit;

 return mat;
}