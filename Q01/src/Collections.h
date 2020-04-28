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
 * @param queue Queue where the element will be added.
 * @param data Data to add to the queue.
 */
void Enqueue(Queue** queue, void* data);

/**
 * Take the next element in the queue.
 *
 * @param queue Queue to take an element from.
 *
 * @return Pointer to the data taken from the queue.
 * @return NULL if the queue was empty.
 */
void* Dequeue(Queue** queue);

/**
 * Get the next element in the queue without removing him.
 *
 * @param queue Queue to take an element from.
 *
 * @return Pointer to the next element's data in the queue.
 * @return NULL if the queue is empty.
 */
void* Peek(Queue* queue);

/**
 * Delete queue from memory.
 *
 * @param queue Queue to delete.
 * @param freeData Function used to free the data of each element.
 */
void ClearQueue(Queue** queue, void (*freeData)(void*));

/**
 * Calculate average for a queue.
 *
 * @param queue Queue to calculate average.
 * @param getValue Function used to get the value to calculate average.
 *
 * @return Final average.
 */
float AverageQueue(Queue* queue, float (*getValue)(void*));

/**
 * Print every element in the queue.
 *
 * @param queue Queue to print.
 * @param printData Function used to print data in the queue.
 */
void PrintQueue(Queue* queue, void (*printData)(void*));

#endif