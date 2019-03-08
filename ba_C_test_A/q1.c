#include <string.h>
#include <stdlib.h>
#include "q1.h"

/* This is the data in the file
 11 customers
 David Adult France
 Jon Child France
 Helena Baby Germany
 Lidia Adult Germany
 Judith Soldier France
 Zeus Adult Italy
 Josef Child Italy
 Michel Baby France
 Tal Adult Italy
 Guy Soldier France
 Moshe Child Germany
 */

/*
 Correct output is:
 In country France the income is: 3100.00
 In country Germany the income is: 1500.00
 In country Italy the income is: 2500.00
 */

const char* CustomerTypeName[] = { "Adult", "Child", "Soldier" };

void Q1() {
	printf("CustomerType: {0-Adult, 1-Child, 2-Baby, 3-Soldier}\n");
	Company theCompany = { NULL, 0 };

	if (!fillCompanySurvey(&theCompany)) {
		printf("Error filling the survey\n");
		return;
	}

	printTotalIncomePerContry(&theCompany);
	releaseCompany(&theCompany);
}

int readCustomerFromFile(FILE* fp, Customer* pCust) {

	int nameSize;
	int countrySize;

	char sTmp[100];

	fread(&nameSize, sizeof(int), 1, fp);
	fread(sTmp, sizeof(char), nameSize, fp);
	pCust->name = strdup(sTmp);
	if (!pCust->name)
		return 0;

	fread(&pCust->type, sizeof(int), 1, fp);

	fread(&countrySize, sizeof(int), 1, fp);
	fread(sTmp, sizeof(char), countrySize, fp);
	pCust->country = strdup(sTmp);
	if (!pCust->country)
		return 0;

	/* print file to console check*/
	printf("%s %d %s\n",pCust->name,pCust->type,pCust->country);

	return 1;
}

int addCustomerToCompany_new_best(Company* pCompany, Customer* pCust) {
	int i = isCountryInCopmany(pCompany, pCust->country);

	/* add new trip */
	if (i < 0) {
		i = pCompany->tripsCount;

		// reallocate extra trip pointer to Trip in tripsArr
		pCompany->tripsArr = (Trip**) realloc(pCompany->tripsArr,
				sizeof(Trip*) * (i + 1));
		if (!checkAllocation(pCompany->tripsArr))
			return 0;
		// reallocate extra trip in tripsArr
		pCompany->tripsArr[i] = (Trip*) malloc(sizeof(Trip));
		if (!checkAllocation(pCompany->tripsArr[i]))
			return 0;

		//init new customer
		pCompany->tripsArr[i]->country = strdup(pCust->country);
		if (!checkAllocation(pCompany->tripsArr[i]->country))
			return 0;
		pCompany->tripsArr[i]->coustomersCount = 0;
		pCompany->tripsArr[i]->customersArr = NULL;

		//increase tripsCount
		(pCompany->tripsCount)++;
	}
	Trip* trip = pCompany->tripsArr[i];

	/* add the customer to an existing trip */

	int customersCount = trip->coustomersCount;

	//reallocate new Customer
	trip->customersArr = (Customer**) realloc(trip->customersArr,
			sizeof(Customer*) * (customersCount + 1));
	if (!checkAllocation(trip->customersArr))
		return 0;

	trip->customersArr[customersCount] = (Customer*) malloc(sizeof(Customer*));

	//copy country
	trip->customersArr[customersCount]->country = strdup(pCust->country);
	if (!checkAllocation(trip->customersArr[customersCount]->country))
		return 0;

	//copy name
	trip->customersArr[customersCount]->name = strdup(pCust->name);
	if (!checkAllocation(trip->customersArr[customersCount]->name))
		return 0;

	//copy type
	trip->customersArr[customersCount]->type = pCust->type;

	//increase coustomersCount
	(trip->coustomersCount)++;

	return 1;
}

