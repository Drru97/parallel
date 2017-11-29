#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

int* createArray(int);
int** createMatrix(int, int);

void fillMatrixWithRandomNumbers(int**, int, int, int);
void fillMatrixWithNumbers(int**, int, int);

void fillArrayWithRandomNumbers(int*, int, int);
void fillArrayWithNumbers(int*, int);

void printArray(int*, int);
void printMatrix(int**, int, int);

void freeMatrixMemory(int**, int);
void freeArrayMemory(int*);

int matrixColumnSum(int**, int, int);
int maxArrayValue(int*, int);

int** matrixMultiplication(int**, int**, int);
