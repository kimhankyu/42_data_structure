#include "../arraygraph/arraygraph.h"

int		setting_floyd(ArrayGraph *pGraph, int ***mdt, int ***nxt);
void	iter(int **mdt, int **nxt, int max, int ver);
void	print_path(ArrayGraph *pGraph, int **nxt, int from, int to);
void	dis_Array(int **pp, int max);
int		free_data(int **mdt, int **nxt, int max, int ret);

int		floyd(ArrayGraph *pGraph)
{
	int **mdt;
	int **nxt;

	if (!setting_floyd(pGraph, &mdt, &nxt))
		return (free_data(mdt, nxt, pGraph->maxVertexCount, FALSE));
	printf("mdt\n");
	dis_Array(mdt, pGraph->maxVertexCount);
	printf("nxt\n");
	dis_Array(nxt, pGraph->maxVertexCount);
	
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		iter(mdt, nxt, pGraph->maxVertexCount, i);
		printf("mdt\n");
		dis_Array(mdt, pGraph->maxVertexCount);
		printf("nxt\n");
		dis_Array(nxt, pGraph->maxVertexCount);
	}
	print_path(pGraph, nxt, 2, 4);

	return (free_data(mdt, nxt, pGraph->maxVertexCount, TRUE));
}

int		malloc_ppp(ArrayGraph *pGraph, int ***ppp)
{
	*ppp = (int**)calloc(pGraph->maxVertexCount, sizeof(int*));
	
	if (*ppp == NULL)
		return (FALSE);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		(*ppp)[i] = (int*)calloc(pGraph->maxVertexCount, sizeof(int));
		if ((*ppp)[i] == FALSE)
		{
			for (int j = 0; j <= i; j++)
				free((*ppp)[j]);
			free((*ppp));
			return (FALSE);
		}
	}
	return (TRUE);
}

int		setting_floyd(ArrayGraph *pGraph, int ***mdt, int ***nxt)
{
	if (!malloc_ppp(pGraph, mdt) || !malloc_ppp(pGraph, nxt))
		return (FALSE);

	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (i == j)
			{
				(*nxt)[i][j] = j;
				continue;
			}
			(*mdt)[i][j] = pGraph->ppAdjEdge[i][j];
			if ((*mdt)[i][j] == 0 && i != j)
			{
				(*mdt)[i][j] = INT32_MAX;
				continue;
			}
			(*nxt)[i][j] = j;
		}
	}
	return (TRUE);
}

void	iter(int **mdt, int **nxt, int max, int ver)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (i == ver || j == ver)
				continue ;
			long long tmp = (long long)mdt[i][ver] + (long long)mdt[ver][j];
			if ((long long)mdt[i][j] > tmp)
			{
				mdt[i][j] = tmp;
				nxt[i][j] = nxt[i][ver];
			}
		}
	}
}

void	print_path(ArrayGraph *pGraph, int **nxt, int from, int to)
{
	int tmp = from;
	printf("=====[%d]->[%d] path=====\n", from, to);
	printf("[%d]", from);
	while (nxt[tmp][to] != to)
	{
		printf("->[%d]", nxt[tmp][to]);
		tmp = nxt[tmp][to];
	}
	printf("->[%d]", nxt[tmp][to]);
	printf("\n===========================\n");
}

void	dis_Array(int **pp, int max)
{
	printf("==========================\n");
	for (int i = 0; i < max; i++)
	{
		printf("[%d]  ", i);
		for (int j = 0; j < max; j++)
		{
			printf("%2d ", pp[i][j]);
		}
		printf("\n");
	}
	printf("==========================\n");
}

int		free_data(int **mdt, int **nxt, int max, int ret)
{
	if (mdt != NULL)
	{
		for (int i = 0; i < max; i++)
			if (mdt[i])
				free(mdt[i]);
		free(mdt);
	}
	if (nxt != NULL)
	{
		for (int i = 0; i < max; i++)
			if (nxt[i])
				free(nxt[i]);
		free(nxt);
	}
	return (ret);
}


int		main(void)
{
	ArrayGraph *A;

	A = createArrayGraph(5, GRAPH_UNDIRECTED);

	for (int i = 0; i < 5; i++)
		addVertexAG(A, i);
	addEdgewithWeightAG(A, 0, 1, 4);
	addEdgewithWeightAG(A, 0, 2, 1);
	addEdgewithWeightAG(A, 0, 3, 1);
	addEdgewithWeightAG(A, 1, 4, 8);
	addEdgewithWeightAG(A, 2, 3, 3);
	addEdgewithWeightAG(A, 2, 4, 15);
	addEdgewithWeightAG(A, 3, 4, 6);

	displayArrayGraph(A);

	floyd(A);

	deleteArrayGraph(A);
	return (0);
}