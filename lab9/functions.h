#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int* createArray(int);
double* createArrayD(int);
int** createMatrix(int, int);

void fillMatrixWithRandomNumbers(int**, int, int, int);
void fillMatrixWithNumbers(int**, int, int);

void fillArrayWithRandomNumbers(int*, int, int);
void fillArrayWithRandomNumbersD(double*, int, int);
void fillArrayWithNumbers(int*, int);

void printArray(int*, int);
void printArrayD(double*, int);

void printMatrix(int**, int, int);

void freeMatrixMemory(int**, int);
void freeArrayMemory(int*);
void freeArrayMemoryD(double*);

int matrixColumnSum(int**, int, int);
int maxArrayValue(int*, int);

void multArrayOnNumber(int*, int, int);

double f(double);
double leftPectanglesIntegral(double, double, int);
