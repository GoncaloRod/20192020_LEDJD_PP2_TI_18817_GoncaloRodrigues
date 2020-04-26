#include "Collections.h"

#include <stdlib.h>
#include <assert.h>

void AddSorted(List** list, void* data, int (*compareValue)(void*, void*))
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
	}
	else if (compareValue(data, current->data) < 0)
	{
		// Add new node at the head of the list
		newNode->next = current;
		current->previous = newNode;
		
		*list = newNode;
	}
	else
	{
		// Find position to add new node
		while (current->next != NULL && compareValue(data, current->next->data) >= 0)
			current = current->next;

		newNode->next = current->next;

		if (current->next != NULL)
			newNode->next->previous = newNode;

		current->next = newNode;
		newNode->previous = current;
	}
}

void* GetElement(List* list, void* equivalentData, int (*compareValue)(void*, void*))
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

int RemoveElement(List** list, void* equivalentData, int (*compareValue)(void*, void*), void (*freeData)(void*))
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

void PrintListAscending(List* list, void (*printData)(void*))
{
	List* current = list;

	// Ensure that parameters were passed correctly
	assert(printData != NULL);

	// Go though the list and print data for every node
	while (current)
	{
		printData(current->data);

		current = current->next;
	}
}

void PrintListDescending(List* list, void (*printData)(void*))
{
	// Ensure that parameters were passed correctly
	assert(printData != NULL);

	if (list == NULL)
		return;

	PrintListDescending(list->next, printData);

	printData(list->data);
}

int ListSum(List* list, int (*getValue)(void*))
{
	List* current = list;
	int sum = 0;

	// Ensure that parameters were passed correctly
	assert(getValue != NULL);

	while (current)
	{
		sum += getValue(current->data);

		current = current->next;
	}

	return sum;
}

float ListAverage(List* list, int (*getValue)(void*))
{
	List* current = list;
	int sum = 0, count = 0, value;

	// Ensure that parameters were passed correctly
	assert(getValue != NULL);

	while (current)
	{
		value = getValue(current->data);

		if (value != 0)
		{
			sum += value;
			count++;
		}
		
		current = current->next;
	}

	return (float)sum / count;
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
