#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q1.h"

void Q1() {
	Company theCompany = { 0 };
	int groupsCount, count, hour;

	//This function is given!!!
	Group** groupArr = createGroupsFromFile(GROUP_FILE_NAME, &groupsCount);
	if (!groupArr)
		return;

	//Q1_A
	if (!createCompanyDrives(&theCompany, groupArr, groupsCount))
		return;

	//Q1_B
	printf("\n-----------------\n");
	printf("Looking for Cleaners\n");
	findGroupByName(groupArr, groupsCount, "Cleaners");
	printf("Looking for Drivers\n");
	findGroupByName(groupArr, groupsCount, "EarlySecurety");

	//Q1_C
	hour = 10;
	count = getTotalPersonsInHour(&theCompany, hour);
	printf("There are %d persons who want a drive in %d\n", count, hour);

	//Q1_D
	free(groupArr);
	freeCompany(&theCompany);

}

int findDriveByHour(int hour, Company* pCompany) {
	for (int i = 0; i < pCompany->driveCount; i++) {
		if (pCompany->drivesArr[i]->hour == hour)
			return i;
	}
	return -1;
}

int	putGroupInDrives(Group* pGroup, Company* pCompany){
	int i = findDriveByHour(pGroup->hour,pCompany);
	if(i<0){//add new Drive
		i=pCompany->driveCount;

		pCompany->drivesArr = (Drive**)realloc(pCompany->drivesArr,sizeof(Drive*)*(i+1));
		if(!checkAllocation(pCompany->drivesArr))return 0;

		pCompany->drivesArr[i] = (Drive*)malloc(sizeof(Drive));
		if(!pCompany->drivesArr[i])return 0;

		pCompany->drivesArr[i]->hour=pGroup->hour;
		pCompany->drivesArr[i]->groupArr=NULL;
		pCompany->drivesArr[i]->groupCount=0;

		(pCompany->driveCount)++;
	}

	/* add Group to Drive */
	Drive* drive = pCompany->drivesArr[i];
	int groupCount = drive->groupCount;

	drive->groupArr = (Group**)realloc(drive->groupArr,sizeof(Group*)*(groupCount+1));
	if(!checkAllocation(drive->groupArr))return 0;

	drive->groupArr[groupCount] = pGroup;
	drive->groupCount++;

	return 1;
}

int getTotalPersonsInHour(Company* pCompany, int hour) {
	int i = findDriveByHour(hour, pCompany);
	int sum = 0;
	if (i >= 0) {
		Drive* drive = pCompany->drivesArr[i];
		for (int j = 0; j < drive->groupCount; j++)
			sum += drive->groupArr[j]->personCount;
	}
	return sum;
}

void findGroupByName(Group** groupArr, int groupsCount, const char* name) {

	Group** hGroup = NULL;
	Group group = { 0 };
	strcpy(group.name, name);
	Group* pGroup = &group;

	qsort(groupArr, groupsCount, sizeof(Group*), compareGroupByName);
	hGroup = (Group**) bsearch(&pGroup, groupArr, groupsCount, sizeof(Group*),
			compareGroupByName);

	if (!hGroup)
		printf("Group %s not found\n", name);
	else
		printGroup(*hGroup);

}
int compareGroupByName(const void* e1, const void* e2) {
	Group* pG1 = *(Group**) e1;
	Group* pG2 = *(Group**) e2;
	return strcmp(pG1->name, pG2->name);
}

int createCompanyDrives(Company* pCompany, Group** groupArr, int groupsCount) {
	int i;
	for (i = 0; i < groupsCount; i++) {
		if (!putGroupInDrives(groupArr[i], pCompany))
			return 0;
	}
	return 1;
}

Group** createGroupsFromFile(const char* fileName, int* pCount) {
	FILE* fp;
	int i;
	int count;
	Group** pGroupsArr;
	fp = fopen(fileName, "r");
	if (!fp)
		return NULL;

	fscanf(fp, "%d", &count);
	pGroupsArr = (Group**) malloc(count * sizeof(Group*));
	if (!pGroupsArr)
		return NULL;

	for (i = 0; i < count; i++) {
		pGroupsArr[i] = (Group*) malloc(sizeof(Group));
		if (!pGroupsArr[i]) {
			fclose(fp);
			return NULL;
		}
		fscanf(fp, "%s %d %d", pGroupsArr[i]->name, &pGroupsArr[i]->hour,
				&pGroupsArr[i]->personCount);
	}
	*pCount = count;
	fclose(fp);
	return pGroupsArr;
}

void freeGroup(Group* group){
}
void freeDrive(Drive* drive) {
	for (int i = 0; i < drive->groupCount; i++) {
		freeGroup(drive->groupArr[i]);
		free(drive->groupArr[i]);
	}
	free(drive->groupArr);
}
void freeCompany(Company* pCompany) {
	for (int i = 0; i < pCompany->driveCount; i++) {
		freeDrive(pCompany->drivesArr[i]);
		free(pCompany->drivesArr[i]);
	}
	free(pCompany->drivesArr);
}

void printGroup(Group* pGroup) {
	printf("Name %s hour %d Persons %d\n", pGroup->name, pGroup->hour,
			pGroup->personCount);
}
int checkAllocation(const void* p) {
	if (!p) {
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}
