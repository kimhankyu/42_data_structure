#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct s_LinkedList
{
	int	vertex;
	int weight;
	struct s_LinkedList *next;
} LinkedList;

typedef struct LinkedGraphType
{
	int maxVertexCount;
	int currentVertexCount;
	int currentEdgeCount;
	int graphType;
	LinkedList** ppAdjEdge;
	int *pVertex;
} LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount, int graph_type);
void deleteLinkedGraph(LinkedGraph* pGraph);
int isEmptyLG(LinkedGraph* pGraph);
int addVertexLG(LinkedGraph* pGraph, int vertexID);
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int checkVertexValid(LinkedGraph* pGraph, int vertexID);
int removeVertexLG(LinkedGraph* pGraph, int vertexID);
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);
void displayLinkedGraph(LinkedGraph* pGraph);

/* list.c */
int list_add(LinkedList *list, int vertex_id, int weight);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif