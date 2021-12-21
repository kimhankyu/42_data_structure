#include "linkedgraph.h"

int list_add(LinkedList *list, int vertex_id, int weight)
{
	LinkedList *add;
	if (!list)
		return (TRUE);
	add = (LinkedList*)calloc(1, sizeof(LinkedList));
	if (!add)
		return (FALSE);
	add->vertex = vertex_id;
	add->weight = weight;
	add->next = list;
	list->next = add;
	return (TRUE);
}