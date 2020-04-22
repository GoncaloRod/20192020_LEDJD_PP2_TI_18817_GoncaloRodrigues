#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

typedef struct list
{
	void* data;
	struct list* previous;
	struct list* next;
} List;

/**
 * Add new element to list neatly.
 * Duplicated elements will not be added to the list.
 *
 * @param list Memory address of the list to add the element.
 * @param data Data to add to the list.
 * @param compareValue Function to compare values when adding the element.
 */
void AddSorted(List** list, void* data, int (*compareValue)(void*, void*));

/**
 * Get an element from list.
 *
 * @param list List to get the element from.
 * @param equivalentData Memory address to an equivalent element.
 * @param compareValue Function to compare values when getting the element.
 *
 * @return Memory address of the element if it exists in the list.
 * @return NULL if the element doesn't exist in the list.
 */
void* GetElement(List* list, void* equivalentData, int (*compareValue)(void*, void*));

/**
 * Remove an element from list.
 *
 * @param list Memory address of the list to remove the element from.
 * @param equivalentData Memory address to an equivalent element.
 * @param compareValue Function to compare values when getting the element.
 * @param freeData Function to use to free the data of each element.
 *
 * @return 1 if the element was removed with success.
 * @return 0 if the element wasn't removed from the list.
 */
int RemoveElement(List** list, void* equivalentData, int (*compareValue)(void*, void*), void (*freeData)(void*));

/**
 * Print data in the list in ascending order.
 *
 * @param list List to print.
 * @param printElement Function to print element's data individually.
 */
void PrintListAscending(List* list, void (*printData)(void*));

/**
 * Print data in the list in descending order.
 *
 * @param list List to print.
 * @param printElement Function to print element's data individually.
 */
void PrintListDescending(List* list, void (*printData)(void*));

/**
 * Calculate sum for list.
 *
 * @param list List to calculate sum.
 * @param getValue Function to get the value to calculate sum.
 */
int ListSum(List* list, int (*getValue)(void*));

/**
 * Calculate average for list.
 *
 * @param list List to calculate average.
 * @param getValue Function to get the value to calculate average.
 */
float ListAverage(List* list, int (*getValue)(void*));

/**
 * Delete list from memory.
 *
 * @param queue Memory address of the list to delete.
 * @param freeData Function to use to free the data of each element.
 */
void ClearList(List** list, void (*freeData)(void*));

#endif
