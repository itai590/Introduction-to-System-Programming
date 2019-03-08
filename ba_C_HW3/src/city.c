/* ba_C_HW3.c
 * city.c
 *
 *  Created on: Dec 29, 2018
 *      Author: Itai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "city.h"
#include "kindergarten.h"

#define fileName "DataFile.txt"

int readCity(City* city) {

	FILE* file;

	file = fopen(fileName, "r");
	if (!file)
		return 0;

	fscanf(file, "%d", &city->kindergartenNum);
	if (city->kindergartenNum == 0) {
		fclose(file);
		return 0;
	}

	city->KindergartenArr = (Kindergarten**) malloc(
			city->kindergartenNum * sizeof(Kindergarten*));
	if (!city->KindergartenArr) {
		fclose(file);
		return 0;
	}
	for (int i = 0; i < city->kindergartenNum; i++) {
		city->KindergartenArr[i] = (Kindergarten*) malloc(sizeof(Kindergarten));
		if (!city->KindergartenArr[i]) {
			fclose(file);
			return 0;
		}
		if (!readKindergartenFromFile(file, city->KindergartenArr[i])) {
			fclose(file);
			return 0;
		}
	}

	fclose(file);
	return 1;
}

//option 2 in the menu
void printCity(City* city) {
	printf("\nNumber of kindergarten:%d", city->kindergartenNum);
	for (int i = 0; i < city->kindergartenNum; i++) {
		printf("\nKindergarten %d:\n", i + 1);
		printKindergarten(city->KindergartenArr[i]);
	}
}

int saveCityToFile(City* city) {

	FILE* file;
	file = fopen(fileName, "w");
	fprintf(file, "%d\n", city->kindergartenNum);
	for (int i = 0; i < city->kindergartenNum; i++) {
		saveKindergartenToFile(file, city->KindergartenArr[i]);
	}

	fclose(file);
	return 1;
}

void showSpecificGardenInCity(City* city) {
	puts("Give me the Kindergarten Name:");
	char gartenName[100];
	scanf("%s", gartenName);
	int i = isKindergartenInCity(city, gartenName);
	if (i > 0) {
		printKindergarten(city->KindergartenArr[i]);
		return;
	}
	puts("No such Kindergarten");
}

int isKindergartenInCity(City* city, char* gartenName) {
	for (int i = 0; i < city->kindergartenNum; i++) {
		if (strcmp(gartenName, city->KindergartenArr[i]->gartenName) == 0) {
			return i;
		}
	}
	return -1;
}

int addChildToSpecificGardenInCity(City* city) {
	puts("Give me the Kindergarten Name:");
	char gartenName[100];
	scanf("%s", gartenName);
	int i = isKindergartenInCity(city, gartenName);
	if (i < 0) {
		puts("no such Kindergarten");
		return 0; //fail
	}

	addChildToKindergarten(city->KindergartenArr[i]);

	return 1;
}

int cityAddGarden(City* city) {
	char gartenName[100];
	puts("Name:");
	scanf("%s", gartenName);
	while (isKindergartenInCity(city, gartenName) >= 0) {
		puts("This Kindergarten already in list");
		puts("Name:");
		scanf("%s", gartenName);
	}

	city->KindergartenArr = (Kindergarten**) realloc(city->KindergartenArr,
			((city->kindergartenNum) + 1) * sizeof(Kindergarten*));
	if (!city->KindergartenArr)
		return 0;

	city->KindergartenArr[city->kindergartenNum] = (Kindergarten*) malloc(
			sizeof(Kindergarten));
	if (!city->KindergartenArr[city->kindergartenNum])
		return 0;
	city->KindergartenArr[city->kindergartenNum]->gartenName = strdup(gartenName);
		if (!city->KindergartenArr[city->kindergartenNum])
		return 0; //fail


	readKindergartenFromUser(city->KindergartenArr[city->kindergartenNum]);

	city->kindergartenNum+=1;

	return 1;
}

void birthdayToChild(City* city) {
	puts("Give me the Kindergarten Name:");
	char gartenName[100];
	scanf("%s", gartenName);
	int i = isKindergartenInCity(city, gartenName);
	if (i < 0) {
		puts("no such Kindergarten");
		return; //fail
	}

	int id;
	puts("Enter child id");
	scanf("%d", &id);
	int j = isChildInGarden(id, city->KindergartenArr[i]);
	if (j < 0){
		puts("No such child");
		return;
	}
	city->KindergartenArr[i]->childArray[j]->age=city->KindergartenArr[i]->childArray[j]->age+1;
}
int countChova(City* city){

	int count = 0;
	for( int i =0;i<city->kindergartenNum;i++){
		if(city->KindergartenArr[i]->gartenType==Chova){
			count += city->KindergartenArr[i]->childNum;
		}
	}

	return count ;
}

void ReleaseCity(City* city){

		for (int i = 0; i < city->kindergartenNum; i++) {
			//freeKinndergarten(city->KindergartenArr[i]);
			free(city->KindergartenArr[i]);
		}
		free(city->KindergartenArr);
}






