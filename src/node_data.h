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
 
 
#ifndef NODE_DATA_H_
#define NODE_DATA_H_
 
 /*
	nodeType is the main data structure that is going to be stored in each abstract formats
	such as stack, queue, etc. 
	It can contain different data formats, but the important feature of our design is that it contains pointers
	to the previous entry and next entry.
 */
 typedef struct{
	dVector  data;
	int      vec_size;
	
	nodeType * prevnode;
	nodeType * nextnode;
}nodeType;


/* subroutines in node_data.c */
nodeType *newNode(nodeType *prev, dVector nodedat);
void printNode(nodeType *node)


#endif /* node_data_H_ */