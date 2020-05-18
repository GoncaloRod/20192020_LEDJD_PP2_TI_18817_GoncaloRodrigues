#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct _taxPayer
{
	int taxNumber;
	char name[32];
	char job[32];
	char hometown[32];
} TaxPayer;

void PrintTaxPayer(void* taxPayer)
{
	TaxPayer* tp = (TaxPayer*)taxPayer;

	// Ensure parameters were passed correctly
	assert(tp != NULL);

	printf("%d - %s, %s, %s\n", tp->taxNumber, tp->name, tp->job, tp->hometown);
}

int CompareTaxPayers(void* taxPayer1, void* taxPayer2)
{
	TaxPayer* tp1 = (TaxPayer*)taxPayer1;
	TaxPayer* tp2 = (TaxPayer*)taxPayer2;

	assert(tp1 != NULL);
	assert(tp2 != NULL);

	if (tp1->taxNumber < tp2->taxNumber)
		return -1;
	else if (tp1->taxNumber == tp2->taxNumber)
		return 0;
	else
		return 1;
}

void CopyTaxPayer(void* destination, void* source)
{
	TaxPayer* d = (TaxPayer*)destination;
	TaxPayer* s = (TaxPayer*)source;

	// Ensure parameters were passed correctly
	assert(d != NULL);
	assert(s != NULL);

	d->taxNumber = s->taxNumber;
	strcpy(d->name, s->name);
	strcpy(d->job, s->job);
	strcpy(d->hometown, s->hometown);
}

#endif
