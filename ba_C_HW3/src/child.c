/* ba_C_HW3.c
 * child.c
 *
 *  Created on: Dec 29, 2018
 *      Author: Itai
 */

#ifndef CHILD_C_
#define CHILD_C_

#include "child.h"

void printChild(Child* child){
	printf("Id:%-4d Age:%d\n",child->id,child->age);
}

void saveChildToFile(FILE* file , Child* child){
	fprintf(file,"%d %d\n",child->id,child->age);
}
void readChildFromFile(FILE* file , Child* child){
	fscanf(file, "%d", &child->id);
	fscanf(file, "%d", &child->age);
}

void readChildFromUser(Child* child){
	puts("\nID No.:");
	scanf("%d", &child->id);
	puts("Age:");
	scanf("%d", &child->age);
}


#endif /* CHILD_C_ */
