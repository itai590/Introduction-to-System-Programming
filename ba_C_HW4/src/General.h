#ifndef __PROTOTYPE__
#define __PROTOTYPE__

typedef enum {
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_NAME,
	SORT_TYPE_CHILDREN_NUMBERS,
	SORT_CHILDREN_IN_KINDERGARTEN,
	LINKED_LIST,
	NofOptions
} MenuOptions;

int menu();
char* getStrExactLength(char* inpStr);
int checkAllocation(const void* p);
int writeToBinFile(FILE* file, void* pBuffer, int size);
int readFromBinFile(FILE* file, void* pBuffer, int size);
void genericSwap(void* a, void* b, int typeSize);
void bubbleSort(void** arr, int size, int typeSize, int (*compare)(const void*, const void*));
void insertionSort(void* arr, int size, int typeSize, int (*compare)(const void*, const void*));
int compareInt(const void* st1, const void* st2);
int compareString(const void* st1, const void* st2);
void Variadic_Function(const char* str, ...);

//void insertionSort(void* arr, int size, int typeSize,int (*compare)(const void*, const void*));

#endif
