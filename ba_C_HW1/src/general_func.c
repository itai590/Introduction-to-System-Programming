/*
 * C_HW1
 * general_func.c
 *
 *  Created on: Nov 13, 2018
 *      Author: itai
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "general_func.h"

int getRandom(int min, int max) {
	return min + rand() % (max - min + 1);
}

void initRandomMatrix(int* matrix, int r, int c) {
	srand(time(NULL));
	for (int i = 0; i < r * c; i++)
		*(matrix + i) = getRandom(MIN_RANDOM, MAX_RANDOM);
}

void printMatrix(int* matrix, int r, int c) {
	int i;
	for (i = 0; i < r * c; i++) {
		if (i % c == 0 && i != 0)
			printf("\n");
		printf("%5d", *(matrix + i));
	}
	printf("\n");
}

void swap(int* a1, int *a2) {
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

void transposeMatrix(int* arr, int row, int col) {
	for (int i = 0; i < row; i++)
		for (int j = i; j < col; j++)
			swap(arr + i * col + j, arr + j * col + i);
}
