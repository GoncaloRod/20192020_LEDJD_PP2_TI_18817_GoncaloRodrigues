#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structs.h"
#include "Collections.h"

int main(int argc, char** argv)
{
	HashTable* hashTable;
	Affiliate* affiliate;

	Affiliate affiliates[] = {
		{.id = 235, .name = "Louis", 21},
		{.id = 654, .name = "IceN", 20},
		{.id = 367, .name = "lebobrainiac", 20},
		{.id = 356, .name = "Riki", 19},
	};

	hashTable = CreateHashTable(10, &AffiliateHash);
	
	// Populate hash table with data inside the array
	for (int i = 0; i < sizeof(affiliates) / sizeof(Affiliate); i++)
	{
		affiliate = (Affiliate*)malloc(sizeof(Affiliate));

		affiliate->id = affiliates[i].id;
		affiliate->age = affiliates[i].age;
		strcpy(affiliate->name, affiliates[i].name);

		HashTableAdd(hashTable, affiliate);
	}

	// Search and update
	affiliate = HashTableGet(hashTable, &affiliates[1], &CompareAffiliates);
	affiliate->age++;

	// Remove
	HashTableRemove(hashTable, &affiliates[3], &CompareAffiliates, &free);

	// Print
	PrintHashTable(hashTable, &PrintAffiliate);

	// Clear hash table from memory
	ClearHashTable(&hashTable, &free);

	return 0;
}