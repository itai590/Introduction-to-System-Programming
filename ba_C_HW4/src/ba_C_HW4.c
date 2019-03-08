/*
 ============================================================================
 Name        : ba_C_HW4.c
 Author      : Itai
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"

int main(int argc, char* argv[]) {
	int fileFormat;
	if (argc != 2)
		return -1;
	sscanf(argv[1], "%d", &fileFormat);
	printf("file mode:%s\n", fileTypeName[fileFormat]);

	City utz = { NULL, 0 };
	int uReq;

	//first time read
	readCity(&utz, fileFormat);
	do {
		uReq = menu();
		switch (uReq) {
		case READ_CITY:
			readCity(&utz, fileFormat);
			break;

		case SHOW_CITY:
			showCityGardens(&utz);
			break;

		case SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case WRITE_CITY:
			saveCity(&utz, fileFormat);
			break;

		case ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",
					countChova(&utz));
			break;

		case SORT_NAME:
			insertionSort(utz.pGardenList, utz.count, sizeof(Garden*),compareGardensByName_v2);
			break;

		case SORT_TYPE_CHILDREN_NUMBERS:
			insertionSort(utz.pGardenList, utz.count, sizeof(Garden*),compareGardensByTypeChildCounter_v2);
			break;

		case SORT_CHILDREN_IN_KINDERGARTEN:
			sortChildrenKindergarten(utz.pGardenList,  utz.count);
			break;

		case LINKED_LIST:
			kindergartensLinkedList(&utz, 0);
			break;
		}
	} while (uReq != EXIT);

	releaseCity(&utz); //free all allocations

	return EXIT_SUCCESS;
}

