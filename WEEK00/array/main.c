/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:32:08 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/22 18:05:55 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	ArrayList *al;
	ArrayListNode node;

	al = createArrayList(6);

	node.data = 1;
	addALElement(al,0,node);

	node.data = 2;
	addALElement(al,1,node);

	node.data = 3;
	addALElement(al,2,node);

	node.data = 4;
	addALElement(al,3,node);

	node.data = 5;
	addALElement(al,4,node);

	displayArrayList(al);
	removeALElement(al, 1);
	displayArrayList(al);
	printf("if arraylist is full -> 1 else -> 0 %d\n",isArrayListFull(al));
	ArrayListNode *pNode = getALElement(al, 2);
	printf("getElement result : %d\n", pNode->data);
	printf("getArrayListLength result : %d\n", getArrayListLength(al));
	clearArrayList(al);
	displayArrayList(al);
	deleteArrayList(al);
	return (0);
}