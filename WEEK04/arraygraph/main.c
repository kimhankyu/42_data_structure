#include "arraygraph.h"

int		main(void)
{
	ArrayGraph *A;

	A = createArrayGraph(10, GRAPH_UNDIRECTED);

	displayArrayGraph(A);
	
	return (0);
}