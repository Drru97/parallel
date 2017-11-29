#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "functions.h"

double f(double);

#define THREADS_NUMBER 4

int main(int argc, char **argv)
{
	printf("Parallel Lab 4 Variant 5\n");
	
	// left and rignt limit of integration
	double a, b;
	
	// number of intervals (must be even)
	int n;
	
	// set-up input values for Simpson method
	printf("Left limit of integraiton = ");
	scanf("%lf", &a);
	printf("Right limit of integration = ");
	scanf("%lf", &b);
	printf("Number of intervals for integration = ");
	scanf("%i", &n);
	
	// checks in intervals number is even
	if (!isEven(n))
	{
		printf("Number of intervals must be even!\n");
		return 1;
	}
	
	// creates arrays for data
	double *x = createArray(n + 1);
	double *y = createArray(n + 1);
	
	// calculate step
	double h = (b - a) / n;
	
	// function tabulation
	for (int i = 0; i < n + 1; i++)
	{
		x[i] = a + i * h;
		y[i] = f(x[i]);
	}
	
	// setting-up threads number for OpenMP
	omp_set_num_threads(THREADS_NUMBER);

	// initialize lock
	omp_lock_t lock;
	omp_init_lock(&lock);
	
	double sum;
	double start_time = omp_get_wtime();

	// integral calculation
	#pragma omp parallel for reduction(+: sum)
	for (int i = 1; i < n; i += 2)
	{
		omp_set_lock(&lock);
		sum = sum + 4.0 * y[i];
		omp_unset_lock(&lock);
	}
	
	#pragma omp parallel for reduction(+: sum)
	for (int i = 2; i < n - 1; i += 2)
	{
		omp_set_lock(&lock);
		sum = sum + 2.0 * y[i];
		omp_unset_lock(&lock);
	}
	
	// print threads number
	printf("Threads count = %i\n", omp_get_max_threads());
	
	double integral = h / 3.0 * (y[0] + y[n] + sum);
	printf("Integral = %lf\n", integral);
	
	// calculate elapsed time
	double end_time = omp_get_wtime();
	double elapsed_milliseconds = 1000 * (end_time - start_time);
	printf("Time elapsed = %lf ms\n", elapsed_milliseconds);
	
	// cleaning-up
	freeArrayMemory(x);
	freeArrayMemory(y);
	
	return 0;
}

double f(double x)
{
	return sin(x);
}
