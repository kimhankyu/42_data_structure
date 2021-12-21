#include "arrayqueue.h"
#include <stdlib.h>

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *ret;

	ret = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	if (ret == NULL)
		return (NULL);
	ret->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (ret->pElement == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->maxElementCount = maxElementCount;
	ret->currentElementCount = 0;
	ret->front = 0;
	ret->rear = -1;
	return (ret);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (pQueue == NULL || isArrayQueueFull(pQueue))
		return (FALSE);
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear].data = element.data;
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *ret;

	ret = peekAQ(pQueue);
	if (ret == NULL)
		return (NULL);
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (ret);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	if (pQueue == NULL || isArrayQueueEmpty(pQueue))
		return (NULL);
	return (pQueue->pElement + pQueue->front);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
		return ;
	free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
		return (FALSE); 
	if (pQueue->currentElementCount == pQueue->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
		return (FALSE);
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
