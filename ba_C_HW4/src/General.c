#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "General.h"

const char* optionStr[NofOptions] = { "Exit", "Read City information from file",
		"Show all Kindergartens", "Show a specific Kindergarten",
		"Save City information to file", "Add a Kindergarten", "Add a Child",
		"Birthday to a Child", "Count Hova childres",
		"Sort Kindergartens by name",
		"Sort Kindergartens by type and children numbers",
		"Sort children in a Kindergarten", "Kindergartens in Linked list" };

/**************************************************/
/**************************************************/
/**************************************************/
int menu() {
	int option, i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for (i = 0; i < NofOptions; i++)
		printf("\n\t%d. %s.", i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr) {
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array
	theStr = (char*) malloc(len * sizeof(char));
	//Copy the string to the right location in the array
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p) {
	if (!p) {
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

int writeToBinFile(FILE* file, void* pBuffer, int size) {
	if (fwrite(pBuffer, sizeof(char), size, file) != size)
		return 0;
	return 1;
}

int readFromBinFile(FILE* file, void* pBuffer, int size) {
	if (fread(pBuffer, sizeof(unsigned char), size, file) != size)
		return 0;
	return 1;
}

void genericSwap(void* a, void* b, int typeSize) {
	char *tmp = (char*) malloc(typeSize);
	memcpy(tmp, a, typeSize);
	memcpy(a, b, typeSize);
	memcpy(b, tmp, typeSize);
	free(tmp);
}

void bubbleSort(void** arr, int size, int typeSize,
		int (*compare)(const void*, const void*)) {
	int i, j;

	for (i = size - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (compare(arr[j], arr[j + 1]) > 0)
				genericSwap((char*) &arr[j], (char*) &arr[j + 1], typeSize);
	//genericSwap((char*)arr + j * typeSize,(char*)arr + (j + 1) * typeSize, typeSize);
}

//void insertionSort(int* arr, int size)
//{
//	int i,j,key;
//	for (i = 1; i < size; i++)
//	{
//		key = arr[i];
//		for (j = i - 1; j >= 0 && (arr[j] > key); j--)
//			arr[j+1] = arr[j];
//		arr[j + 1] = key;
//	}
//}

/* my insertionSort - doesn't work - to fix later*/
void insertionSort(void* arr, int size, int typeSize,
		int (*compare)(const void*, const void*)) {
	int i, j;

	char* key = (char*) malloc(typeSize);
	char *pList = (char*) arr;

	for (i = 1; i < size; i++) {

		memcpy((char*) key, arr + i * typeSize, typeSize);
		for (j = i - 1; j >= 0 && (compare(pList + j * typeSize, key) > 0); j--)
			memcpy(pList + (j + 1) * typeSize, arr + j * typeSize, typeSize);
		memcpy(pList + (j + 1) * typeSize, key, typeSize);
	}
	free(key);
}


void Variadic_Function(const char* str, ...) {
	int index;
	va_list list;
	va_start(list, str);
	while (str != NULL) {
		index = va_arg(list, int);
		printf("%s %d", str, index);
		str = va_arg(list, char*);
		printf("\n");
	}

	va_end(list);
}

