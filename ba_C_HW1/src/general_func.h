/*
 * C_HW1
 * general_func.h
 *
 *  Created on: Nov 13, 2018
 *      Author: itai
 */

#ifndef GENERAL_FUNC_H_
#define GENERAL_FUNC_H_

#define MIN_RANDOM 1
#define MAX_RANDOM 100


int getRandom(int min, int max);
void initRandomMatrix(int* matrix, int r, int c);
void printMatrix(int* matrix, int r, int c);
void swap(int* a1, int* a2);
void transposeMatrix(int* arr, int row, int col);

#endif /* GENERAL_FUNC_H_ */
