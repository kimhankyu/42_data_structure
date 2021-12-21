#include "linkeddeque.h"
#include <stdlib.h>

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *ret;

	ret = (LinkedDeque*)calloc(1, sizeof(LinkedDeque));
	if (ret == NULL)
		return (NULL);
	return (ret);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;

	if (pDeque == NULL)
		return (FALSE);
	new = (DequeNode*)malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	new->pRLink = pDeque->pFrontNode;
	new->pLLink = NULL;
	if (pDeque->pFrontNode != NULL)
	{
		pDeque->pFrontNode->pLLink = new;
	}
	else
	{
		pDeque->pRearNode = new;
	}
	pDeque->pFrontNode = new;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;
	
	if (pDeque == NULL)
		return (FALSE);
	new = (DequeNode*)malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	new->pRLink = NULL;
	new->pLLink = pDeque->pRearNode;
	if (pDeque->pRearNode != NULL)
	{
		pDeque->pRearNode->pRLink = new;
	}
	else
	{
		pDeque->pFrontNode = new;
	}
	pDeque->pRearNode = new;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* popFrontLD(LinkedDeque* pDeque)
{
	DequeNode *ret;

	if (pDeque == NULL || (ret = peekFrontLD(pDeque)) == NULL)
		return (NULL);
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	if (pDeque->pFrontNode != NULL)
	{
		pDeque->pFrontNode->pLLink = NULL;
	}
	else
	{
		pDeque->pRearNode = NULL;
	}
	pDeque->currentElementCount--;
	return (ret);
}

DequeNode* popRearLD(LinkedDeque* pDeque)
{
	DequeNode *ret;

	if (pDeque == NULL || (ret = peekRearLD(pDeque)) == NULL)
		return (NULL);
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	if (pDeque->pRearNode != NULL)
	{
		pDeque->pRearNode->pRLink = NULL;
	}
	else
	{
		pDeque->pFrontNode = NULL;
	}
	pDeque->currentElementCount--;
	return (ret);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
		return ;
	while (pDeque->pFrontNode != NULL)
	{
		DequeNode *p = popFrontLD(pDeque);
		free(p);
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
		return (FALSE);
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
