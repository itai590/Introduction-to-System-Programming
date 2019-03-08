#pragma once
#include <stdio.h>

#define GROUP_FILE_NAME "groups.txt"
#define MAX_LEN 15

typedef struct
{
	char	name[MAX_LEN];
	int		hour;
	int		personCount;
}Group;

typedef struct
{
	int		hour;
	int		groupCount;
	Group** groupArr;
}Drive;

typedef struct
{
	int driveCount;
	Drive** drivesArr;
}Company;

void	Q1();
int 	findDriveByHour(int hour,Company* pCompany);
int 	compareGroupByName(const void* e1, const void* e2);
Group** createGroupsFromFile(const char* fileName, int* pCount);

int		createCompanyDrives(Company* pCompany, Group**  groupArr, int groupsCount);
int		putGroupInDrives(Group* pGroup, Company* pCompany);
int		getTotalPersonsInHour(Company* pCompany, int hour);

void	findGroupByName(Group**  groupArr, int groupsCount, const char* name);

void	printGroup(Group* pGroup);

int 	checkAllocation(const void* p);

void freeGroup(Group* group);
void freeDrive(Drive* drive);
void freeCompany(Company* pCompany);


