/*
 * child.c
 *
 *  Created on: Jan 20, 2019
 *      Author: itai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"

unsigned char* compressedChild(const Child* child) {
	unsigned char* buffer = (unsigned char*) malloc(
	COMPRESSED_CHILD_SIZE * sizeof(unsigned char*));
	if (!buffer)
		return NULL;

	buffer[0] = child->id & 0xff;
	buffer[1] = (child->id >> 8) | (child->age << 5);

	return buffer;
}

void unCompressedChild(unsigned char* pBuffer, Child* child) {
	child->id = pBuffer[0] | (pBuffer[1] & 0x1f) << 8; //0001-1111
	child->age = pBuffer[1] >> 5; //pBuffer[1]&0xe000
}

/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild, int fileFormat) {
	//txt
	if (!fileFormat) {
		fscanf(fp, "%d", &pChild->id);
		fscanf(fp, "%d", &pChild->age);
	}
	//bin
	else if (fileFormat == 1) {
		unsigned char buffer[COMPRESSED_CHILD_SIZE];
		if (!readFromBinFile(fp, buffer, COMPRESSED_CHILD_SIZE)) {
			puts("error readChild");
			return;
		}
		unCompressedChild(buffer, pChild);
	} else
		puts("readChild fileFormat error 0 or 1 expected");
}

/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild) {
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}

/**************************************************/
/**************************************************/
/**************************************************/
void getChildFromUser(Child* pChild, int id) {
	int age;

	pChild->id = id;
	puts("\nAge:\t");
	scanf("%d", &age);
	while(age <1 || age>7){
		puts("\nAge 1-7:\t");
		scanf("%d", &age);
	}
	pChild->age = age;
}

/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp, const Child* pChild, int fileFormat) {

	if (fileFormat == 0) {
		fprintf(fp, "%d %d\n", pChild->id, pChild->age);
	} else if (fileFormat == 1) {
		unsigned char* buffer = compressedChild(pChild);
		if (!writeToBinFile(fp, buffer, COMPRESSED_CHILD_SIZE))
			puts("error writeChild");
	}
}

Child* findChildById(Child** pChildList, int count, int id) {
	Child tmp = { id, 0 };
	Child* pTmp = &tmp;

	qsort(pChildList, count, sizeof(Child*), compareChildsById_v2);
	return bsearch(&pTmp, pChildList, count, sizeof(Child*), compareChildsById_v2);
}

void birthday(Child* pChild) {
	pChild->age++;
}

int compareChildsById(const void* st1, const void* st2) {
	const Child* pc1 = (const Child*) st1;
	const Child* pc2 = (const Child*) st2;
	return pc1->id - pc2->id;
}
int compareChildsById_v2(const void* st1, const void* st2) {
	const Child* pc1 = *(Child**) st1;
	const Child* pc2 = *(Child**) st2;
	return pc1->id - pc2->id;
}

//void	releaseChild(Child* pChild)
//{
//	//nothing to release
//}

