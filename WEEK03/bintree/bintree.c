#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *ret;

	ret = (BinTree*)malloc(sizeof(BinTree));
	if (ret == NULL)
		return (NULL);
	ret->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	if (ret->pRootNode == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->pRootNode->data = rootNode.data;
	ret->pRootNode->visited = FALSE;
	ret->pRootNode->pLeftChild = NULL;
	ret->pRootNode->pRightChild = NULL;
	return (ret);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (!pParentNode || pParentNode->pLeftChild != NULL)
		return (NULL);
	pParentNode->pLeftChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	if (pParentNode->pLeftChild == NULL)
		return (NULL);
	pParentNode->pLeftChild->data = element.data;
	pParentNode->pLeftChild->visited = FALSE;
	pParentNode->pLeftChild->pLeftChild = NULL;
	pParentNode->pLeftChild->pRightChild = NULL;
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (!pParentNode || pParentNode->pRightChild != NULL)
		return (NULL);
	pParentNode->pRightChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	if (pParentNode->pRightChild == NULL)
		return (NULL);
	pParentNode->pRightChild->data = element.data;
	pParentNode->pRightChild->visited = FALSE;
	pParentNode->pRightChild->pLeftChild = NULL;
	pParentNode->pRightChild->pRightChild = NULL;
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode || pNode->pLeftChild == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode || pNode->pRightChild == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree)
		return ;
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}

void preorderTraversalBinTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	printf("|%c| ", pNode->data);
	preorderTraversalBinTree(pNode->pLeftChild);
	preorderTraversalBinTree(pNode->pRightChild);
}

void inorderTraversalBinTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	inorderTraversalBinTree(pNode->pLeftChild);
	printf("|%c| ", pNode->data);
	inorderTraversalBinTree(pNode->pRightChild);
}

void postorderTraversalBinTree(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	postorderTraversalBinTree(pNode->pLeftChild);
	postorderTraversalBinTree(pNode->pRightChild);
	printf("|%c| ", pNode->data);
}

int main(void)
{
    BinTree *pBinTree;
    BinTreeNode new;
	
    new.data = 'A';
    pBinTree = makeBinTree(new);
    new.data = 'B';
    insertLeftChildNodeBT(pBinTree->pRootNode, new);
    new.data = 'C';
    insertRightChildNodeBT(pBinTree->pRootNode, new);
    new.data = 'D';
    insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild, new);
    new.data = 'E';
    insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild, new);
    new.data = 'F';
    insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild, new);
    new.data = 'G';
    insertRightChildNodeBT(pBinTree->pRootNode->pRightChild, new);
    new.data = 'H';
    insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, new);
    new.data = 'I';
    insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, new);
    new.data = 'J';
    insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pRightChild, new);
    new.data = 'K';
    insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pLeftChild, new);
    new.data = 'L';
    insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, new);
    new.data = 'M';
    insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, new);
    printf("PREORDER\n");
    preorderTraversalBinTree(pBinTree->pRootNode);
    printf("\n");
    printf("INORDER\n");
    inorderTraversalBinTree(pBinTree->pRootNode);
    printf("\n");
    printf("POSTORDER\n");
    postorderTraversalBinTree(pBinTree->pRootNode);
    deleteBinTree(pBinTree);
	return (0);
}