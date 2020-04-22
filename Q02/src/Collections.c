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
