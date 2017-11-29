#include "functions.h"

double* createArray(int length)
{
	double* array = (double*) malloc(length * sizeof(double));
	return array;
}

bool isEven(int value)
{
	if (value % 2 == 0)
		return true;
	else
		return false;
}

void freeArrayMemory(double* array)
{
	free(array);
}
