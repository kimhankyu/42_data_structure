/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:16:04 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/25 17:33:21 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList()
{
	LinkedList* ls = (LinkedList*)malloc(sizeof(LinkedList));
	
	if (ls == NULL)
		return (NULL);
	ls->currentElementCount = 0;
	return (ls);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *node;
	ListNode *next;
	ListNode *add;
	
	if (!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (pList->currentElementCount == 0)
	{
		pList->headerNode = element;
		pList->currentElementCount++;
		return (TRUE);
	}
	node = &(pList->headerNode);
	for (int i = 0; i < position - 1; i++)
	{
		node = node->pLink;
	}
	add = (ListNode*)malloc(sizeof(ListNode));
	if (add == NULL)
		return (FALSE);
	add->data = element.data;
	add->pLink = element.pLink;
	next = node->pLink;
	node->pLink = add;
	element.pLink = next;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *next;
	ListNode *node;

	if (!pList)
		return (FALSE);
	if (pList->currentElementCount == 0)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	node = &(pList->headerNode);
	for(int i = 0; i < position - 1; i++)
	{
		node = node->pLink;
	}
	next = node->pLink;
	node->pLink = next->pLink;
	pList->currentElementCount--;
	free(next);
	return(TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *ret;

	if (!pList)
		return (NULL);
	if (position < 0 || position > pList->currentElementCount)
		return (NULL);
	ret = &(pList->headerNode);
	for (int i = 0; i < position; i++)
	{
		ret = ret->pLink;
	}
	return (ret);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *node;
	
	if (!pList)
		return ;
	node = &(pList->headerNode);
	for (int i = 0; i < pList->currentElementCount; ++i)
	{
		node->data = 0;
		node = node->pLink;
	}
}

int getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	if (!pList)
		return ;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		removeLLElement(pList, 0);
	}
	free(pList);
}

void displayLinkedList(LinkedList* pList)
{
	ListNode *node;

	if (!pList)
		return ;
	node = &(pList->headerNode);
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
	{
		printf("%d ", node->data);
		node = node->pLink;
	}
	printf("\n");
	for (int i = 0; i < pList->currentElementCount; ++i)
		printf("====");
	printf("\n");
}
