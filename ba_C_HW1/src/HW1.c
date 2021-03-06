/*
 * HW1
 ============================================================================
 Name        : HW1.c
 Author      : Itai
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "general_func.h"
#include "Q1.h"
#include "Q2.h"

#define MAIN_SWITCH_PICTURE_MANIPULATION 'p'
#define MAIN_SWITCH_NUMBER_GAME 'n'
#define MAIN_SWITCH_QUIT 'e'

#define WELCOME_MSG "Please choose one of the following options:\nP/p -Picture Manipulation\nN/n -Number Game\nE/e -Quit\n"

void start() {

	char ans;
	int again = 1;

	while (again) {

		printf(WELCOME_MSG);
		scanf("%c", &ans);
		while (isspace(ans)) {
			scanf("%c", &ans);
		}
		ans = tolower(ans); //case insensitive

		switch (ans) {
		case MAIN_SWITCH_PICTURE_MANIPULATION: {
			PictureManipulation(Q1_SIZE, Q1_SIZE);
			break;
		}
		case MAIN_SWITCH_NUMBER_GAME: {
			numberGame(N, M);
			break;
		}
		case MAIN_SWITCH_QUIT: {
			puts("Bye Bye");
			again = 0;
			break;
		}
		default: {
			printf("\nInvalid input\n");
		}
		}
	}
}

int main(void) {

	start();

	return EXIT_SUCCESS;
}
