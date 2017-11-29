#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

#define MATRIX_SIZE 512
#define THREADS_NUMBER 4

int main(int argc, char **argv) 
{
	printf("Parallel Lab 5 Variant 3\n");
	
	// creating and filling matrix with random numbers
	int **matrix1 = createMatrix(MATRIX_SIZE, MATRIX_SIZE);
	fillMatrixWithRandomNumbers(matrix1, MATRIX_SIZE, MATRIX_SIZE, 99);
	int **matrix2 = createMatrix(MATRIX_SIZE, MATRIX_SIZE);
	fillMatrixWithRandomNumbers(matrix2, MATRIX_SIZE, MATRIX_SIZE, 49);
	
	//printMatrix(matrix1, MATRIX_SIZE, MATRIX_SIZE);
	//printMatrix(matrix2, MATRIX_SIZE, MATRIX_SIZE);
	
	// setting-up threads number for OpenMP
	omp_set_num_threads(THREADS_NUMBER);
	
	double start_time = omp_get_wtime();
	
	int **multiplication = matrixMultiplication(matrix1, matrix2, MATRIX_SIZE);
	
	// calculate elapsed time
	double end_time = omp_get_wtime();
	double elapsed_milliseconds = 1000 * (end_time - start_time);
	printf("Time elapsed = %lf ms\n", elapsed_milliseconds);
	
	// print threads number
	printf("Threads count = %i\n", omp_get_max_threads());
	
	// print result of multiplication
	//printMatrix(multiplication, MATRIX_SIZE, MATRIX_SIZE);
	
	// cleaning-up
	freeMatrixMemory(matrix1, MATRIX_SIZE);
	freeMatrixMemory(matrix2, MATRIX_SIZE);
	freeMatrixMemory(multiplication, MATRIX_SIZE);
	
	return 0;
}
