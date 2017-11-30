#include <stdio.h>
#include <mpi.h>
#include "functions.h"

double f(double);

#define DATA_TAG 9999

int main(int argc, char **argv)
{
	// MPI initialization
	MPI_Init(&argc, &argv);
	
	int size, rank;
	
	// Getting task count
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	// Getting task number
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	// master thread
	if (rank == 0)
	{
		printf("Parallel Lab 9 Variant 5\n");
			
		// left and rignt limit of integration
		double a = -5, b = 10;
	
		// number of intervals
		int n = 1000000;
		
		// pack data into array
		double data[] = { a, b, n};		
		MPI_Request sendRequest;
		
		// sending data to another processes
		for (int i = 1; i < size; i++)
		{
			printf("Sending data to process %i\n", i);
			MPI_Isend(&data, 3, MPI_DOUBLE, i, DATA_TAG, MPI_COMM_WORLD, &sendRequest);
		}
	}
	
	// receiving data
	else
	{
		double data[3];
		MPI_Request receiveRequest;
				
		// starting timer
		double start_time = MPI_Wtime();
		
		printf("Process %i received data from process 0\n", rank);
		MPI_Irecv(&data, 3, MPI_DOUBLE, 0, DATA_TAG, MPI_COMM_WORLD, &receiveRequest);
		
		// waiting for transfer
		MPI_Wait(&receiveRequest, MPI_STATUS_IGNORE);
			
		// calculate integral
		double integral = leftPectanglesIntegral(data[0], data[1], data[2]);
		printf("Integral calculated by left rectangles method in process %i = %.3lf\n", rank, integral);
		
		// calculate elapsed time
		double end_time = MPI_Wtime();
		double elapsed_miliseconds = 1000 * (end_time - start_time);
		printf("Elapsed time = %lf ms\n", elapsed_miliseconds);
	}
	
	// finalization
	MPI_Finalize();
	
	return 0;
}
