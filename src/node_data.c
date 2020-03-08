
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
 
 
#include <utils.h>
#include <node_data.h>


nodeType *newNode(nodeType *prev, nodeType *next, dVector nodedat)
{
	nodeType * new_node;
	
	if ( !(new_node = (nodeType *) mem_malloc(sizeof(nodeType))) )
			errMsg("allocation", "newNode", "new_node", 0);
	
	if( !(new_node->prevnode = (nodeType *) mem_malloc (sizeof(nodeType))))
			errMsg("allocation", "newNode", "previous node pointer", 0);
	
	if( !(new_node->nextnode = (nodeType *) mem_malloc (sizeof(nodeType))))
			errMsg("allocation", "newNode", "next node pointer", 0);
	
}