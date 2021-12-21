/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:07:56 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/22 19:34:09 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>

int	main(void)
{
	LinkedList *ls;
	ListNode node;

	ls = createLinkedList(6);
	node.data = 1;
	addLLElement(ls,0,node);
	node.data = 2;
	addLLElement(ls,1,node);
	node.data = 3;
	addLLElement(ls,2,node);
	node.data = 4;
	addLLElement(ls,3,node);
	node.data = 5;
	addLLElement(ls,4,node);
    displayLinkedList(ls);
	removeLLElement(ls, 1);
    displayLinkedList(ls);
    ListNode *lNode = getLLElement(ls, 2);
	printf("getElement result : %d\n", lNode->data);
    printf("getlinkedListLength result : %d\n", getLinkedListLength(ls));
	clearLinkedList(ls);
	displayLinkedList(ls);
	deleteLinkedList(ls);
	return (0);