/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:57:49 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/22 18:07:11 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *ret;

	if (maxElementCount <= 0)
		return (NULL);
	ret = (ArrayList*)malloc(sizeof(ArrayList));
	if (ret == NULL)
		return (NULL);
	ret->maxElementCount = maxElementCount;
	ret->currentElementCount = 0;
	ret->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (ret->pElement == NULL)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

void deleteArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	free(pList->pElement);
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (FALSE);
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (!pList)
		return (FALSE);
	if (pList->maxElementCount == pList->currentElementCount)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	for (int i = pList->currentElementCount; i > position; --i)
	{
		pList->pElement[i] = pList->pElement[i - 1];
	}
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	if (!pList)
		return (FALSE);
	if (pList->currentElementCount == 0)
		return (FALSE);
	if(position >= 0 && position < pList->currentElementCount)
	{
		for(int i = position; i < pList->currentElementCount - 1; i++)
		{
			pList->pElement[i] = pList->pElement[i + 1];
		}
		pList->currentElementCount--;
	}
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if(position >= 0 && position < pList->currentElementCount)
	{
		return (&(pList->pElement[position]));
	}
	return (NULL);
}

void displayArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
	{
		printf("[%d] ", pList->pElement[i].data);
	}
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
}

void clearArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	for (int i = 0; i < pList->maxElementCount; ++i)
	{
		pList->pElement[i].data = 0;
	}
}

int getArrayListLength(ArrayList* pList)
{
	if (pList == NULL)
	{
		return (-1);
	}
	return (pList->currentElementCount);
}