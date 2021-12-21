/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:43:57 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/26 18:50:34 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>

void input_poly(LinkedList *list)
{
	ListNode node;
	
	printf("========poly=========\n");
	while (TRUE)
	{
		int scan;
		printf("[coef degree]  ");
		scan = scanf("%d%d", &(node.coef), &(node.degree));
		if (!addPolyElement(list, node))
			return ;
		if (scan != 2)
			break;
	}
	printf("=====================\n");
}

int addPolyElement(LinkedList *list, ListNode node)
{
	int position = 0;
	if (!list)
		return (FALSE);
	while (position < list->currentElementCount)
	{
		ListNode *getnode = getLLElement(list, position);
		if (node.degree == getnode->degree)
		{
			getnode->coef += node.coef;
			break;
		}
		else if (node.degree > getnode->degree)
		{
			if (!addLLElement(list, position, node))
				return (FALSE);
			break ;
		}
		++position;
	}
	if (position == list->currentElementCount)
	{
		if (!addLLElement(list, position, node))
			return (FALSE);
	}
	return (TRUE);
}

// int addPoly(LinkedList *a, LinkedList *b)
// {
// 	int a_position = 0;
// 	int b_position = 0;

	

// }
