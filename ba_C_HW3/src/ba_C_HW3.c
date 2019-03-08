/*
 ============================================================================
 Name        : ba_C_HW3.c
 Author      : Itai
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "city.h"

typedef enum {
	EXIT,READ_CITY,SHOW_CITY,SHOW_GARDEN,WRITE_CITY,ADD_GARDEN,ADD_CHILD,CHILD_BIRTHDAY,COUNT_GRADUATE
}MainSelect;

#define menuMsg "\n==========================\nSelect:\n\n1. Read City information from file.\n2. Show all Kindergartens.\n3. Show a specific Kindergarten.\n4. Save City information to file.\n5. Add a Kindergarten.\n6. Add a Child.\n7. Birthday to a Child.\n8. Count Hova childres.\n0. Exit."

int menu() {
	puts(menuMsg);

	int ans;
	scanf("%d", &ans);
	while (getchar() != '\n')
		;     // will consume the charters
	while (ans < 0 || ans > 8) { //menu violation
		printf(menuMsg);
		scanf("%d", &ans);
		while (getchar() != '\n')
			;     // will consume the charters
	}

	return ans;
}

int main() {
	City utz = { NULL, 0 };
	int uReq;

	//first time read
	readCity(&utz);
	do {
		uReq = menu();
		switch (uReq) {
		case READ_CITY://1
			ReleaseCity(&utz);
			readCity(&utz);
			break;

		case SHOW_CITY://2
			printCity(&utz);
			break;

		case SHOW_GARDEN://3
			showSpecificGardenInCity(&utz);
			break;

		case WRITE_CITY://4
			saveCityToFile(&utz);
			break;

		case ADD_GARDEN://5
			cityAddGarden(&utz);
			break;

		case ADD_CHILD://6
			addChildToSpecificGardenInCity(&utz);
			break;

		case CHILD_BIRTHDAY://7
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE://8
			printf("There are %d children going to school next year\n",countChova(&utz));
			break;

		}
	} while (uReq != EXIT);


	ReleaseCity(&utz); //free all allocations

	puts("Bye Bye");

	return 1;
}
