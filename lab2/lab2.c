#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "functions.h"

#define MATRIX_ROWS 3000
#define MATRIX_COLUMNS 3000
#define THREADS_NUMBER 4

int main(int argc, char **argv)
{
	printf("Parallel Lab 2 Variant 5\n");
	
	// creating and filling matrix with random numbers
	int **matrix = createMatrix(MATRIX_ROWS, MATRIX_COLUMNS);
	fillMatrixWithRandomNumbers(matrix, MATRIX_ROWS, MATRIX_COLUMNS, 99);
	//printMatrix(matrix, MATRIX_ROWS, MATRIX_COLUMNS);
	
	// setting-up threads number for OpenMP
	omp_set_num_threads(THREADS_NUMBER);
	
	int *columnsMax = createArray(MATRIX_COLUMNS);
	double start_time = omp_get_wtime();
	
	// calculate sum of each matrix column
	#pragma omp parallel for shared(columnsMax)
	for (int i = 0; i < MATRIX_COLUMNS; i++)
	{
		columnsMax[i] = matrixColumnSum(matrix, MATRIX_ROWS, i);
	}
	
	// calculate max column's sum value
	int max = maxArrayValue(columnsMax, MATRIX_COLUMNS);
	
	// calculate elapsed time
	double end_time = omp_get_wtime();
	double elapsed_milliseconds = 1000 * (end_time - start_time);
	printf("Time elapsed = %lf ms\n", elapsed_milliseconds);
	
	// print threads number
	printf("Threads count = %i\n", omp_get_max_threads());
	
	// print maximum column's sum value
	printf("Maximum column sum = %i\n", max);
	
	// cleaning-up
	freeMatrixMemory(matrix, MATRIX_ROWS);
	freeArrayMemory(columnsMax);
	
	return 0;
}
