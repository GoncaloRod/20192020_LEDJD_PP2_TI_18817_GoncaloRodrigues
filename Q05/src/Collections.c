#include "Collections.h"

#include <stdlib.h>
#include <assert.h>

int BinaryTreeAdd(BinaryTree** tree, void* data, int (*compareData)(void*, void*))
{
	int compareResult, balance;

	// Ensure parameters were passed correctly
	assert(tree != NULL);
	assert(data != NULL);
	assert(compareData != NULL);

	if (*tree == NULL)
	{
		// Add new node here

		// Allocate memory for new node
		*tree = (BinaryTree*)malloc(sizeof(BinaryTree));
		
		// Ensure memory was successfully allocated
		assert(*tree != NULL);

		// Set new node's data
		(*tree)->left = (*tree)->right = NULL;
		(*tree)->data = data;

		return 1;
	}

	// Add new node to the left or right?
	compareResult = compareData(data, (*tree)->data);

	if (compareResult < 0)
	{
		if (!BinaryTreeAdd(&(*tree)->left, data, compareData))
			return 0;
	}
	else if (compareResult > 0)
	{
		if (BinaryTreeAdd(&(*tree)->right, data, compareData))
			return 0;
	}
	else
	{
		return 0;
	}

	// Calculate node's balance factor
	balance = BinaryTreeBalance(*tree);

	if (balance >= -1 && balance <= 1)
	{
		// Tree is balanced
		return 1;
	}

	// Tree is not balanced
	// 4 possible cases
	if (balance > 1 && compareData(data, (*tree)->left->data) < 0)
	{
		// Left-left
		BinaryTreeRightRotate(tree);
	}
	else if (balance < -1 && compareData(data, (*tree)->right->data) > 0)
	{
		// Right-right
		BinaryTreeLeftRotate(tree);
	}
	else if (balance > 1 && compareData(data, (*tree)->left->data) > 0)
	{
		// Left-right
		BinaryTreeLeftRotate(&(*tree)->left);
		BinaryTreeRightRotate(tree);
	}
	else if (balance < -1 && compareData(data, (*tree)->right->data) < 0)
	{
		// Right-left
		BinaryTreeRightRotate(&(*tree)->right);
		BinaryTreeLeftRotate(tree);
	}
	else
	{
		// Unknown case. Thrown an error
		assert(0);
	}

	return 1;
}

void* BinaryTreeGet(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*))
{
	int compareResult;

	// Ensure parameters were passed correctly
	assert(equivalentData != NULL);
	assert(compareData != NULL);

	// Reached the end without a match
	if (tree == NULL)
		return NULL;

	compareResult = compareData(equivalentData, tree->data);
		
	if (compareResult < 0)
		return BinaryTreeGet(tree->left, equivalentData, compareData);
	else if (compareResult > 0)
		return BinaryTreeGet(tree->right, equivalentData, compareData);
	else
		return tree->data;
}

void BinaryTreeRemove(BinaryTree** tree, void* equivalentData, int (*compareData)(void*, void*), void (*freeData)(void*), void (*copyData)(void*, void*))
{
	int compareResult, balance;
	BinaryTree* helperNode;

	// Ensure parameters were passed correctly
	assert(tree != NULL);
	assert(equivalentData != NULL);
	assert(compareData != NULL);

	if (*tree == NULL)
		return;

	compareResult = compareData(equivalentData, (*tree)->data);

	if (compareResult < 0)
	{
		BinaryTreeRemove(&(*tree)->left, equivalentData, compareData, freeData, copyData);
	}
	else if (compareResult > 0)
	{
		BinaryTreeRemove(&(*tree)->right, equivalentData, compareData, freeData, copyData);
	}
	else
	{
		if ((*tree)->left == NULL)
		{
			helperNode = (*tree)->right;

			freeData((*tree)->data);
			free(*tree);

			*tree = helperNode;
		}
		else if ((*tree)->right == NULL)
		{
			helperNode = (*tree)->left;

			freeData((*tree)->data);
			free(*tree);

			*tree = helperNode;
		}
		else
		{
			helperNode = GetMinValueNodeInTree((*tree)->right);

			copyData((*tree)->data, helperNode->data);

			BinaryTreeRemove(&(*tree)->right, helperNode->data, compareData, freeData, copyData);
		}
	}

	// Tree is empty. No need to balance
	if (*tree == NULL)
		return;

	// Calculate node's balance factor
	balance = BinaryTreeBalance(*tree);

	if (balance >= -1 && balance <= 1)
	{
		// Tree is balanced
		return;
	}

	// 4 possible cases
	if (balance > 1 && BinaryTreeBalance((*tree)->left) >= 0)
	{
		// Left-left
		BinaryTreeRightRotate(tree);
	}
	else if (balance < -1 && BinaryTreeBalance((*tree)->right) <= 0)
	{
		// Right-right
		BinaryTreeLeftRotate(tree);
	}
	else if (balance > 1 && BinaryTreeBalance((*tree)->left) < 0)
	{
		// Left-right
		BinaryTreeLeftRotate(&(*tree)->left);
		BinaryTreeRightRotate(tree);
	}
	else if (balance < -1 && BinaryTreeBalance((*tree)->right) > 0)
	{
		// Right-left
		BinaryTreeRightRotate(&(*tree)->right);
		BinaryTreeLeftRotate(tree);
	}
	else
	{
		// Unknown case
		assert(0);
	}
}

