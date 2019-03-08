/*
 * C_HW1
 * Q2.h
 *
 *  Created on: Nov 16, 2018
 *      Author: itai
 */

#ifndef Q2_H_
#define Q2_H_

#define N 4
#define M 4
#define SHUFFEL_COUNT 30
#define EMPTY_CELL 0
#define INVALID_COICE -1

typedef enum {
	FALSE, TRUE
} boolean;

boolean isSorted(int* arr, int row, int col);
void matrixRadomize(int *arr, int r, int c, int* rowOfZeroLocation,
		int* colOfZeroLocation);
void isValidUserChoice(int* board, int choice, int zeroRow, int zeroCol, int* i,
		int*j, int rows, int cols);
void moveHandler(int* board, int move, int zeroRow, int zeroCol, int* i, int* j,
		int rows, int cols);

void numberGame(int row, int col);

#endif /* Q2_H_ */
