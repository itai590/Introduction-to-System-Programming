#include <stdio.h>
#include <stdlib.h>
#include "City.h"
#include "Kindergarten.h"
#include "General.h"


const char* fileTypeName[noOfFileTypes] = { "txt", "bin" };
char* DATA_FILE[noOfFileTypes] = { "DataFile.txt", "DataFile.bin" };

void readCity(City* pCity, int fileFormat) {
	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}
	pCity->pGardenList = readAllGardensFromFile(DATA_FILE[fileFormat],
			&pCity->count, fileFormat);

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void showCityGardens(City* pCity) {

	showAllGardens(pCity->pGardenList, pCity->count);

	Variadic_Function(pCity->pGardenList[0]->name,
			pCity->pGardenList[0]->childCount, pCity->pGardenList[1]->name,
			pCity->pGardenList[1]->childCount, pCity->pGardenList[2]->name,
			pCity->pGardenList[2]->childCount, NULL);
}

void showSpecificGardenInCity(City* pCity) {
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity, int fileFormat) {
	writeGardensToFile(pCity->pGardenList, pCity->count, DATA_FILE[fileFormat],
			fileFormat);
}

void cityAddGarden(City* pCity) {
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL) //Allocation error
		printf("Error adding kindergarten\n");
}

void addChildToSpecificGardenInCity(City* pCity) {
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void birthdayToChild(City* pCity) {
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int countChova(City* pCity) {
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++) {
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

LIST* createLinkedListForKindergartenType(City* city, GardenType type) {

	LIST* list = (LIST*)malloc(sizeof(LIST));
	L_init(list);
	NODE* pointer = &list->head;
	for (int i = 0; i < city->count; i++) {
		if (city->pGardenList[i]->type == type) {
			pointer = L_insert(pointer, city->pGardenList[i]);
		}
	}

	return list;
}

void displayKindergartensFromList(LIST* list) {

	NODE *tmp;
	int c = 1;
	if (!list)
		return;

	for (tmp = list->head.next; tmp != NULL; tmp = tmp->next, c++){
		printf("\nKindergarten %d:\n",c);
		showGarden(tmp->key);
		printf("\n");
	}
}


void kindergartensLinkedList(City* city, GardenType type){
	LIST* l = createLinkedListForKindergartenType(city, type);
	displayKindergartensFromList(l);
}


void releaseCity(City* pCity) {
	release(pCity->pGardenList, pCity->count);
}
