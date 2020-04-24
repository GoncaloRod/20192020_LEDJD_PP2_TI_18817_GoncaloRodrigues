#include "Collections.h"

#include <stdlib.h>
#include <assert.h>

HashTable* CreateHashTable(int size, int (*hashFunc)(void*, int))
{
	HashTable* hash;

	// Ensure that parameters were passed correctly
	assert(hashFunc != NULL);

	// Allocate memory for hash table struct
	hash = (HashTable*)malloc(sizeof(HashTable));

	// Allocate memory for hash tables' array
	hash->table = malloc(size * sizeof(void*));

	// Initialize array elements with NULL
	for (int i = 0; i < size; i++)
	{
		hash->table[i] = NULL;
	}

	// Save hash table size and hash function
	hash->size = size;
	hash->hashFunc = hashFunc;

	return hash;
}

int HashTableAdd(HashTable* hashTable, void* data)
{
	int index;
	int attempts = 0;

	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(data != NULL);

	// Calculate index for data to add with hash function
	index = hashTable->hashFunc(data, hashTable->size);

	// Find the closest empty index
	while (hashTable->table[index] != NULL && attempts < hashTable->size)
	{
		index = (index + 1) % hashTable->size;

		attempts++;
	}

	if (attempts == hashTable->size)
	{
		// Hash table is full
		return 0;
	}

	// Add data to the hash table
	hashTable->table[index] = data;

	return 1;
}

void* HashTableGet(HashTable* hashTable, void* equivalentData, int (*compareData)(void*, void*))
{
	int index;
	int attempts = 0;
	void* match = NULL;

	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(equivalentData != NULL);

	// Calculate index for equivalent data using hash function
	index = hashTable->hashFunc(equivalentData, hashTable->size);

	// Find data position in hash table
	while (attempts < hashTable->size && match == NULL)
	{
		index = (index + 1) % hashTable->size;;
		attempts++;

		if (hashTable->table[index] != NULL && compareData(hashTable->table[index], equivalentData) == 0)
			match = hashTable->table[index];
	}

	return match;
}

int HashTableRemove(HashTable* hashTable, void* equivalentData, int (*compareData)(void*, void*), void (*freeData)(void*))
{
	int index;
	int attempts = 0;
	void* match = NULL;

	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(equivalentData != NULL);
	assert(freeData != NULL);

	// Calculate index for equivalent data using hash function
	index = hashTable->hashFunc(equivalentData, hashTable->size);

	// Find data position in hash table
	while (attempts < hashTable->size && match == NULL)
	{
		index = (index + 1) % hashTable->size;
		attempts++;

		if (hashTable->table[index] != NULL && compareData(hashTable->table[index], equivalentData) == 0)
			match = hashTable->table[index];
	}

	if (match == NULL)
	{
		// Element doesn't exist in the hash
		return 0;
	}

	freeData(match);
	hashTable->table[index] = NULL;
	
	return 1;
}

void PrintHashTable(HashTable* hashTable, void (*printData)(void*))
{
	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(printData != NULL);

	for (int i = 0; i < hashTable->size; i++)
	{
		printf("[%d] ", i);

		if (hashTable->table[i] != NULL)
		{
			printData(hashTable->table[i]);

			printf(" %d collisions\n", abs(i - hashTable->hashFunc(hashTable->table[i], hashTable->size)));
		}
		else
		{
			printf("Empty slot\n");
		}
	}
}

void ClearHashTable(HashTable** hashTable, void (*freeData)(void*))
{
	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(*hashTable != NULL);
	assert(freeData != NULL);

	// Free data in table
	for (int i = 0; i < (*hashTable)->size; i++)
		freeData((*hashTable)->table[i]);

	// Free table
	free((*hashTable)->table);

	// Free hash table
	free(*hashTable);

	*hashTable = NULL;
}
