#include "Collections.h"

#include <stdlib.h>
#include <assert.h>

#pragma region List functions

int ListAdd(List** list, void* data, int (*compareValue)(void*, void*))
{
	List* current;
	List* newNode;

	// Ensure that parameters were passed correctly
	assert(list != NULL);
	assert(data != NULL);
	assert(compareValue != NULL);

	// Create new node
	newNode = (List*)malloc(sizeof(List));

	assert(newNode != NULL);

	newNode->previous = newNode->next = NULL;
	newNode->data = data;

	// Find position for newNode
	current = *list;

	if (current == NULL)
	{
		// List is empty, add new node in the head
		*list = newNode;
		return 1;
	}
	
	// Find list's tail element
	while (current->next != NULL)
	{
		if (compareValue(current->data, data) == 0)
		{
			// Duplicate found
			free(newNode);
			return 0;
		}

		current = current->next;
	}

	// Compare tail's data with data
	if (compareValue(current->data, data) == 0)
	{
		// Duplicate found
		free(newNode);
		return 0;
	}

	// Add new node in the tail
	current->next = newNode;
	newNode->previous = current;

	return 1;
}

void* ListGet(List* list, void* equivalentData, int (*compareValue)(void*, void*))
{
	List* current;

	// Ensure that parameters were passed correctly
	assert(equivalentData != NULL);
	assert(compareValue != NULL);

	current = list;

	while (current != NULL)
	{
		if (compareValue(equivalentData, current->data) == 0)
			return current->data;

		current = current->next;
	}

	return NULL;
}

int ListRemove(List** list, void* equivalentData, int (*compareValue)(void*, void*), void (*freeData)(void*))
{
	List* current;

	// Ensure that parameters were passed correctly
	assert(list != NULL);
	assert(equivalentData != NULL);
	assert(compareValue != NULL);

	current = *list;

	while (current != NULL)
	{
		if (compareValue(equivalentData, current->data) == 0)
		{
			if (current->previous == NULL)
			{
				// Element to remove is the head
				*list = current->next;
				current->next->previous = NULL;
			}
			else
			{
				if (current->next != NULL)
					current->next->previous = current->previous;

				current->previous->next = current->next;
			}

			// Free memory for the node and his data
			freeData(current->data);
			free(current);

			return 1;
		}

		current = current->next;
	}

	return 0;
}

void PrintList(List* list, void (*printData)(void*))
{
	List* current = list;

	// Ensure parameters were passed correctly
	assert(printData != NULL);

	while (current != NULL)
	{
		printData(current->data);

		current = current->next;
	}
}

float ListAverage(List* list, int* count, int (*getValue)(void*))
{
	List* current = list;
	int sum = 0, c = 0, value;

	// Ensure that parameters were passed correctly
	assert(getValue != NULL);

	while (current)
	{
		value = getValue(current->data);

		if (value != 0)
		{
			sum += value;
			c++;
		}

		current = current->next;
	}

	if (count != NULL)
		*count = c;

	if (c == 0)
		return 0.0f;

	return (float)sum / c;
}

void ClearList(List** list, void (*freeData)(void*))
{
	List* current;
	List* next;

	// Ensure that parameters were passed correctly
	assert(list != NULL);
	assert(freeData != NULL);

	current = *list;

	while (current != NULL)
	{
		// Save next node
		next = current->next;

		// Clear current data and node
		freeData(current->data);
		free(current);

		current = next;
	}

	*list = NULL;
}

#pragma endregion

#pragma region Hash table functions

HashTable* CreateHashTable(int size, int (*hashFunc)(void*, int))
{
	HashTable* hash;

	// Ensure that parameters were passed correctly
	assert(hashFunc != NULL);

	// Allocate memory for hash table struct
	hash = (HashTable*)malloc(sizeof(HashTable));

	// Allocate memory for hash tables' array
	hash->table = malloc(size * sizeof(List*));

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

int HashTableAdd(HashTable* hashTable, void* data, int (*compareData)(void*, void*))
{
	int index;

	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(data != NULL);

	// Calculate index for data to add with hash function
	index = hashTable->hashFunc(data, hashTable->size);

	// Add data to correct list
	return ListAdd(&hashTable->table[index], data, compareData);
}

void* HashTableGet(HashTable* hashTable, void* equivalentData, int (*compareData)(void*, void*))
{
	int index;

	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(equivalentData != NULL);

	// Calculate index for equivalent data using hash function
	index = hashTable->hashFunc(equivalentData, hashTable->size);

	// Get data from the correct list
	return ListGet(hashTable->table[index], equivalentData, compareData);
}

int HashTableRemove(HashTable* hashTable, void* equivalentData, int (*compareData)(void*, void*), void (*freeData)(void*))
{
	int index;

	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(equivalentData != NULL);
	assert(freeData != NULL);

	// Calculate index for equivalent data using hash function
	index = hashTable->hashFunc(equivalentData, hashTable->size);

	// Remove data from the correct list
	return ListRemove(&hashTable->table[index], equivalentData, compareData, freeData);
}

float HashTableAverage(HashTable* hashTable, float (*getValue)(void*))
{
	float sum = 0.0f;
	int count = 0, countTemp;

	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(getValue != NULL);

	for (int i = 0; i < hashTable->size; i++)
	{
		sum += ListAverage(hashTable->table[i], &countTemp, getValue);
		count += countTemp;
	}

	return sum / count;
}

void PrintHashTable(HashTable* hashTable, void (*printData)(void*))
{
	// Ensure parameters were passed correctly
	assert(hashTable != NULL);
	assert(printData != NULL);

	for (int i = 0; i < hashTable->size; i++)
	{
		printf("[%d]:\n", i);

		if (hashTable->table[i] != NULL)
		{
			PrintList(hashTable->table[i], printData);
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
		ClearList(&(*hashTable)->table[i], freeData);

	// Free table
	free((*hashTable)->table);

	// Free hash table
	free(*hashTable);

	*hashTable = NULL;
}

#pragma endregion
