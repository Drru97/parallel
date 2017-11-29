#include <stdio.h>
#include <omp.h>

#define THREADS_NUMBER 4

int main(int argc, char **argv)
{
	printf("Parallel Lab 1\n");
	
	omp_set_num_threads(THREADS_NUMBER);
	
	int processorsCount = omp_get_num_procs();
	int threadNumber, maxThreads;
	#pragma omp parallel private(threadNumber) num_threads(THREADS_NUMBER) shared(processorsCount, maxThreads)
	{
		printf("Processors count = %i\n", processorsCount);
		threadNumber = omp_get_thread_num();		
		maxThreads = omp_get_max_threads();
		printf("I am thread %i from %i threads!\n", threadNumber, maxThreads);
	}
	
	return 0;
}
