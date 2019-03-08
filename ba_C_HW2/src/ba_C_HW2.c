/*
 ============================================================================
 Name        : ba_C_HW2.c
 Author      : Itai
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define  NEW_STRING 		1
#define  CURRENT_STRING 	2
#define  COUNT_WORDS 		3
#define  LONGEST_WORD 		4
#define  REVERT_WORD 		5
#define  CHECK_ERASE_CHARS 	6
#define  CHECK_PALINDROME 	7
#define  EXIT 				-1
#define  MAX_LEN	      	100

typedef enum {
	FALSE, TRUE
} boolean;

void printMenu() {
	printf("\n\n");
	printf("Please choose one of the following options\n");
	printf("%d - Enter new string\n", NEW_STRING);
	printf("%d - Print current string\n", CURRENT_STRING);
	printf("%d - Count words in string\n", COUNT_WORDS);
	printf("%d - Print longest word in string CAPITALIZED\n", LONGEST_WORD);
	printf("%d - Revert each word in string\n", REVERT_WORD);
	printf("%d - Check eraseCharsFromStr\n", CHECK_ERASE_CHARS);
	printf("%d - Check palindrome\n", CHECK_PALINDROME);
	printf("%d - Exit\n", EXIT);
}
/* 1 */
void initString(char* str, int max_length) {
	printf("please enter a new string:\n");
	fgets(str, max_length, stdin);
	str[strcspn(str, "\n")] = '\0';

	/**
	 * replace '\n' by '\0' at the end of the string
	 *
	 * str[strlen(str) - 1] = '\0';
	 *
	 * 			OR
	 *
	 * str[strcspn(str, "\n")] = '\0';
	 *
	 */

	/**
	 * strcspn VS strspn
	 *
	 * strcspn(str, "\n");
	 * returns the number of characters in the initial segment of string str1 which are not in the string str2.
	 *
	 *
	 * strspn(str, "\n");
	 * returns the number of characters in the initial segment of str1 which consist only of characters from str2
	 */
}
/* 2 */
void printString(const char* str) {
	printf("%s\n", str);
}

boolean isSpecialTav(char c) {
	if (c == ' ' || c == ',' || c == ':' || c == '?' || c == '-')
		return TRUE;
	return FALSE;
}

/* 3 */
int countWords(const char* str) {
	int count = 0;
	int size = strlen(str);

	/* handle the case which the string starts with a word */
	if (!isSpecialTav(*str))
		count++;

	for (int i = 0; i < size - 1; i++) {
		if (isSpecialTav(*str) && !isSpecialTav(*(str + 1))) {
			count++;
		}
		str++;
	}
	return count;
}

/* 4 */
void longestInCaptital(char* str) {
	int maxChars = 0;
	int charCount = 0;
	char* ptr;
	//char* keepPtr;

	while (*str) {
		//ptr = str;

		while (!isSpecialTav(*str) && (*str)) {

			charCount++;
			str++;
		}

		if (charCount > maxChars) {
			//keepPtr = ptr;
			ptr = str - charCount;
			maxChars = charCount;
		}

		if (isSpecialTav(*str))
			charCount = 0;
		str++;
	}

	for (int i = 0; i < maxChars; i++) {
		*ptr = toupper(*ptr);
		ptr++;

		//*keepPtr = toupper(*keepPtr);
		//keepPtr++;
	}
}

void swap(char* start, char* end) {
	int temp = *start;
	*start = *end;
	*end = temp;
}

/* 5 */
void revertWords(char* str) {
	char* ptr = str;
	int charCount = 0;

	while (*str) {

		if (isSpecialTav(*str)) {
			*str = '*';
			str++;

		} else {
			ptr = str;

			while (!isSpecialTav(*str) && (*str)) {
				charCount++;
				str++;
			}
			while (ptr < str - 1) {
				swap(ptr, str - 1);
				str--;
				ptr++;
			}
			//re-init
			str = str + charCount / 2;
			charCount = 0;
		}
	}
}

/* 6 */
void eraseCharsFromString(char *str, const char *symbols) {

	char symbolsCopy[strlen(symbols) + 1];
	strcpy(symbolsCopy, symbols);

	char strCopy[strlen(str) + 1];
	strcpy(strCopy, str);

	char ans[strlen(str)];
	ans[0] = '\0';

	char* token = strtok(strCopy, symbolsCopy);
	while (token) {
		strcat(ans, token);
		token = strtok(NULL, symbolsCopy);
	}
	strcpy(str, ans);
	str[strlen(str) + 1] = '\0';
}

void ramoveNonAlphaChars(const char* from, char* to) {
	char* trr = to;
	char* size = trr + strlen(from);
	while (trr < size) {
		*trr = '\0';
		trr++;
	}
	while (*from) {
		if (isalpha(*from)) {
			*to = *from;
			to++;
		}
		from++;
	}
}

/* 7 */
int isPalindrome(const char *str) {
	char tmp[strlen(str)];
	ramoveNonAlphaChars(str, tmp);

	char* start = tmp;
	char* end = tmp + strlen(tmp) - 1;

	while (start < end) {
		if (tolower(*start) != tolower(*end))
			return 0;
		start++;
		end--;
	}
	return 1;
}


void performChoice(int option, char *str) {

	switch (option) {
	case NEW_STRING:
		//1
		initString(str, MAX_LEN);
		break;

	case CURRENT_STRING:
		//2
		printString(str);
		break;

	case COUNT_WORDS: {
		//3
		int count = countWords(str);
		printf("There are %d words in string\n", count);
		break;
	}
	case LONGEST_WORD:
		//4
		longestInCaptital(str);
		printf("String after longest capital: %s\n", str);
		break;

	case REVERT_WORD:
		//5
		revertWords(str);
		printf("String after revert: %s\n", str);
		break;

	case CHECK_ERASE_CHARS:
		//6
		//eraseCharsFromString(str, ":, ?!-;");
		eraseCharsFromString(str, "E'!");
		printf("String after erase: %s\n", str);
		break;

	case CHECK_PALINDROME:
		//7
		if (isPalindrome(str))
			printf("String %s is palindrome\n", str);
		else
			printf("String %s is NOT palindrome\n", str);
		break;

	case EXIT:
		printf("Bye bye\n");
		break;

	default:
		printf("Wrong option\n");
		break;
	}

}

int main() {
	int option;
	char str[MAX_LEN] = "\0";

	do {
		printMenu();
		scanf("%d", &option);
		getchar();
		performChoice(option, str);

	} while (option != EXIT);

	return EXIT_SUCCESS;
}
