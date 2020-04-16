#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

typedef struct queue
{
	void* data;
	struct queue* next;
} Queue;

/**
 * Add an element to the queue.
 *
 * @param queue Address of the queue where the element will be added.
 * @param data Pointer to the data of the new element.
 */
void Enqueue(Queue** queue, void* data);

/**
 * Take the next element in the queue.
 *
 * @param queue Address of the queue to take an element from.
 *
 * @return Pointer to the data taken from the queue.
 * @return NULL if the queue was empty.
 */
void* Dequeue(Queue** queue);

/**
 * Get the next element in the queue without removing him.
 *
 * @param queue Address of the queue to take an element from.
 *
 * @return Pointer to the next element's data in the queue.
 * @return NULL if the queue is empty.
 */
void* Peek(Queue** queue);

/**
 * Delete queue from memory.
 *
 * @param queue Address of the queue to delete.
 * @param freeData Function pointer to use to free the data of each element.
 */
void FreeQueue(Queue** queue, void (*freeData)(void*));

#endif