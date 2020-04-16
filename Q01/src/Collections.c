#include "Collections.h"

#include <stdlib.h>
#include <assert.h>

void Enqueue(Queue** queue, void* data)
{
    Queue* newElement, *tail;

    // Ensure that parameters were passed correctly
    assert(queue != NULL);
    assert(data != NULL);

    // Allocate new node and ensure that it was allocated correctly
    newElement = (Queue*)malloc(sizeof(Queue));
    assert(newElement != NULL);

    // Set data for new node
    newElement->next = NULL;
    newElement->data = data;

    if (*queue == NULL)
    {
        // Queue is empty so add new element in the head
        *queue = newElement;
    }
    else
    {
        // Find tail element
        tail = *queue;

        while (tail->next != NULL)
            tail = tail->next;

        // Add new element in tail
        tail->next = newElement;
    }
}

void* Dequeue(Queue** queue)
{
    Queue* next;
    void* nextData;

    // Ensure that a queue was passed
	assert(queue != NULL);

	// Save the element to take from queue and set the next as the head
    next = *queue;
    *queue = next->next;

    // Save data
    nextData = next->data;

    // Free node
    free(next);

    return nextData;
}

void* Peek(Queue** queue)
{
    // Ensure that a queue was passed
    assert(queue != NULL);

    // If queue has elements return data from the head. if not return NULL
    return *queue != NULL ? (*queue)->data : NULL;
}

void FreeQueue(Queue** queue, void (*freeData)(void*))
{
    Queue* current, *next;

    // Ensure that parameters were passed correctly
    assert(queue != NULL);
    assert(freeData != NULL);

    current = *queue;

    while (current != NULL)
    {
        next = current->next;

        // Free data first, then node
        freeData(current->data);
        free(current);

        current = next;
    }

    // Clear previous stored address
    *queue = NULL;
}
