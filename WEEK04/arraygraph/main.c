#include "arraygraph.h"

int		main(void)
{
	ArrayGraph *A;

	A = createArrayGraph(5, GRAPH_UNDIRECTED);

	for (int i = 0; i < 5; i++)
		addVertexAG(A, i);
	printf("%d\n", A->currentVertexCount);

	if (!addEdgewithWeightAG(A, 0, 1, 4))
		printf("aaaaaaaa\n");
	
	addEdgewithWeightAG(A, 0, 2, 1);
	addEdgewithWeightAG(A, 0, 3, 1);
	addEdgewithWeightAG(A, 1, 4, 8);
	addEdgewithWeightAG(A, 2, 3, 3);
	addEdgewithWeightAG(A, 2, 4, 15);
	addEdgewithWeightAG(A, 3, 4, 6);
	

	displayArrayGraph(A);
	deleteArrayGraph(A);
	return (0);
}