/* ba_C_HW3.c
 * kinderGarden.h
 *
 *  Created on: Dec 29, 2018
 *      Author: Itai
 */

#ifndef KINDERGARTEN_H_
#define KINDERGARTEN_H_

#include "child.h"


typedef enum{
	Chova, Trom_Chova,Trom_Trom_Chova,NoOfTypes
}GartenType;

typedef struct{
	char* gartenName;
	int childNum;
	Child** childArray;
	GartenType gartenType;

}Kindergarten;



void printKindergarten(Kindergarten* kindergarten) ;
void saveKindergartenToFile(FILE* file, Kindergarten* kindergarten) ;
int setType(int type, Kindergarten* kindergarten);
int readKindergartenFromFile(FILE* file, Kindergarten* kindergarten) ;
int readKindergartenFromUser(Kindergarten* kindergarten);
int isChildInGarden(int id,Kindergarten* kindergarten);
int addChildToKindergarten(Kindergarten* kindergarten);
void freeKinndergarten(Kindergarten* kindergarten);



#endif /* KINDERGARTEN_H_ */
