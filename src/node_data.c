
/*
 * node_data.c
 *
 *
 *
 *
 *
 *
 *
 *  Created on: March 8, 2020
 *      Author: Siavash Tabrizian
 */
 
 
#include <node_data.h>

/*
	Node constructor form previous node
*/
nodeType *newNode(nodeType *prev, dVector nodedat)
{
	dataType * data;

	if (!(data = (dataType *)mem_malloc(sizeof(dataType))))
		errMsg("allocation", "newNode", "dataType", 0);

	if (!(data->data = (dVector)arr_alloc(prev->data->vec_size, double)))
		errMsg("Allocation", "changeRhs", "rhs", 0);
	data->data = nodedat;
	data->vec_size = prev->data->vec_size;
	
	nodeType * new_node;
	
	if ( !(new_node = (nodeType *) mem_malloc(sizeof(nodeType))) )
			errMsg("allocation", "newNode", "new_node", 0);
	
	if( !(new_node->prevnode = (dataType *) mem_malloc (sizeof(dataType))))
			errMsg("allocation", "newNode", "previous node pointer", 0);
	new_node->prevnode = prev;
	
	
	if( !(new_node->nextnode = (dataType *) mem_malloc (sizeof(dataType))))
			errMsg("allocation", "newNode", "next node pointer", 0);
	prev->nextnode = new_node;
	
	
	if ( !(new_node->data = (dataType *)mem_malloc(sizeof(dataType))))
		errMsg("allocation", "new_node->data", "next node pointer", 0);
	new_node->data = data;
	
		
}

/*
	Node constructor from scratch
*/
nodeType *newNodeOrig(int size, dVector nodedat)
{
	dataType * data;

	if (!(data = (dataType *)mem_malloc(sizeof(dataType))))
		errMsg("allocation", "newNode", "dataType", 0);

	if (!(data->data = (dVector)arr_alloc(size, double)))
		errMsg("Allocation", "changeRhs", "rhs", 0);
	data->data = nodedat;
	data->vec_size = size;

	nodeType * new_node;

	if (!(new_node = (nodeType *)mem_malloc(sizeof(nodeType))))
		errMsg("allocation", "newNode", "new_node", 0);

	if (!(new_node->nextnode = (dataType *)mem_malloc(sizeof(dataType))))
		errMsg("allocation", "newNode", "next node pointer", 0);

	if (!(new_node->data = (dataType *)mem_malloc(sizeof(dataType))))
		errMsg("allocation", "new_node->data", "next node pointer", 0);
	new_node->data = data;

}

/*
   This is the sorting comparison for heap sorting of nodes
   The current comparison is based on the twoNorm of the data vector
*/
bool OneGreater2(nodeType *one, nodeType *two)
{
	if (oneNorm(one->data->data, one->data->vec_size) >
		oneNorm(two->data->data, two->data->vec_size))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printNode(nodeType *node)
{
	int n;
	printf("data size: %i \n", node->data->vec_size);
	printf("node data is: \n");
	for ( n = 0; n < node->data->vec_size; ++n )
			printf("%0.4lf, ", node->data->data[n]);
		printf("\n");
}

