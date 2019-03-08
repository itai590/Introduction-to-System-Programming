/* ba_C_HW3.c
 * kinderGarden.c
 *
 *  Created on: Dec 29, 2018
 *      Author: Itai
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kindergarten.h"

const char* gartenTypeTilte[NoOfTypes] = { "Chova", "Trom Chova",
		"Trom Trom Chova", };


void printKindergarten(Kindergarten* kindergarten) {
	printf("Name:%-12s Type:%-15s %d Children:\n", kindergarten->gartenName,
			gartenTypeTilte[kindergarten->gartenType], kindergarten->childNum);
	for (int i = 0; i < kindergarten->childNum; i++) {
		printChild(kindergarten->childArray[i]);
	}
}

void saveKindergartenToFile(FILE* file, Kindergarten* kindergarten) {
	fprintf(file, "%s  %d %d\n", kindergarten->gartenName,
			kindergarten->gartenType, kindergarten->childNum);

	for (int i = 0; i < kindergarten->childNum; i++) {
		saveChildToFile(file, kindergarten->childArray[i]);
	}
}

int setType(int type, Kindergarten* kindergarten) {
	if (type < 0 || type >= NoOfTypes) {
		puts(
				"invalid Kindergarten type enter valid one: 0-Hova, 1-Trom Hova, 2-Trom Trom Hova");
		return 0;
	}

	kindergarten->gartenType = (GartenType) type;
	return 1;
}

int readKindergartenFromFile(FILE* file, Kindergarten* kindergarten) {
	//allocation for: string (garten name), array (childArray array)

	char tmp[100];
	fscanf(file, "%s", tmp);
	int typeTmp;
	fscanf(file, "%d", &typeTmp);
	setType(typeTmp, kindergarten);

	fscanf(file, "%d", &kindergarten->childNum);

	kindergarten->childArray = (Child**) malloc(
			kindergarten->childNum * sizeof(Child*));

	if (!kindergarten->childArray)
		return 0;

	kindergarten->gartenName = strdup(tmp);
	if (!kindergarten->gartenName)
		return 0;

	for (int i = 0; i < kindergarten->childNum; i++) {
		kindergarten->childArray[i] = (Child*) malloc(sizeof(Child));
		readChildFromFile(file, kindergarten->childArray[i]);
	}

	return 1;
}

int readKindergartenFromUser(Kindergarten* kindergarten) {
	int typeTmp;
	puts(
			"Garden type:\nEnter 0 for Chova\nEnter 1 for Trom Chova\nEnter 2 for Trom Trom Chova");
	scanf("%d", &typeTmp);
	setType(typeTmp, kindergarten);

	puts("Enter children Details:\nChildren count:");
	scanf("%d", &kindergarten->childNum);

	kindergarten->childArray = (Child**) malloc((kindergarten->childNum)* sizeof(Child*));

	if (!kindergarten->childArray)
		return 0; //fail

	for (int i = 0; i < kindergarten->childNum; i++) {
		kindergarten->childArray[i] = (Child*) malloc(sizeof(Child));
		readChildFromUser(kindergarten->childArray[i]);
	}
	return 1; //success
}

int isChildInGarden(int id, Kindergarten* kindergarten) {
	for (int i = 0; i < kindergarten->childNum; i++) {
		if (id == kindergarten->childArray[i]->id)
			return i;
	}
	return -1;
}

int addChildToKindergarten(Kindergarten* kindergarten) {

	kindergarten->childArray = (Child**) realloc(kindergarten->childArray,
			((kindergarten->childNum) + 1) * sizeof(Child*));
	if (!kindergarten->childArray)
		return 0;
	kindergarten->childArray[kindergarten->childNum] = (Child*) malloc(
			sizeof(Child));
	if (!kindergarten->childArray[kindergarten->childNum])
		return 0;

	int id;
	int age;
	puts("\nID No.:");
	scanf("%d", &id);

	while (isChildInGarden(id, kindergarten) >= 0) {
		puts("This child is in the Kindergarten");
		puts("\nID No.:");
		scanf("%d", &id);
	}
	puts("Age:");
	scanf("%d", &age);


	kindergarten->childArray[kindergarten->childNum]->age = age;
	kindergarten->childArray[kindergarten->childNum]->id = id;

	(kindergarten->childNum)+=1;
	return 1;
}

void freeKinndergarten(Kindergarten* kindergarten) {

	for (int i = 0; i < kindergarten->childNum; i++) {
		free(kindergarten->childArray[i]);
	}

	free(kindergarten->gartenName);
	free(kindergarten->childArray);
	free(kindergarten);

}

