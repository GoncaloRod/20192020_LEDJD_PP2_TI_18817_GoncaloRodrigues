#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Collections.h"
#include "Structs.h"

int main(int argc, char** argv)
{
	BinaryTree* tree = NULL;
	TaxPayer* taxPayer;

	TaxPayer taxPayers[] = {
		{ .taxNumber = 479856569, .name = "Goncalo", .job = "Gameplay Programmer", .hometown = "Viseu" },
		{ .taxNumber = 945412232, .name = "Henrique", .job = "Backend Programmer", .hometown = "Porto" },
		{ .taxNumber = 745644466, .name = "Luis", .job = "Sound Designer", .hometown = "Viseu" },
		{ .taxNumber = 375546686, .name = "Carlos", .job = "Gameplay Programmer", .hometown = "Viseu" },
		{ .taxNumber = 512131313, .name = "Tomas", .job = "Graphics Programmer", .hometown = "Kortrijk" },
		{ .taxNumber = 278925466, .name = "Ze Manel", .job = "Unemployed", .hometown = "Lisboa" }
	};

	for (int i = 0; i < sizeof(taxPayers) / sizeof(TaxPayer); i++)
	{
		taxPayer = (TaxPayer*)malloc(sizeof(TaxPayer));

		assert(taxPayer != NULL);

		taxPayer->taxNumber = taxPayers[i].taxNumber;
		strcpy(taxPayer->name, taxPayers[i].name);
		strcpy(taxPayer->job, taxPayers[i].job);
		strcpy(taxPayer->hometown, taxPayers[i].hometown);

		BinaryTreeAdd(&tree, (void*)taxPayer, &CompareTaxPayers);
	}

	// Get & Update
	taxPayer = BinaryTreeGet(tree, &taxPayers[1], &CompareTaxPayers);

	if (taxPayer != NULL)
		strcpy(taxPayer->job, "System Administrator");

	// Remove
	BinaryTreeRemove(&tree, &taxPayers[5], &CompareTaxPayers, &free, &CopyTaxPayer);

	// Print
	printf("Tax Payers:\n");
	InOrder(tree, &PrintTaxPayer);

	// Query
	printf("\n\nTax Payers in %s:\n", taxPayers[0].hometown);
	BinaryTreeQuery(tree, &taxPayers[0], &CompareTaxPayerHometown, &PrintTaxPayer);

	ClearBinaryTree(&tree, &free);

	return 0;
}