void PreOrder(BinaryTree* tree, void (*printData)(void*))
{
	if (tree == NULL)
		return;

	printData(tree->data);

	PreOrder(tree->left, printData);
	PreOrder(tree->right, printData);
}

void InOrder(BinaryTree* tree, void (*printData)(void*))
{
	if (tree == NULL)
		return;

	InOrder(tree->left, printData);

	printData(tree->data);

	InOrder(tree->right, printData);
}

void PostOrder(BinaryTree* tree, void (*printData)(void*))
{
	if (tree == NULL)
		return;

	PostOrder(tree->left, printData);
	PostOrder(tree->right, printData);

	printData(tree->data);
}

BinaryTree* GetMinValueNodeInTree(BinaryTree* tree)
{
	BinaryTree* current = tree;

	while (current != NULL && current->left != NULL)
		current = current->left;

	return current;
}

int BinaryTreeHeight(BinaryTree* tree)
{
	int leftHeight, rightHeight, maxHeight;

	if (tree == NULL)
		return 0;

	leftHeight = BinaryTreeHeight(tree->left);
	rightHeight = BinaryTreeHeight(tree->right);

	if (leftHeight > rightHeight)
		maxHeight = leftHeight;
	else
		maxHeight = rightHeight;

	return maxHeight + 1;
}

int BinaryTreeBalance(BinaryTree* tree)
{
	if (tree == NULL)
		return 0;

	return BinaryTreeHeight(tree->left) - BinaryTreeHeight(tree->right);
}

void BinaryTreeLeftRotate(BinaryTree** tree)
{
	BinaryTree* rightNode;
	BinaryTree* t2;

	// Ensure parameters were passed correctly
	assert(tree != NULL);

	rightNode = (*tree)->right;
	t2 = rightNode->left;

	rightNode->left = *tree;
	(*tree)->right = t2;
	*tree = rightNode;
}

void BinaryTreeRightRotate(BinaryTree** tree)
{
	BinaryTree* leftNode;
	BinaryTree* t3;

	// Ensure parameters were passed correctly
	assert(tree != NULL);

	leftNode = (*tree)->left;
	t3 = leftNode->right;

	leftNode->right = *tree;
	(*tree)->left = t3;
	*tree = leftNode;
}

void BinaryTreeQuery(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*), void (*printData)(void*))
{
	// Ensure parameters were passed correctly
	assert(equivalentData != NULL);
	assert(compareData != NULL);
	assert(printData != NULL);

	if (tree == NULL)
		return;

	BinaryTreeQuery(tree->left, equivalentData, compareData, printData);

	if (compareData(equivalentData, tree->data) == 0)
		printData(tree->data);

	BinaryTreeQuery(tree->right, equivalentData, compareData, printData);
}

int BinaryTreeQueryCount(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*))
{
	int count = 0;

	// Ensure parameters were passed correctly
	assert(equivalentData != NULL);
	assert(compareData != NULL);

	if (tree == NULL)
		return 0;

	if (compareData(tree->data, equivalentData) == 0)
		count++;

	count += BinaryTreeQueryCount(tree->left, equivalentData, compareData);
	count += BinaryTreeQueryCount(tree->right, equivalentData, compareData);

	return count;
}

float BinaryTreeQuerySum(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*), float (*getValue)(void*))
{
	float sum = 0.0f;

	// Ensure parameters were passed correctly
	assert(equivalentData != NULL);
	assert(compareData != NULL);
	assert(getValue != NULL);

	if (tree == NULL)
		return 0.0f;

	if (compareData(tree->data, equivalentData) == 0)
		sum += getValue(tree->data);

	sum += BinaryTreeQuerySum(tree->left, equivalentData, compareData, getValue);
	sum += BinaryTreeQuerySum(tree->right, equivalentData, compareData, getValue);

	return sum;
}

float BinaryTreeQueryAverage(BinaryTree* tree, void* equivalentData, int (*compareData)(void*, void*), float (*getValue)(void*))
{
	float sum, count;

	// Ensure parameters were passed correctly
	assert(equivalentData != NULL);
	assert(compareData != NULL);
	assert(getValue != NULL);

	sum = BinaryTreeQuerySum(tree, equivalentData, compareData, getValue);
	count = BinaryTreeQueryCount(tree, equivalentData, compareData);

	return count > 0 ? sum / count : 0.0f;
}

void ClearBinaryTree(BinaryTree** tree, void (*freeData)(void*))
{
	// Ensure parameters were passed correctly
	assert(tree != NULL);
	assert(freeData != NULL);

	if (*tree == NULL)
		return;

	ClearBinaryTree(&(*tree)->left, freeData);
	ClearBinaryTree(&(*tree)->right, freeData);

	freeData((*tree)->data);
	free(*tree);

	*tree = NULL;
}
