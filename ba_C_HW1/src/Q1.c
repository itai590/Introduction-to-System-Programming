/*
 * C_HW1
 * Q1.C
 *
 *  Created on: Nov 16, 2018
 *      Author: itai
 */
#include <stdio.h>
#include "general_func.h"
#include "Q1.h"

/* 1 */
void flip90Clockwise(int* arr, int row, int col) {
	transposeMatrix(arr, row, col);
	flipVertical(arr, row, col);
}

/* 2 */
void flip90Cclockwise(int* arr, int row, int col) {
	flipVertical(arr, row, col);
	transposeMatrix(arr, row, col);
}

/* 3 */
void flipHorizontal(int* arr, int row, int col) {

	int m = row - 1;

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < m; j++, m--) {
			swap((arr + j * col + i), (arr + m * col + i));
		}
		m = row - 1;
	}
}

/* 4 */
void flipVertical(int* arr, int row, int col) {

	int m = col - 1;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < m; j++, m--) {
			swap((arr + i * col + j), (arr + i * col + m));
		}
		m = col - 1;
	}
}



void PictureManipulation(int row, int col) {
	int again = 1;

	int arr[row][col];
	initRandomMatrix((int*) arr, row, col);

	printMatrix((int *)arr, row, col);

	while (again) {
		printf(Q1_MENU);

		int ans = Q1_SWITCH_INIT;
		scanf("%d", &ans);
		while (getchar() != '\n')
			;     // will consume the charters

		switch (ans) {

		case Q1_SWITCH_FLIP_90_CW: {
			flip90Clockwise((int*) arr, row, col);
			puts(AFTER_MANIPULATION_MSG);
			printMatrix((int*) arr, row, col);
			break;
		}
		case Q1_SWITCH_FLIP_90_CCW: {
			flip90Cclockwise((int*) arr, row, col);
			puts(AFTER_MANIPULATION_MSG);
			printMatrix((int*) arr, row, col);
			break;
		}
		case Q1_SWITCH_FLIP_HORIZONTAL: {
			flipHorizontal((int*) arr, row, col);
			puts(AFTER_MANIPULATION_MSG);
			printMatrix((int*) arr, row, col);
			break;
		}
		case Q1_SWITCH_FLIP_VERTICAL: {
			flipVertical((int*) arr, row, col);
			puts(AFTER_MANIPULATION_MSG);
			printMatrix((int*) arr, row, col);
			break;

		}
		case Q1_SWITCH_QUIT: {
			puts("Picture manipulation completed\n");
			again = 0;
			break;
		}
		default: {
			printf("Invalid input\n");
		}
		}
	}
}
