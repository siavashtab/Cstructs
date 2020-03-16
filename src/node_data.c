
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


nodeType *newNode(nodeType *prev, dVector nodedat)
{
	nodeType * new_node;
	
	if ( !(new_node = (nodeType *) mem_malloc(sizeof(nodeType))) )
			errMsg("allocation", "newNode", "new_node", 0);
	
	
	if( !(new_node->prevnode = (nodeType *) mem_malloc (sizeof(nodeType))))
			errMsg("allocation", "newNode", "previous node pointer", 0);
	new_node->prevnode = prev;
	
	
	if( !(new_node->nextnode = (nodeType *) mem_malloc (sizeof(nodeType))))
			errMsg("allocation", "newNode", "next node pointer", 0);
	prev->nextnode = new_node;
	
	
	if ( !(new_node->data = (dVector) arr_alloc(prev->vec_size, double)) )
			errMsg("allocation", "newNode", "data allocation", 0);
	new_node->data = nodedat;
	
		
}



void printNode(nodeType *node)
{
	int n;
	
	printf("node data is: \n");
	for ( n = 1; n <= node->vec_size; n++ )
			printf("%4.6lf, ", node->data[n]);
		printf("\n");
}