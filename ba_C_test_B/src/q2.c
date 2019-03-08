#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "q2.h"

void Q2() {

	char **matrix;
	char **maskA;
	char **maskB;

	// make allocations of all matrices and set values like in question 2
	if (allocateAndInitMatrices(&matrix, &maskA, &maskB) == FAILURE)
		return;

	// Q2.1
	// Use mask A to find a template
	if(findTemplateInMatrix(matrix, MATRIX_ROWS, MATRIX_COLS,maskA,MASK_A_ROWS, MASK_A_COLS,copmeratorA)==1)
		puts("A");
	else puts("nop A");

	// Use mask B to find a template
	if(findTemplateInMatrix(matrix, MATRIX_ROWS, MATRIX_COLS,maskB,MASK_B_ROWS, MASK_B_COLS,copmeratorB)==1)
		puts("B");
	else
		puts("nop B");

	// Q2.2
	// Find TWO different masks in one call
	findFewTemplatesInMatrix(matrix, MATRIX_ROWS,MATRIX_COLS,maskA,MASK_A_ROWS, MASK_A_COLS,copmeratorA,maskB,MASK_B_ROWS, MASK_B_COLS,copmeratorB,NULL);

}


/////////////////////////
// Utility functions
/////////////////////////

// Allocation and initialization like in Question 2
int allocateAndInitMatrices(char ***matrixM, char ***maskA, char ***maskB) {
	char M[6][4] = {{'A', 'S', 'R', 'W'},
					{'D', 'F', 'I', 'B'},
					{'A', 'F', 'K', 'M'},
					{'N', 'Z', 'Z', 'A'},
					{'E', 'F', 'L', 'F'},
					{'T', 'K', 'K', 'O'}};
	char A[2][2] = {{'I', 'B'},
					{'X', 'M'}};
	char B[4][2] = {{'X', 'A'},
					{'F', 'X'},
					{'E', 'A'},
					{'K', 'X'}};

	//Allocate matrices
	*matrixM = allocateMatrix(6, 4);
	*maskA = allocateMatrix(2, 2);
	*maskB = allocateMatrix(4, 2);
	if (*matrixM == NULL || *maskA == NULL || *maskB == NULL)
		return FAILURE;

	// Copy data
	copyArrayToMatrix(*matrixM, 6, 4, &M[0][0]);
	copyArrayToMatrix(*maskA, 2, 2, &A[0][0]);
	copyArrayToMatrix(*maskB, 4, 2, &B[0][0]);

	return SUCCESS;
}

// Allocates two dimensional array [rows][colomns]
char **allocateMatrix(int rows, int colomns) {
	int i;
	char **matrix;

	matrix = (char **) malloc(rows*sizeof(char *));
	if (matrix == NULL)
		return NULL;

	for (i = 0;   i < rows;   i++) {
		matrix[i] = (char *) malloc(colomns*sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}

	return matrix;
}

// Copies data from array to matrix
void copyArrayToMatrix(char **to, int row, int column, char *from) {
	int i, j;

	for (i = 0;    i < row;   i++)
		for (j = 0;    j < column;   j++) {
			to[i][j] = *from;
			from++;
	}
}

int findTemplateInMatrix(char** matrix, int rows,int columns,char** mask, int maskRows,int maskColumns,
		int(*comperator)(char** matrix,int startRow, int startColumn, char** mask)){

for(int i=0;i<=rows-maskRows;i++){
	for(int j=0;j<=columns-maskColumns;j++){
		if (comperator(matrix,i,j,mask)) return SUCCESS;
	}
}

return FAILURE;

}



int copmeratorA(char** matrix,int startRow, int startColumn, char** mask){
	if(mask[0][0]!=matrix[startRow][startColumn]) return FAILURE;
	if(mask[0][1]!=matrix[startRow][startColumn+1]) return FAILURE;
	if(mask[1][1]!=matrix[startRow+1][startColumn+1]) return FAILURE;

	return SUCCESS;
}
int copmeratorB(char** matrix,int startRow, int startColumn, char** mask){
	if(mask[0][1]!=matrix[startRow][startColumn+1]) return FAILURE;
	if(mask[1][0]!=matrix[startRow+1][startColumn]) return FAILURE;
	if(mask[2][0]!=matrix[startRow+2][startColumn]) return FAILURE;
	if(mask[3][0]!=matrix[startRow+3][startColumn]) return FAILURE;
	if(mask[2][1]!=matrix[startRow+2][startColumn+1]) return FAILURE;

	return SUCCESS;
}


void findFewTemplatesInMatrix(char** matrix, int rows,int columns,...)
{
	va_list list;
	va_start(list, columns);
	int i =1;
	char start = 's';

	char** mask =(char**) &start;
	int maskRows;
	int maskColumns;
	void* copmerator;

	while(1){
		mask = va_arg(list, char**);
		if (mask==NULL) break;
		maskRows = va_arg(list, int);
		maskColumns = va_arg(list, int);
		copmerator = va_arg(list, void*);

		if(findTemplateInMatrix(matrix, 6, 4,mask,maskRows, maskColumns,copmerator)==SUCCESS)
			printf("\nTemplate #%d - found",i);
		else
			printf("\nTemplate #%d - NOT found",i);

		i++;
	}

	va_end(list);

}


