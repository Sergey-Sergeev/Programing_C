#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>


void add_graph_link(GRAPH** g, GRAPH* link)
{
	if (*g == NULL)
	{
		(*g) = link;
	}
	else
	{
		NODE* n = (NODE*)malloc(sizeof(NODE));
		n->next = NULL;
		n->data = (void*)link;
		add_node(&((*g)->links), n);
		(*g)->listLen++;
	}
}

GRAPH* create_graph(int x, int y, int weight)
{
	GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
	graph->x = x;
	graph->y = y;
	graph->listLen = 0;
	graph->links = NULL;
	graph->weight = weight;
	return graph;
}

void del_graph(GRAPH** g)
{
	if ((*g)->listLen == 0)
	{
		free(*g);
		return;
	}

	int i = 0;
	for (; i < (*g)->listLen; i++)
	{
		del_graph(&((GRAPH*)(get_node(&((*g)->links), i)->data)));
		freeList(&(((GRAPH*)(get_node(&((*g)->links), i)->data))->links));
	}
}
