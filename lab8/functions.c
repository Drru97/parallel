#include "functions.h"

int* createArray(int length)
{
	int* array = (int*) malloc(length * sizeof(int));
	return array;
}

double* createArrayD(int length)
{
	double* array = (double*) malloc(length * sizeof(double));
	return array;
}

int** createMatrix(int rows, int columns) 
{
	int** matrix= (int**) malloc(rows * sizeof(*matrix));
	
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (int*)malloc(columns * sizeof(int));
	}
	
	return matrix;
}

void fillMatrixWithRandomNumbers(int** matrix, int rows, int columns, int maxValue)
{
	// setting-up random generator with seed
	srand(time(NULL));
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = rand() % maxValue;
		}
	}
}

void fillMatrixWithNumbers(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = i * j;
		}
	}
}

void fillArrayWithRandomNumbers(int* array, int length, int maxValue)
{
	// setting-up random generator with seed
	srand(time(NULL));
	
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % maxValue;
	}
}

void fillArrayWithRandomNumbersD(double* array, int length, int maxValue)
{
	// setting-up random generator with seed
	srand(time(NULL));
	
	for (int i = 0; i < length; i++)
	{
		array[i] = 0.3 + rand() % maxValue;
	}
}


void fillArrayWithNumbers(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = i * i;
	}
}

void printArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%i\t", array[i]);
	}
	printf("\n");
}

void printArrayD(double* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%.2lf\t", array[i]);
	}
	printf("\n");
}

void printMatrix(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%i\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void freeMatrixMemory(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void freeArrayMemory(int* array)
{
	free(array);
}

void freeArrayMemoryD(double* array)
{
	free(array);
}

int matrixColumnSum(int** matrix, int rows, int column)
{
	int sum = 0;
	
	for (int i = 0; i < rows; i++)
	{
		sum += matrix[i][column];
	}
	
	return sum;
}

int maxArrayValue(int* array, int length)
{
	int max = array[0];
	
	for (int i = 1; i < length; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}	
	}
	
	return max;
}

void multArrayOnNumber(int* array, int length, int value)
{
	for (int i = 0; i < length; i++)
	{
		array[i] *= value;
	}
}
