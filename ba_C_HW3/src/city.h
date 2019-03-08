/* ba_C_HW3.c
 * city.h
 *
 *  Created on: Dec 29, 2018
 *      Author: Itai
 */

#ifndef CITY_H_
#define CITY_H_

#include "kindergarten.h"

typedef struct {
	Kindergarten** KindergartenArr;
	int kindergartenNum;
} City;

int readCity(City* city);
void printCity(City* city); //option 2 in the menu
int saveCityToFile(City* city); //option 4 in the menu
void showSpecificGardenInCity(City* city);
int cityAddGarden(City* city); //option 5 in the menu
int isKindergartenInCity(City* city, char* gartenName);
int addChildToSpecificGardenInCity(City* city);
int cityAddGarden(City* city);
void birthdayToChild(City* city);
int countChova(City* city);
void ReleaseCity(City* city);


#endif /* CITY_H_ */
