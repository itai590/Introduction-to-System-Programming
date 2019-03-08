#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "q2.h"

// Prints two dimensional matrix by rows
void printMatrix(int *matrix, int rows, int columns) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			printf("%-5d", *(matrix + i * columns + j));
		printf("\n");
	}
}

void printArrEzer(Array** arr, int rows) {
	printf("printArrEzer\n");
	for (int i = 0; i < rows; i++)
		printf("row:%d sum:%d\n", arr[i]->row, arr[i]->sum);
}

void sortMatrix(int *matrix, int rows, int columns, int func(int*, int)) {
	Array** arrayArr = (Array**) malloc(sizeof(Array*) * rows);
	/* create array ezer */
	for (int i = 0; i < rows; i++) {
		arrayArr[i] = (Array*) malloc(sizeof(Array));
		arrayArr[i]->row = i;
		arrayArr[i]->sum = func(matrix + i * columns, columns);

	}

	//printf("\nBefore sorting ");
	//printArrEzer(arrayArr, rows);
	qsort(arrayArr, rows, sizeof(Array*), compareBySum);
	//printf("After sorting ");
	//printArrEzer(arrayArr, rows);

	int* tmp = (int*) calloc(columns * rows, sizeof(int));
	memcpy(tmp, matrix, sizeof(int) * columns * rows);

	for (int i = 0; i < rows; i++)
		memcpy(matrix + columns * i, tmp + columns * (arrayArr[i]->row), sizeof(int) * columns);

}

// Sort a matrix using "sum of elements in row" criteria
void sortMatrixRowsBySum(int *matrix, int rows, int columns) {
	sortMatrix(matrix, rows, columns, sumRow);
}

// Sort a matrix using "number of non zero bits in row" criteria
void sortMatrixRowsByBits(int *matrix, int rows, int columns) {
	sortMatrix(matrix, rows, columns, bitsRow);
}

void copyArray(int *to, int *from, int size) {
	for (int i = 0; i < size; i++)
		to[i] = from[i];
}

int sumRow(int *matrix, int columns) {
	int sum = 0;
	for (int i = 0; i < columns; i++)
		sum += matrix[i];

	return sum;
}

int bitsRow(int *matrix, int columns) {
	int sum = 0;
	for (int i = 0; i < columns; i++)
		sum += calcNumberOfOnes(matrix[i]);

	return sum;
}

int calcNumberOfOnes(int n) {
	int sum = 0;
	int temp = n;

	for (int i = 0; i < 8 * sizeof(int); i++) {
		sum = sum + (temp & 0x01);
		temp = temp >> 1;
	}
	return sum;
}
int compareBySum(const void* arr1, const void* arr2) {

	Array* arrr1 = *(Array**) arr1;
	Array* arrr2 = *(Array**) arr2;
	return arrr1->sum - arrr2->sum;
}

int Q2(void) {

	int matrixSum[4][3] = { { 10, 20, 30 }, { 2, 4, 3 }, { 100, 200, 300 }, {50, 60, 70 } };

	int matrixBits[4][3] = { { 0, 0, 7 }, { 1, 1, 3 }, { 7, 7, 7 }, { 1, 0, 1 } };

// Sort matrixSum by the sum of elements in row
	printf("Before sorting\n");
	printMatrix((int*) matrixSum, 4, 3);

	sortMatrixRowsBySum((int*) matrixSum, 4, 3);

	printf("\nAfter sorting\n");
	printMatrix((int*) matrixSum, 4, 3);

	printf("\n========\n\n");

// Sort matrixBits by the sum of non zero bits of all elements in row
	printf("Before sorting\n");
	printMatrix((int*) matrixBits, 4, 3);

	sortMatrixRowsByBits((int*) matrixBits, 4, 3);

	printf("\nAfter sorting\n");
	printMatrix((int*) matrixBits, 4, 3);

	return EXIT_SUCCESS;
}

