#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

static int dx[4] = {1, 0, -1, 0};
static int dy[4] = {0, 1, 0, -1};

extern int g_map[HEIGHT][WIDTH];

int		findPath(const t_pos currPos, const t_pos endPos, LinkedStack *pStack)
{
	t_pos pos;

	g_map[currPos.y][currPos.x] = 2;
	if (pushLS(pStack, currPos) == FALSE)
		return (FALSE);
	for (int i = 0; i < 4; ++i)
	{
		pos.x = currPos.x + dx[i];
		pos.y = currPos.y + dy[i];
		if (pos_in_map(pos) && g_map[pos.y][pos.x] == 0)
			if (findPath(pos, endPos, pStack))
				return (TRUE);
	}
	if (poscmp(currPos, endPos) == FALSE)
	{
		g_map[currPos.y][currPos.x] = 3;
		StackNode *pop;
		pop = popLS(pStack);
		free(pop);
		return (FALSE);
	}
	return (TRUE);
}