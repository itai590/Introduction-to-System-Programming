#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"
#include "list.h"

typedef enum {
	txt, bin,noOfFileTypes
} fileType;
const char* fileTypeName[noOfFileTypes] ;
char* DATA_FILE[noOfFileTypes] ;


typedef struct{
	Garden** pGardenList;
	int count;
}City;


void 	readCity(City* pCity,int fileFormat);
void	showCityGardens(City* pCity);
void	showSpecificGardenInCity(City* pCity);
void	saveCity(City* pCity,int fileFormat);
void	cityAddGarden(City* pCity);
void	addChildToSpecificGardenInCity(City* pCity);
void 	displayKindergartensFromList(LIST* list);
void 	kindergartensLinkedList(City* city, GardenType type);
void	birthdayToChild(City* pCity);
int		countChova(City* pCity);
void	releaseCity(City* pCity);


#endif
