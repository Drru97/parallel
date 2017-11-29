#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
	// MPI initialization
	MPI_Init(&argc, &argv);
	
	int size, rank;
	
	// Getting task count
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	// Getting task number
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0)
	{
		printf("Parallel Lab 6\n");
	}
	
	// Getting processor name
	char *processorName;
	int nameLength;
	MPI_Get_processor_name(processorName, &nameLength);
	
	printf("I am %i process from %i (%s) processes!\n", rank, size, processorName);
	
	// finalization
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	
	return 0;
}