int addCustomerToCompany_original_improve(Company* pCompany, Customer* pCust) {

	int i = isCountryInCopmany(pCompany, pCust->country);

	/* add new trip */
	if (i < 0) {
		i = pCompany->tripsCount;

		//allocate
		pCompany->tripsArr = (Trip**) realloc(pCompany->tripsArr,
				sizeof(Trip*) * (pCompany->tripsCount + 1));
		pCompany->tripsArr[pCompany->tripsCount] = (Trip*) malloc(sizeof(Trip));
		if (!pCompany->tripsArr[pCompany->tripsCount]) {
			puts("memory error addCustomerToCompany new trip allocation");
			return 0;
		}

		//set trip country
		pCompany->tripsArr[pCompany->tripsCount]->country = strdup(
				pCust->country);
		if (!pCompany->tripsArr[pCompany->tripsCount]->country) {
			puts("error add addCustomerToCompany strcpy(trip country");
			return 0;
		}

		pCompany->tripsArr[pCompany->tripsCount]->customersArr = NULL;
		pCompany->tripsArr[pCompany->tripsCount]->coustomersCount = 0;
		pCompany->tripsCount++;

	}

	/* add the customer to the trip arr in index */

	//allocate
	pCompany->tripsArr[i]->customersArr = (Customer**) realloc(
			pCompany->tripsArr[i]->customersArr,
			sizeof(Customer*) * (pCompany->tripsArr[i]->coustomersCount + 1));
	if (!pCompany->tripsArr[i]->customersArr) {
		puts("memory error addCustomerToCompany 1");
		return 0;
	}
	pCompany->tripsArr[i]->customersArr[(pCompany->tripsArr[i]->coustomersCount)] =
			(Customer*) malloc(sizeof(Customer));
	if (!pCompany->tripsArr[i]->customersArr[(pCompany->tripsArr[i]->coustomersCount)]) {
		puts("memory error addCustomerToCompany 2");
		return 0;
	}

	//copy country
	pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->country =
			strdup(pCust->country);
	if (!(pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->country)) {
		puts("error addCustomerToCompany strcpy(country)");
		return 0;
	}

	//copy name
	pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->name =
			strdup(pCust->name);
	if (!pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->name) {
		puts("error addCustomerToCompany strcpy(name)");
		return 0;
	}

	//copy type
	pCompany->tripsArr[i]->customersArr[(pCompany->tripsArr[i]->coustomersCount)]->type =
			pCust->type;

	//increase
	pCompany->tripsArr[i]->coustomersCount++;

	return 1;
}

