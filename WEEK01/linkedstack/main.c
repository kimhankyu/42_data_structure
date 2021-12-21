#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

void displayLinkedStack(LinkedStack *pStack)
{
	StackNode *node;

	if (pStack == NULL)
	{
		printf("Stack pointer doesn't exist\n\n");
		return ;
	}
	node = pStack->pTopElement;
	if (pStack->currentElementCount == 0)
	{
		printf("No elements in stack\n\n");
		return ;
	}
	printf("=====STACK=====\n");
	printf("Stack size : %d\n", pStack->currentElementCount);
	while (node != NULL)
	{
		printf("[%d]\n", node->data);
		node = node->pLink;
	}
	printf("===============\n\n");
}

int main(void)
{
	LinkedStack *pStack;
	StackNode new;
	StackNode *temp;

	pStack = createLinkedStack();

	printf("EMPTY? : %d\n\n", isLinkedStackEmpty(pStack));

	new.data = 0;
	pushLS(pStack, new);
	new.data = 1;
	pushLS(pStack, new);
	new.data = 2;
	pushLS(pStack, new);
	displayLinkedStack(pStack);

	temp = popLS(pStack);
	printf("pop : %d\n", (int)temp->data);
	free(temp);
	temp = peekLS(pStack);
	printf("peek : %d\n", (int)temp->data);
	displayLinkedStack(pStack);

	popLS(pStack);
	popLS(pStack);
	displayLinkedStack(pStack);

	printf("EMPTY? : %d\n\n", isLinkedStackEmpty(pStack));

	popLS(pStack);

	deleteLinkedStack(pStack);

	return (0);
}