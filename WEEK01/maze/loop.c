#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

static int dx[4] = {1, 0, -1, 0};
static int dy[4] = {0, 1, 0, -1};

extern int g_map[HEIGHT][WIDTH];

/*
push()
동서남북 -> 0이면 (for문 다돌고 출구 아니면 pop)
이동
push()

*/

int		findPath(const t_pos currPos, const t_pos endPos, LinkedStack *pStack)
{
	int i;
	int flag = 0;
	t_pos curr = currPos;

	while (TRUE)
	{
		if (flag == 0)
		{
			g_map[curr.y][curr.x] = 2;
			if (pushLS(pStack, curr) == FALSE)
				return (FALSE);
		}
		flag = 0;
		for (i = 0; i < 4; ++i)
		{
			t_pos pos = {curr.x + dx[i], curr.y + dy[i]};
			if (pos_in_map(pos) && (g_map[pos.y][pos.x] == 0))
			{
				curr = pos;
				break;
			}
		}
		if (i == 4)
		{
			if (poscmp(curr, endPos))
				break ;
			else
			{
				StackNode *tmp = popLS(pStack);
				g_map[curr.y][curr.x] = 3;
				if (tmp == NULL)
					return (FALSE);
				free(tmp);
				tmp = peekLS(pStack);
				if (tmp == NULL)
					return (FALSE);
				printf("curr [%d %d] tmp [%d %d]\n", curr.x, curr.y, tmp->data.x, tmp->data.y);
				curr = tmp->data;
				flag = 1;
			}
		}
	}
	return (TRUE);
}
