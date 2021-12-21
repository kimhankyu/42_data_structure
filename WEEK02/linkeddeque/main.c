#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedDequeType
{
	int currentElementCount;
	int *pFrontNode;
} LinkedDeque;

int main(void)
{
	LinkedDeque *p = calloc(1, sizeof(LinkedDeque));
	if (p->pFrontNode == NULL)
		printf("aaaa\n");
	if (p->currentElementCount == 0)
		printf("bbbb\n");
	return (0);
}