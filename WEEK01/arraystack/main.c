#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

void displayArrayStack(ArrayStack* pStack)
{
	if (pStack == NULL)
	{
		printf("Stack pointer doesn't exist\n\n");
		return ;
	}
	if (pStack->currentElementCount == 0)
	{
		printf("No elements in stack\n\n");
		return ;
	}
	printf("=====STACK=====\n");
	printf("Stack size : %d\n", pStack->currentElementCount);
	for (int i = pStack->currentElementCount - 1; i >= 0; i--)
	{
		printf("[%d] : %d\n", pStack->currentElementCount - i - 1, (int)pStack->pElement[i].data);
	}
	printf("===============\n\n");
}

int	main(void)
{
	ArrayStack *pStack;
	ArrayStackNode new;
	ArrayStackNode *temp;

	pStack = createArrayStack(3);

	printf("EMPTY? : %d\n\n", isArrayStackEmpty(pStack));

	new.data = 0;
	pushAS(pStack, new);
	new.data = 1;
	pushAS(pStack, new);
	new.data = 2;
	pushAS(pStack, new);
	displayArrayStack(pStack);

	printf("FULL? : %d\n\n", isArrayStackFull(pStack));

	new.data = 3;
	pushAS(pStack, new);
	displayArrayStack(pStack);

	temp = popAS(pStack);
	printf("POP : %d\n", temp->data);
	temp = peekAS(pStack);
	printf("PEEK : %d\n", temp->data);
	displayArrayStack(pStack);

	popAS(pStack);
	popAS(pStack);
	displayArrayStack(pStack);

	printf("EMPTY? : %d\n\n", isArrayStackEmpty(pStack));

	popAS(pStack);
	return (0);
}