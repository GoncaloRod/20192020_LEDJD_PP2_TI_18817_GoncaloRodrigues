#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

typedef struct binaryTree
{
	void* data;
	struct binaryTree* left;
	struct binaryTree* right;
} BinaryTree;

/**
 * Add data to binary tree.
 *
 * @param tree Tree to add data to.
 * @param data Data to add to tree.
 * @param comapareData Function used to compare data.
 *
 * @return 1 if data was added with success.
 * @return 0 if data was not added.
 */
int BinaryTreeAdd(BinaryTree** tree, void* data, int (*compareData)(void*, void*));

/**
 * Get data from binary tree.
 *
 * @param tree Tree to get data from.
 * @param equivalentData Equivalent data to the one you want to get.
 * @param comapareData Function used to compare data.
 *
 * @return Pointer to the data if it exists in the tree.
 * @return NULL if it does not exist in the tree.
 */
void* BinaryTreeGet(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*));

/**
 * Remove data from binary tree.
 *
 * @param tree Tree to remove data from.
 * @param equivalentData Equivalent data to the one you want to remove.
 * @param comapareData Function used to compare data.
 * @param freeData Function used to free data of the node.
 * @param copyData Function used to copy data from one node to other's.
 */
void BinaryTreeRemove(BinaryTree** tree, void* equivalentData, int (*compareData)(void*, void*), void (*freeData)(void*), void (*copyData)(void*, void*));

/**
 * Print binary tree using pre-order algorithm.
 *
 * @param tree Binary tree to print.
 * @param printData Function used to print node's data.
 */
void PreOrder(BinaryTree* tree, void (*printData)(void*));

/**
 * Print binary tree using in-order algorithm.
 *
 * @param tree Binary tree to print.
 * @param printData Function used to print node's data.
 */
void InOrder(BinaryTree* tree, void (*printData)(void*));

/**
 * Print binary tree using post-order algorithm.
 *
 * @param tree Binary tree to print.
 * @param printData Function used to print node's data.
 */
void PostOrder(BinaryTree* tree, void (*printData)(void*));

/**
 * Get node with the lowest value in a binary tree.
 *
 * @param tree Tree to get lowest value node.
 *
 * @return Node with the lowest value.
 * @return NULL if tree is empty.
 */
BinaryTree* GetMinValueNodeInTree(BinaryTree* tree);

/**
 * Calculate the height of a tree.
 *
 * @param tree Tree to calculate height.
 */
int BinaryTreeHeight(BinaryTree* tree);

/**
 * Calculate balance factor of a tree.
 *
 * @param tree Tree to calculate balance factor.
 */
int BinaryTreeBalance(BinaryTree* tree);

/**
 * Perform left rotation on a tree.
 *
 * @param tree Tree to rotate left.
 */
void BinaryTreeLeftRotate(BinaryTree** tree);

/**
 * Perform right rotation on a tree.
 *
 * @param tree Tree to rotate right.
 */
void BinaryTreeRightRotate(BinaryTree** tree);

/**
 * Make a query in a tree.
 * Results will be automatically printed in order.
 *
 * @param tree Tree to run query.
 * @param equivalentData Equivalent data to the one you want to query.
 * @param compareData Function to compare data when querying.
 * @param printData Function to print data.
 */
void BinaryTreeQuery(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*), void (*printData)(void*));

/**
 * Get the number of elements in a tree with a filter.
 *
 * @param tree Tree to calculate count.
 * @param equivalent Data Equivalent data to the one you want to filter.
 * @param compareData Function to compare data when filtering.
 *
 * @return Number of elements in the tree that passed the filter.
 */
int BinaryTreeQueryCount(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*));

/**
 * Calculate the sum in a tree with a filter.
 *
 * @param tree Tree to calculate sum.
 * @param equivalent Data Equivalent data to the one you want to filter.
 * @param compareData Function to compare data when filtering.
 * @param getValue Function to get value to calculate sum.
 *
 * @return Sum of the elements in the tree that passed the filter.
 */
float BinaryTreeQuerySum(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*), float (*getValue)(void*));

/**
 * Calculate the average in a tree with a filter.
 *
 * @param tree Tree to calculate sum.
 * @param equivalent Data Equivalent data to the one you want to filter.
 * @param compareData Function to compare data when filtering.
 * @param getValue Function to get value to calculate average.
 *
 * @return Average of the elements in the tree that passed the filter.
 */
float BinaryTreeQueryAverage(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*), float (*getValue)(void*));

/**
 * Clear a tree from memory.
 *
 * @param tree Tree to clear.
 * @param freeData Function to free data in nodes.
 */
void ClearBinaryTree(BinaryTree** tree, void (*freeData)(void*));

#endif