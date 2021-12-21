#include "binsearchtree.h"

BinSearchTree* createBinSearchTree()
{
	BinSearchTree* ret;

	ret = (BinSearchTree*)calloc(1, sizeof(BinSearchTree));
	if (ret == NULL)
		return (ret);
}



int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
	if (!pBinSearchTree)
		return (FALSE);
	
	return (TRUE);
}

BinSearchTreeNode *find_insert_position(BinSearchTreeNode *node, BinSearchTreeNode element)
{
	t_state state;

	if (node == NULL)
		return (NULL);
	state = node_state(node);
	if (state == EMPTY)
		return (node);
	if (element.key == node->key)
		return (node);
	else if (element.key < node->key)
	{
		if (state == LEFT || state == FULL)
			find_insert_position(node->pLeftChild, element);
		return (node);
	}
	else if (element.key > node->key)
	{
		if (state == RIGHT || state == FULL)
			find_insert_position(node->pRightChild, element);
		return (node);
	}
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
	return (TRUE);
}

t_state node_state(BinSearchTreeNode *node)
{
	// if (node == NULL)
	// 	return (EMPTY);
	if (node->pLeftChild)
	{
		if (node->pRightChild)
			return (FULL);
		else
			return (LEFT);
	}
	else
	{
		if (node->pRightChild)
			return (RIGHT);
		else
			return (EMPTY);
	}
}

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key);
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key);

void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);
