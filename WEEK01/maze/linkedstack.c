#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

LinkedStack* createLinkedStack()
{
	LinkedStack *ret;

	ret = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (ret == NULL)
		return (NULL);
	ret->currentElementCount = 0;
	ret->pTopElement = NULL;
	return (ret);
}

int pushLS(LinkedStack* pStack, t_pos element)
{
	StackNode *new;
	
	if (pStack == NULL)
		return (FALSE);
	new = (StackNode*)malloc(sizeof(StackNode));
	if (new == NULL)
		return (FALSE);
	new->data.x = element.x;
	new->data.y = element.y;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *ret;

	if (pStack == NULL || isLinkedStackEmpty(pStack))
		return (NULL);
	ret = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	pStack->currentElementCount--;
	return (ret);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (pStack == NULL || isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (pStack == NULL)
		return ;
	while (pStack->pTopElement != NULL)
	{
		StackNode *tmp = pStack->pTopElement;
		pStack->pTopElement = pStack->pTopElement->pLink;
		free(tmp);
	}
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack->currentElementCount != 0)
		return (FALSE);
	return (TRUE);
}
