#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "functions.h"

#define MATRIX_ROWS 3000
#define MATRIX_COLUMNS 3000

int main(int argc, char **argv)
{
	printf("Parallel Lab 10 Variant 5");
	
	// creating matrix with random numbers
	int **matrix = createMatrix(MATRIX_ROWS, MATRIX_COLUMNS);
	fillMatrixWithRandomNumbers(matrix, MATRIX_ROWS, MATRIX_COLUMNS, 99);
	//printMatrix(matrix, MATRIX_ROWS, MATRIX_COLUMNS);
	
	// MPI initialization
	int size, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int **returnBuffer = createMatrix(MATRIX_ROWS, MATRIX_COLUMNS);

	// setting-up sync
	MPI_Barrier(MPI_COMM_WORLD);
	
	// starting timer
	double start_time = MPI_Wtime();
	
	// do something important
	MPI_Reduce(matrix, returnBuffer, MATRIX_ROWS * MATRIX_COLUMNS, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	// finishing timer and prints elapsed time
	double end_time = MPI_Wtime() - start_time;
	double elapsed_milliseconds = 1000 * (end_time - start_time);
	printf("Time elapsed = %lf ms\n", elapsed_milliseconds);

	// prints result
	printf("Sum of matrix = %i \n", returnBuffer[0][0]);
		
	// cleaning-up and finalizing
	freeMatrixMemory(matrix, MATRIX_ROWS);
	freeMatrixMemory(returnBuffer, MATRIX_ROWS);
	MPI_Finalize();
	
	return 0;
}
