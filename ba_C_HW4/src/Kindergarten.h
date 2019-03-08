#ifndef __KINDERGARTEN__
#define __KINDERGARTEN__

#include "Child.h"

#define COMPRESSED_GARDEN_SIZE 1 //bytes

typedef enum {
	Chova, TromChova, TromTromChova, NofTypes
} GardenType;

const char* GardenTypeName[NofTypes];

typedef struct {
	char* name;
	GardenType type;
	Child** childPtrArr;
	int childCount;
} Garden;

unsigned char* compressedGarden(const Garden* garden);

void unCompressedGarden(unsigned char* pBuffer, Garden* garden);

Garden** readAllGardensFromFile(char* fileName, int* pGardenCount,
		int fileFormat);

void readGarden(FILE* fp, Garden* pGarden, int fileFormat);

void showAllGardens(Garden** pGardenList, int count);

void showGarden(const Garden* pGarden);

void writeGardensToFile(Garden** pGardenList, int gardenCount, char* fileName,
		int fileForamt);

void writeGarden(FILE* fp, const Garden* pGarden, int fileFormat);

void addChildToGarden(Garden** pGardenList, int gardenCount);

Garden** addGarden(Garden** pGardenList, int* pGardenCount);

void showGardenMenu(Garden** pGardenList, int count);

Garden* getGardenAskForName(Garden** pGardenList, int count);

Garden* findGardenByName(Garden** pGardenList, int count, const char* name);

Child* getChildAskForId(Garden* pGarden);

void getGardenFromUser(Garden* pGarden, Garden** pGardenList, int count);

void getChildCheckIdFromUser(Child* pChild, const Garden* pGarden);

void handleBirthdayToChild(Garden** pGardenList, int count);

GardenType getTypeOption();

void sortChildrenKindergarten(Garden** pGardenList, int gardenCount);

int compareGardensByName(const void* st1, const void* st2);
int	compareGardensByName_v2(const void* e1, const void* e2);

int compareGardensByTypeChildCounter(const void* st1, const void* st2);
int compareGardensByTypeChildCounter_v2(const void* st1, const void* st2);

void release(Garden** pGardenList, int count);

#endif
