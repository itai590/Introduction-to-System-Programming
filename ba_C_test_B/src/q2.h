#ifndef Q2_H_
#define Q2_H_

#include "q2.h"

#define SUCCESS 1
#define FAILURE 0

#define MATRIX_ROWS 6
#define MATRIX_COLS 4

#define MASK_A_ROWS 2
#define MASK_A_COLS 2
#define MASK_B_ROWS 4
#define MASK_B_COLS 2

void Q2();


// Make allocations of all matrices and set values like in question 2
int allocateAndInitMatrices(char ***matrixM, char ***maskA, char ***maskB);

// Allocates two dimensional array [rows][colomns]
char **allocateMatrix(int rows, int colomns);

// Copies data from array to matrix
void copyArrayToMatrix(char **to, int row, int column, char *from);

int findTemplateInMatrix(char** matrix, int rows,int columns,char** mask, int maskRows,int maskColumns,int(*comperator)(char** matrix,int startRow, int startColumn, char** mask));

int copmeratorA(char** matrix,int startRow, int startColumn, char** mask);
int copmeratorB(char** matrix,int startRow, int startColumn, char** mask);


void findFewTemplatesInMatrix(char** matrix, int rows,int columns,...);




#endif /* Q2_H_ */
