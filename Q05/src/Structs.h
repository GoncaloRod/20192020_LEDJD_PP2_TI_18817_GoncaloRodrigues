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
	float salary;
} TaxPayer;

/**
 * Print a Tax Payer to the screen.
 *
 * @param taxPayer Tax Payer to print.
 */
void PrintTaxPayer(void* taxPayer)
{
	TaxPayer* tp = (TaxPayer*)taxPayer;

	// Ensure parameters were passed correctly
	assert(tp != NULL);

	printf("%d - %s, %s, %s - Salary: %.2f\n", tp->taxNumber, tp->name, tp->job, tp->hometown, tp->salary);
}

/**
 * Compare two Tax Payers.
 *
 * @param taxPayer1 Tax payer 1 to compare.
 * @param taxPayer2 Tax payer 2 to compare.
 *
 * @return 1 if taxPayer1 is greater than taxPayer2.
 * @return 0 if taxPayer1 is equal to taxPayer2.
 * @return -1 if taxPayer1 is less than taxPayer2.
 */
int CompareTaxPayers(void* taxPayer1, void* taxPayer2)
{
	TaxPayer* tp1 = (TaxPayer*)taxPayer1;
	TaxPayer* tp2 = (TaxPayer*)taxPayer2;

	// Ensure parameters were passed correctly
	assert(tp1 != NULL);
	assert(tp2 != NULL);

	if (tp1->taxNumber < tp2->taxNumber)
		return -1;
	else if (tp1->taxNumber == tp2->taxNumber)
		return 0;
	else
		return 1;
}

/**
 * Compare hometown of 2 Tax Payers.
 *
 * @param taxPayer1 Tax payer 1 to compare.
 * @param taxPayer2 Tax payer 2 to compare.
 *
 * @return 1 if taxPayer1 hometown is greater than taxPayer2's.
 * @return 0 if taxPayer1 hometown is equal to taxPayer2's.
 * @return -1 if taxPayer1 hometown is less than taxPayer2's.
 */
int CompareTaxPayerHometown(void* taxPayer1, void* taxPayer2)
{
	TaxPayer* tp1 = (TaxPayer*)taxPayer1;
	TaxPayer* tp2 = (TaxPayer*)taxPayer2;

	// Ensure parameters were passed correctly
	assert(tp1 != NULL);
	assert(tp2 != NULL);

	return strcmp(tp1->hometown, tp2->hometown);
}

/**
 * Compare job of 2 Tax Payers.
 *
 * @param taxPayer1 Tax payer 1 to compare.
 * @param taxPayer2 Tax payer 2 to compare.
 *
 * @return 1 if taxPayer1 job is greater than taxPayer2's.
 * @return 0 if taxPayer1 job is equal to taxPayer2's.
 * @return -1 if taxPayer1 job is less than taxPayer2's.
 */
int CompareTaxPayerJob(void* taxPayer1, void* taxPayer2)
{
	TaxPayer* tp1 = (TaxPayer*)taxPayer1;
	TaxPayer* tp2 = (TaxPayer*)taxPayer2;

	// Ensure parameters were passed correctly
	assert(tp1 != NULL);
	assert(tp2 != NULL);

	return strcmp(tp1->job, tp2->job);
}

/**
 * Copy data from 1 Tax Payer to another.
 *
 * @param destination Tax Payer to receive new data.
 * @param source Source of the data.
 */
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
	d->salary = s->salary;
}

float GetTaxPayerSalary(void* taxPayer)
{
	TaxPayer* tp = (TaxPayer*)taxPayer;

	assert(tp != NULL);

	return tp->salary;
}

#endif
