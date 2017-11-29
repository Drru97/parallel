#include <stdio.h>
#include <mpi.h>
#include "functions.h"

#define ARRAY_LENGTH 3

int main(int argc, char **argv)
{
	// MPI initialization
	MPI_Init(&argc, &argv);
	
	int size, rank;
	
	// Getting task count
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	// Getting task number
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	// print lab number
	if (rank == 0)
	{
		printf("Parallel Lab 7\n");
	}
	
	int *vector, *recvBuffer;
	MPI_Status status;

	switch (rank)
	{
		case 0:
			// create vector with random data
			vector = createArray(ARRAY_LENGTH);
			fillArrayWithRandomNumbers(vector, ARRAY_LENGTH, 10);
			
			// print sent data
			printf("Sent data from %i to %i process: \n", rank, 1);
			printArray(vector, ARRAY_LENGTH);
			
			// send vector to another process
			MPI_Rsend(vector, ARRAY_LENGTH, MPI_INT, 1, 0, MPI_COMM_WORLD);
				
			// receive data in primary process
			MPI_Recv(vector, ARRAY_LENGTH, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
			
			// print received data in primary process
			printf("Received multiplicated data from %i in %i process: \n", 1, rank);
			printArray(vector, ARRAY_LENGTH);
			
			break;
			
		case 1:
			// receive sent data in another process
			recvBuffer = createArray(ARRAY_LENGTH);
			MPI_Recv(recvBuffer, ARRAY_LENGTH, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
			
			// print received data
			printf("Received data from %i in %i process: \n", 0, rank);
			printArray(recvBuffer, ARRAY_LENGTH);
			
			// multiply vector on 5
			multArrayOnNumber(recvBuffer, ARRAY_LENGTH, 5);
			
			printf("Multiplicated data: \n");
			printArray(recvBuffer, ARRAY_LENGTH);
						
			// send multiplicated vector to primary process
			MPI_Rsend(recvBuffer, ARRAY_LENGTH, MPI_INT, 0, 1, MPI_COMM_WORLD);
			
			break;
	}
	
	// waiting for finishing all processes
	MPI_Barrier(MPI_COMM_WORLD);

	// cleaning-up
	freeArrayMemory(vector);
	freeArrayMemory(recvBuffer);
	
	// finalization
	MPI_Finalize();
	
	return 0;
}
