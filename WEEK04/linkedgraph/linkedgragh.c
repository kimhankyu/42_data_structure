#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount, int graph_type)
{
	LinkedGraph *ret;

	ret = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (ret == NULL)
		return (NULL);
	ret->maxVertexCount = maxVertexCount;
	ret->currentVertexCount = 0;
	ret->currentEdgeCount = 0;
	ret->graphType = graph_type;
	ret->ppAdjEdge = (LinkedList**)malloc(sizeof(LinkedList*) * maxVertexCount);
	if (ret->ppAdjEdge == NULL)
		goto ERR;
	for (int i = 0; i < maxVertexCount; i++)
	{
		ret->ppAdjEdge[i] = (LinkedList*)calloc(1, sizeof(LinkedList));
		if (ret->ppAdjEdge[i] == NULL)
		{
			for (int j = 0; j <= i; j++)
				free(ret->ppAdjEdge[j]);
			free(ret->ppAdjEdge);
			goto ERR;
		}
	}
	ret->pVertex = (int*)calloc(maxVertexCount, sizeof(int));
	if (ret->pVertex != NULL)
		goto EXIT;
ERR:
	deleteLinkedGraph(ret);
	return (NULL);
EXIT:
	return (ret);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		removeVertexLG(pGraph, i);
	if (pGraph->pVertex != NULL)
		free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (pGraph->currentVertexCount != 0)
		return (FALSE);
	return (TRUE);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);
	pGraph->currentVertexCount++;
	pGraph->pVertex[vertexID] = USED;
	return (TRUE);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph, fromVertexID) ||
	!checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	if (!list_add(pGraph->ppAdjEdge[fromVertexID], toVertexID, 1))
		return (FALSE);
	if (pGraph->graphType == GRAPH_UNDIRECTED ||
	!list_add(pGraph->ppAdjEdge[toVertexID], fromVertexID, 1))
		return (FALSE);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->currentEdgeCount += 2;
	else
		pGraph->currentEdgeCount++;
	return (TRUE);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!checkVertexValid(pGraph, fromVertexID) ||
	!checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	if (!list_add(pGraph->ppAdjEdge[fromVertexID], toVertexID, weight))
		return (FALSE);
	if (pGraph->graphType == GRAPH_UNDIRECTED ||
	!list_add(pGraph->ppAdjEdge[toVertexID], fromVertexID, weight))
		return (FALSE);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->currentEdgeCount += 2;
	else
		pGraph->currentEdgeCount++;
	return (TRUE);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (vertexID < 0 ||
	vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	return (TRUE);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	LinkedList *p;

	if (!checkVertexValid(pGraph, vertexID) || pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	p = pGraph->ppAdjEdge[vertexID];
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	while (p != NULL)
	{
		removeEdgeLG(pGraph, vertexID, p->vertex);
		p = p->next;
	}
	return (TRUE);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedList *p;
	LinkedList *tmp;

	if (!checkVertexValid(pGraph, fromVertexID) ||
	!checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	p = pGraph->ppAdjEdge[fromVertexID];
	if (p == NULL)
		return (FALSE);
	while (p->next != NULL)
	{
		if (p->next->vertex == toVertexID)
			break ;
		p = p->next;
	}
	if (p->next == NULL)
		return (FALSE);
	tmp = p->next;
	p->next = p->next->next;
	pGraph->currentEdgeCount--;
	free(tmp);
	return (TRUE);
}

// int findGraphNodePosition(LinkedList* pList, int vertexID);

// void displayLinkedGraph(LinkedGraph* pGraph);