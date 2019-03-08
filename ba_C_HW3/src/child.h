/* ba_C_HW3.c
 * child.h
 *
 *  Created on: Dec 29, 2018
 *      Author: Itai
 */

#ifndef CHILD_H_
#define CHILD_H_

#include <stdio.h>

typedef struct{
	int id;
	int age;
}Child;



void printChild(Child* child);

void saveChildToFile(FILE* file , Child* child);
void readChildFromFile(FILE* file , Child* child);
void readChildFromUser(Child* child);
void freeChild(Child* child);



#endif /* CHILD_H_ */
