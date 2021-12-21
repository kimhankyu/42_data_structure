/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:58:39 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/26 14:25:01 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>


int	main(void)
{
	LinkedList *a = createLinkedList();
	// LinkedList *b = createLinkedList();
	ListNode ele;
	ele.degree = 0;
	ele.coef = 0;
	ele.pLink = NULL;
	// input_poly(a);
	
	addLLElement(a, 0, ele);
	ele.degree = 1;
	ele.coef = 2;
	ele.pLink = NULL;
	addLLElement(a, 0, ele);
	
		ele.degree = 2;
	ele.coef = 3;
	ele.pLink = NULL;
	addLLElement(a, 1, ele);
	displayLinkedList(a);
	return (0);
}