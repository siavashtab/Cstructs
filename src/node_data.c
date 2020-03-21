
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
	dataType * data;

	if (!(data = (dataType *)mem_malloc(sizeof(dataType))))
		errMsg("allocation", "newNode", "dataType", 0);
	
	nodeType * new_node;
	
	if ( !(new_node = (nodeType *) mem_malloc(sizeof(nodeType))) )
			errMsg("allocation", "newNode", "new_node", 0);
	
	
	if( !(new_node->prevnode = (nodeType *) mem_malloc (sizeof(nodeType))))
			errMsg("allocation", "newNode", "previous node pointer", 0);
	new_node->prevnode = prev;
	
	
	if( !(new_node->nextnode = (nodeType *) mem_malloc (sizeof(nodeType))))
			errMsg("allocation", "newNode", "next node pointer", 0);
	prev->nextnode = new_node;
	
	
	if ( !(new_node->data = (dataType *)mem_malloc(sizeof(dataType))))
		errMsg("allocation", "new_node->data", "next node pointer", 0);
	new_node->data = data;
	
		
}



void printNode(nodeType *node)
{
	int n;
	
	printf("node data is: \n");
	for ( n = 1; n <= node->vec_size; n++ )
			printf("%4.6lf, ", node->data[n]);
		printf("\n");
}