/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:29:12 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/25 17:39:34 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
	DoublyList *ret = (DoublyList*)malloc(sizeof(DoublyList));
	if (ret == NULL)
		return (NULL);
	ret->currentElementCount = 0;
	return (ret);
}

void deleteDoublyList(DoublyList* pList)
{
	if (!pList)
		return ;
	clearDoublyList(pList);
	free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *node;
	DoublyListNode *prev;
	DoublyListNode *add;

	if (!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (pList->currentElementCount == 0)
	{
		pList->headerNode.data = element.data;
		pList->headerNode.pLLink = &(pList->headerNode);
		pList->headerNode.pRLink = &(pList->headerNode);
		pList->currentElementCount++;
		return (TRUE);
	}
	node = getDLElement(pList, position);
	add = (DoublyListNode*)malloc(sizeof(DoublyListNode));
	if (node == NULL || add == NULL)
		return (FALSE);
	add->data = element.data;
	prev = node->pLLink;
	add->pRLink = node;
	add->pLLink = prev;
	node->pLLink = add;
	prev->pRLink = add;
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	
	if (!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	node = getDLElement(pList, position);
	if (node == NULL)
		return (FALSE);
	node->pLLink->pRLink = node->pRLink;
	node->pRLink->pLLink = node->pLLink;
	pList->currentElementCount--;
	free(node);
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	int num;
	if (!pList)
		return ;
	num = pList->currentElementCount;
	for (int i = 0; i < num; ++i)
	{
		removeDLElement(pList, 0);
	}
}

int getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *ret;

	if (!pList)
		return (NULL);
	if (position < 0 || position > pList->currentElementCount)
		return (NULL);
	t_flag flag = rotation_direction(*pList, position);
	ret = &(pList->headerNode);
	if (flag == CW)
	{
		for (int i = 0; i < position; ++i)
		{
			ret = ret->pRLink;
		}
	}
	else
	{
		for (int i = 0; i < pList->currentElementCount - position; ++i)
		{
			ret = ret->pLLink;
		}
	}
	return (ret);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *node;

	if (!pList)
		return ;
	node = &(pList->headerNode);
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
	{
		printf("%d ", node->data);
		node = node->pRLink;
	}
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
}

