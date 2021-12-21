#include "reverselist.h"
#include <stdio.h>

int	main(void)
{
	LinkedList *ls;
	ListNode node;

	ls = createLinkedList();
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
	reverseLinkedList(ls);
	// displayLinkedList(ls);
	return (0);
}