#include "Collections.h"

#include <stdlib.h>

List* CreateList()
{
	// Allocate list
	List* list = (List*)malloc(sizeof(List));

	// Evaluate if list was correctly allocated
	if (!list)
		return NULL;

	// Init list values
	list->count = 0;
	list->head	= NULL;
	list->tail	= NULL;

	return list;
}

static Node* CreateNode()
{
	// Allocate node
	Node* node = (Node*)malloc(sizeof(Node));

	// Evaluate if node was correctly allocated
	if (!node)
		return NULL;

	// Init node values
	node->value = NULL;
	node->next	= NULL;

	return node;
}

void Enqueue(List* list, void* data)
{
	// Ensure that list exists 
	if (!list)
		return;
	
	// Create a node and set his value
	Node* node = CreateNode();
	node->value = data;

	if (!list->head)
	{
		// If list is empty head and tail will point to the same node
		list->head = node;
		list->tail = node;
	}
	else
	{
		// Add node to the end of the list
		list->tail->next = node;

		// Update list's tail
		list->tail = node;
	}
}

void* Dequeue(List* list)
{
	// Ensure that list exists and that is not empty
	if (!list || !list->head)
		return NULL;

	// Get node at the head of the list and his value
	Node* node = list->head;
	void* value = node->value;

	// Point the head of the list to next node
	list->head = node->next;

	free(node);

	return value;
}

void* Peek(List* list)
{
	// Ensure that list exists and that is not empty
	if (!list || !list->head)
		return NULL;
	
	// Return the value from the node at the head of the list
	return list->head->value;
 }

void FreeList(List* list, void (*freeValue)(void*))
{
	// Ensure that list exists
	if (!list)
		return;

	// Helper variable to save the next node to be freed
	Node* next;

	// Cycle through every node from the list
	for (Node* current = list->head; current; current = next)
	{
		// Save next node to be freed
		next = current->next;

		// Free node's value and node
		freeValue(current->value);
		free(current);
	}

	// Free list after every node is freed
	free(list);
}
