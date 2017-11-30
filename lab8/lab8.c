#include <stdio.h>
#include <math.h>
#include <mpi.h>
#include "functions.h"

#define MAX_MESSAGE_LENGTH 8

// define tags for different types of messages
#define DOUBLE_TAG 9999
#define INT_TAG 1111
#define CHAR_TAG 5555

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
		printf("Parallel Lab 8 Variant 5\n");
	}
	
	double *doublePtr;
	int *intPtr;
	int count;
	MPI_Status status;
	
	char *namePtr, *processorName;
	int nameLength;
	
	switch (rank)
	{
		case 0:
			// creating message with random number of double's
			count = 1 + rand() % MAX_MESSAGE_LENGTH;
			doublePtr = createArrayD(count);
			fillArrayWithRandomNumbersD(doublePtr, count, 50);
			printf("Generated %i double in %i process\n", count, rank);
			printArrayD(doublePtr, count);
						
			// send message in process 1
			MPI_Send(doublePtr, count, MPI_DOUBLE, 1, DOUBLE_TAG, MPI_COMM_WORLD);
			printf("%i sent %i double items to process %i\n", rank, count, 1);
			
			break;
			
		// master process
		case 1:			
			// expecting 3 messages
			for (int i = 0; i < 3; i++)
			{
				// getting status of the received message
				MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
				
				// getting tag of the message
				if (status.MPI_TAG == DOUBLE_TAG)
				{
					// getting size
					MPI_Get_count(&status, MPI_DOUBLE, &count);
					doublePtr = createArrayD(count);
					
					// receive message from system to user-defined buffer
					MPI_Recv(doublePtr, count, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
					
					printf("Received message of %i doubles\n", count);
				}
				else if (status.MPI_TAG == INT_TAG)
				{
					MPI_Get_count(&status, MPI_INT, &count);
					intPtr = createArray(count);
					MPI_Recv(intPtr, count, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
					
					printf("Received message of %i ints\n", count);
				}
				
				/* Not working, need to be revised
				else if (status.MPI_TAG == CHAR_TAG)
				{
					MPI_Get_count(&status, MPI_CHAR, &count);
					namePtr = (char*) malloc(count * sizeof(char));
					MPI_Recv(namePtr, count, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
					
					printf("Received message of %i chars\n", count);
				}
				*/
			}
			
			MPI_Barrier(MPI_COMM_WORLD);
			printf("All messages received!\n");
			
			break;
			
		/*	Not working, need to be revised
		case 2:
			// create message that contains processor name
			processorName = (char*) malloc(MPI_MAX_PROCESSOR_NAME * sizeof(char));
			MPI_Get_processor_name(processorName, &nameLength);
			printf("Generated name %s in %i process\n", processorName, rank);
			
			// send message to process 1
			MPI_Send(processorName, nameLength, MPI_CHAR, 1, CHAR_TAG, MPI_COMM_WORLD);
			printf("%i sent char items to process %i\n", rank, 1);
			
			break;
		*/	
		case 3:
			// creating message with random number of int's
			count = 1 + rand() % MAX_MESSAGE_LENGTH;
			intPtr = createArray(count);
			fillArrayWithRandomNumbers(intPtr, count, 60);
			printf("Generated %i int in %i process\n", count, rank);
			printArray(intPtr, count);
			
			// send message in process 1
			MPI_Send(intPtr, count, MPI_INT, 1, INT_TAG, MPI_COMM_WORLD);
			printf("%i sent %i int items to process %i\n", rank, count, 1);
			
			break;
	}
	
	// waiting for finishing all processes
	MPI_Barrier(MPI_COMM_WORLD);
	
	// cleaning-up
	freeArrayMemoryD(doublePtr);
	freeArrayMemory(intPtr);
	free(processorName);
	free(namePtr);
	
	// finalization
	MPI_Finalize();
	
	return 0;
}
