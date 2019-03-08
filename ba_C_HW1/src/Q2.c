/*
 * C_HW1
 * Q2.c
 *
 *  Created on: Nov 16, 2018
 *      Author: itai
 */

#ifndef Q2_C_
#define Q2_C_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Q2.h"
#include "general_func.h"

boolean isSorted(int* arr, int row, int col) {
	int size = row * col;
	for (int i = 1; i < size; i++)
		if (*(arr + i - 1) != i)
			return FALSE;

	return TRUE;
}

void matrixRadomize(int *arr, int r, int c, int* rowOfZeroLocation,
		int* colOfZeroLocation) {
	srand(time(NULL));
	for (int i = 0; i <= SHUFFEL_COUNT; i++) {

		int r1 = getRandom(0, r - 1);
		int c1 = getRandom(0, c - 1);
		int r2 = getRandom(0, r - 1);
		int c2 = getRandom(0, c - 1);

		if (*(arr + r1 * c + c1) == 0) {
			*rowOfZeroLocation = r2;
			*colOfZeroLocation = c2;
		} else if (*(arr + r2 * c + c2) == 0) {
			*rowOfZeroLocation = r1;
			*colOfZeroLocation = c1;
		}

		swap(arr + r1 * c + c1, arr + r2 * c + c2);
	}
}

void initMatrixSequential(int *arr, int r, int c) {
	for (int i = 0; i < r * c; i++) {
		*(arr + i) = i;
	}
}

void isValidUserChoice(int* board, int choice, int zeroRow, int zeroCol, int* i,
		int*j, int rows, int cols) {

	*i = zeroRow;
	*j = zeroCol;

	if (zeroRow > 0)
		if (choice == *(board + (zeroRow - 1) * cols + zeroCol)) {
			*i = zeroRow - 1;
			return;
		}

	if (zeroRow < rows - 1)
		if (choice == *(board + (zeroRow + 1) * cols + zeroCol)) {
			*i = zeroRow + 1;
			return;
		}

	if (zeroCol > 0)
		if (choice == *(board + zeroRow * cols + zeroCol - 1)) {
			*j = zeroCol - 1;
			return;
		}

	if (zeroCol < cols - 1)
		if (choice == *(board + zeroRow * cols + zeroCol + 1)) {
			*j = zeroCol + 1;
			return;
		}
	*i = INVALID_COICE;
	*j = INVALID_COICE;
}

void moveHandler(int* board, int move, int zeroRow, int zeroCol, int* i, int* j,
		int rows, int cols) {

	puts("Your step:");
	scanf("%d", &move);
	getchar(); //clean the buffer
	isValidUserChoice((int*) board, move, zeroRow, zeroCol, i, j, rows, cols);
}



void numberGame(int row, int col) {

	int rowOfZero = 0;
	int colOfZero = 0;

	int game_board[N][M];

	initMatrixSequential((int*) game_board, row, col);
	matrixRadomize((int*) game_board, row, col, &rowOfZero, &colOfZero);


	/* 2 moves to win matrix initialization */
//	int game_board[N][M] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 },
//			{ 13, 0, 14, 15 } };
//	rowOfZero = 3;
//	colOfZero = 1;


	printMatrix((int*) game_board, row, col);
	//printf("zero loc: arr[%d][%d]\n", rowOfZero, colOfZero);

	boolean win = FALSE;

	while (!win) {

		int move = 0, i, j;

		moveHandler((int*) &game_board, move, rowOfZero, colOfZero, &i, &j, row,
				col);

		while (i == INVALID_COICE && j == INVALID_COICE) {

			puts("Invalid input");
			moveHandler((int*) &game_board, move, rowOfZero, colOfZero, &i, &j,
					row, col);
		}

		swap((int*) game_board + i * col + j,
				(int*) game_board + rowOfZero * col + colOfZero);

		rowOfZero = i;
		colOfZero = j;

		printMatrix((int*) game_board, row, col);

		if (isSorted((int*) game_board, row, col)) {
			puts("You win! The game is over!");
			win = TRUE;
		}

	}
}

#endif /* Q2_C_ */
