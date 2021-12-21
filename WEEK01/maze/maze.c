#include "linkedstack.h"
#include <stdio.h>

extern int g_map[HEIGHT][WIDTH];

void	printMap(void)
{
	printf("================\n");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf("%d ", g_map[i][j]);
		}
		printf("\n");
	}
	printf("===============\n");
}

int		poscmp(const t_pos a, const t_pos b)
{
	if (a.x == b.x && a.y == b.y)
		return (TRUE);
	return (FALSE);
}

int		pos_in_map(const t_pos pos)
{
	if ((pos.x >= 0 && pos.x < HEIGHT) && (pos.y >= 0 && pos.y < WIDTH))
		return (TRUE);
	return (FALSE);
}
