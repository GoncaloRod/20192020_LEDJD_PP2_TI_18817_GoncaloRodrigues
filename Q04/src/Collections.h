#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

#pragma region Types

typedef struct list
{
	void* data;
	struct list* previous;
	struct list* next;
} List;

typedef struct hashTable
{
    List** table;
    int size;
    int (*hashFunc)(void*, int);
} HashTable;

#pragma endregion

#pragma region List functions

/**
 * Add new element to list neatly.
 * Duplicated elements will not be added to the list.
 *
 * @param list Memory address of the list to add the element.
 * @param data Data to add to the list.
 * @param compareValue Function to compare values when adding the element.
 *
 * @return 1 if data was successfully added to list.
 * @return 0 if data wasn't added to list.
 */
int ListAdd(List** list, void* data, int (*compareValue)(void*, void*));

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
void* ListGet(List* list, void* equivalentData, int (*compareValue)(void*, void*));

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
int ListRemove(List** list, void* equivalentData, int (*compareValue)(void*, void*), void (*freeData)(void*));

/**
 * Print data in the list.
 *
 * @param list List to print.
 * @param printData Function used to print a single element data to screen.
 */
void PrintList(List* list, void (*printData)(void*));

/**
 * Calculate average for list.
 *
 * @param list List to calculate average.
 * @param sum Address where you want to store the number of elements in the list. Can be NULL if you don't want to save it.
 * @param getValue Function to get the value to calculate average.
 *
 * @return Final average
 */
float ListAverage(List* list, int* count, int (*getValue)(void*));

/**
 * Delete list from memory.
 *
 * @param queue Memory address of the list to delete.
 * @param freeData Function to use to free the data of each element.
 */
void ClearList(List** list, void (*freeData)(void*));

#pragma endregion

#pragma region Hash table functions

/**
 * Create a new hash table.
 *
 * @param size Size of the hash table.
 * @param hashFunc Hash function associated with the new hash table.
 *
 * @return Memory address of the created hash table.
 */
HashTable* CreateHashTable(int size, int (*hashFunc)(void*, int));

/**
 * Add an element an the hash table.
 * Duplicated data will not be added
 *
 * @param hashTable Hash table where the new element will be added.
 * @param data Data to add to the hash table.
 * @param compareData Function used to compare data.
 *
 * @return 1 if the element was successfully added.
 * @return 0 if the element wasn't added.
 */
int HashTableAdd(HashTable* hashTable, void* data, int (*compareData)(void*, void*));

/**
 * Get an element from the hash table.
 *
 * @param hashTable Hash table to get the element from.
 * @param equivalentData Equivalent data to the element that you want to get from hash table.
 * @param compareData Function used to compare data.
 *
 * @return Memory address of the data if it exists in the hash table.
 * @return NULL if data doesn't exists in the hash table.
 */
void* HashTableGet(HashTable* hashTable, void* equivalentData, int (*compareData)(void*, void*));

/**
 * Remove an element from the hash table.
 *
 * @param hashTable Hash table to remove the element from.
 * @param equivalentData Equivalent data to the element that you want to remove from hash table.
 * @param compareData Function used to compare data.
 * @param freeData Function to free data from memory when removing.
 *
 * @return 1 if the element was removed successfully.
 * @return 0 if the element wasn't removed.
 */
int HashTableRemove(HashTable* hashTable, void* equivalentData, int (*compareData)(void*, void*), void (*freeData)(void*));

/**
 * Calculate average for an hash table.
 *
 * @param hashTable Hash table to calculate average.
 * @param getValue Function to get value from data when calculating average.
 */
float HashTableAverage(HashTable* hashTable, float (*getValue)(void*));

/**
 * Print data in the hash table.
 *
 * @param hashTable Hash table to print.
 * @param printData Function to print an individual element.
 */
void PrintHashTable(HashTable* hashTable, void (*printData)(void*));

/**
 * Clear an hash table from memory.
 *
 * @param hashTable Memory address of the hash table to clear.
 * @param freeData
 */
void ClearHashTable(HashTable** hashTable, void (*freeData)(void*));

#pragma endregion


#endif
