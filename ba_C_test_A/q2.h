#ifndef Q2_H_
#define Q2_H_

typedef struct {
	int row;
	int sum;
} Array;

// Prints two dimensional matrix by rows
void 	printMatrix(int *matrix, int rows, int columns);
void 	printArrEzer(Array** arr, int rows);
void 	sortMatrixRowsByBits(int *matrix, int rows, int columns);
// Sort a matrix using "sum of elements in row" criteria
void 	sortMatrixRowsBySum(int *matrix, int rows, int columns);
// Sort a matrix using "number of non zero bits in row" criteria
void 	sortMatrix(int *matrix, int rows, int columns, int func(int*, int));
int 	sumRow(int *matrix, int columns);
int 	bitsRow(int *matrix, int columns);
void 	copyArray(int *to, int *from, int size);
int 	Q2(void);
int 	calcNumberOfOnes(int n);
int 	compareBySum(const void* arr1, const void* arr2);

#endif /* Q2_H_ */