int addCustomerToCompany_original(Company* pCompany, Customer* pCust) {

	int i = isCountryInCopmany(pCompany, pCust->country);

	/* add the customer to the trip arr in index */
	if (i >= 0) {

		//allocate
		pCompany->tripsArr[i]->customersArr = (Customer**) realloc(
				pCompany->tripsArr[i]->customersArr,
				sizeof(Customer*)
						* (pCompany->tripsArr[i]->coustomersCount + 1));
		if (!pCompany->tripsArr[i]->customersArr) {
			puts("memory error addCustomerToCompany 1");
			return 0;
		}
		pCompany->tripsArr[i]->customersArr[(pCompany->tripsArr[i]->coustomersCount)] =
				(Customer*) malloc(sizeof(Customer));
		if (!pCompany->tripsArr[i]->customersArr[(pCompany->tripsArr[i]->coustomersCount)]) {
			puts("memory error addCustomerToCompany 2");
			return 0;
		}

		//copy country
		pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->country =
				strdup(pCust->country);
		if (!(pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->country)) {
			puts("error addCustomerToCompany strcpy(country)");
			return 0;
		}

		//copy name
		pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->name =
				strdup(pCust->name);
		if (!pCompany->tripsArr[i]->customersArr[pCompany->tripsArr[i]->coustomersCount]->name) {
			puts("error addCustomerToCompany strcpy(name)");
			return 0;
		}

		//copy type
		pCompany->tripsArr[i]->customersArr[(pCompany->tripsArr[i]->coustomersCount)]->type =
				pCust->type;

		//increase
		pCompany->tripsArr[i]->coustomersCount++;

		/* add new trip */
	} else {

		//allocate
		pCompany->tripsArr = (Trip**) realloc(pCompany->tripsArr,
				sizeof(Trip*) * (pCompany->tripsCount + 1));
		pCompany->tripsArr[pCompany->tripsCount] = (Trip*) malloc(sizeof(Trip));
		if (!pCompany->tripsArr[pCompany->tripsCount]) {
			puts("memory error addCustomerToCompany new trip allocation");
			return 0;
		}

		//set trip country
		pCompany->tripsArr[pCompany->tripsCount]->country = strdup(
				pCust->country);
		if (!pCompany->tripsArr[pCompany->tripsCount]->country) {
			puts("error add addCustomerToCompany strcpy(trip country");
			return 0;
		}

		pCompany->tripsArr[pCompany->tripsCount]->customersArr =
				(Customer**) malloc(sizeof(Customer*));
		pCompany->tripsArr[pCompany->tripsCount]->customersArr[0] =
				(Customer*) malloc(sizeof(Customer));

		//copy country
		pCompany->tripsArr[pCompany->tripsCount]->customersArr[0]->country =
				strdup(pCust->country);

		//copy name
		pCompany->tripsArr[pCompany->tripsCount]->customersArr[0]->name =
				strdup(pCust->name);

		//copy type
		pCompany->tripsArr[pCompany->tripsCount]->customersArr[0]->type =
				pCust->type;

		pCompany->tripsArr[pCompany->tripsCount]->coustomersCount = 1;
		pCompany->tripsCount++;

	}

	return 1;
}



int isCountryInCopmany(Company* company, char* country) {
	for (int i = 0; i < company->tripsCount; i++) {
		if (strcmp(company->tripsArr[i]->country, country) == 0)
			return i;
	}
	return -1;
}

int checkAllocation(const void* p) {
	if (!p) {
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

void releaseCompany(Company* pCompany) {
	for (int i = 0; i < pCompany->tripsCount; i++) {
		realeseTrip(pCompany->tripsArr[i]);
		free(pCompany->tripsArr[i]);
	}
	free(pCompany->tripsArr);
	//printf("all freed"); //I added
}

void realeseTrip(Trip* trip) {
	free(trip->country);
	for (int i = 0; i < trip->coustomersCount; i++) {
		realeseCustomer(trip->customersArr[i]);
		free(trip->customersArr[i]);
	}
	free(trip->customersArr);
}
void realeseCustomer(Customer* customer) {
	free(customer->country);
	free(customer->name);
}

int fillCompanySurvey(Company* pCompany) {
	FILE* fp;
	int count, i;
	Customer temp;

	fp = fopen(FILE_NAME, "rb");
	if (!fp)
		return 0;
	if (!fread(&count, sizeof(int), 1, fp)) {
		fclose(fp);
		return 0;
	}

	for (i = 0; i < count; i++) {
		if (!readCustomerFromFile(fp, &temp)) {
			puts("check");
			fclose(fp);
			return 0;
		}

		if (!addCustomerToCompany_new_best(pCompany, &temp)) {
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

void printTotalIncomePerContry(Company* pCompany) {
	int i;
	float income;
	for (i = 0; i < pCompany->tripsCount; i++) {
		income = calculateIncome(pCompany->tripsArr[i]);
		printf("In country %s the income is: %.2f\n",
				pCompany->tripsArr[i]->country, income);
	}
}

float calculateIncome(Trip *pTrip) {

	float ans = 0;
	for (int i = 0; i < pTrip->coustomersCount; i++) {
		switch (pTrip->customersArr[i]->type) {
		case Adult:
			ans += BASE_PRICE;
			break;

		case Child:
			ans += CHILD_PRICE * BASE_PRICE;
			break;

		case Baby:
			ans += BABY_PRICE * BASE_PRICE;
			break;

		case Soldier:
			ans += SOLDIER_PRICE * BASE_PRICE;
			break;
		}
	}
	return ans;
}
