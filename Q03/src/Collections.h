#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

typedef struct hashTable
{
	void** table;
	int size;
	int (*hashFunc)(void*, int);
} HashTable;

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
 * Add and element an the hash table.
 *
 * @param hashTable Hash table where the new element will be added.
 * @param data Data to add to the hash table.
 *
 * @return 1 if the element was successfully added.
 * @return 0 if the element wasn't added.
 */
int HashTableAdd(HashTable* hashTable, void* data);

/**
 * Get an element from the hash table.
 *
 * @param hashTable Hash table to get the element from.
 * @param equivalentData Equivalent data to the element that you want to get from hash table.
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
 * @param freeData Function to free data from memory when removing.
 *
 * @return 1 if the element was removed successfully.
 * @return 0 if the element wasn't removed.
 */
int HashTableRemove(HashTable* hashTable, void* equivalentData, int (*compareData)(void*, void*), void (*freeData)(void*));

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

#endif
