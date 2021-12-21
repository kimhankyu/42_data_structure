#include "arraystack.h"
#include <stdlib.h>

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *ret;

	if (maxElementCount <= 0)
		return (NULL);
	ret = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (ret == NULL)
		return (NULL);
	ret->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (ret->pElement == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->maxElementCount = maxElementCount;
	ret->currentElementCount = 0;
	return (ret);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	if (!pStack)
		return (FALSE);
	if (isArrayStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode *ret = peekAS(pStack);
	if (ret == NULL)
		return (NULL);
	pStack->currentElementCount--;
	return (ret);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	if (!pStack)
		return (NULL);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (pStack->pElement + pStack->currentElementCount - 1);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return ;
	free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
