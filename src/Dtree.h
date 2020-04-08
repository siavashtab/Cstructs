
/*=====================================================\
* stack.h
*
*   C implementation of the decision tree abstract data type
*          using doubly linked list
*
*
*
*
*
*
*
*  Created on: April 7, 2020
*      Author: Siavash Tabrizian
*=====================================================*/
 
#ifndef DTREE_H_
#define DTREE_H_
 
#include <stdio.h>
#include <node_data.h>

#define INITIAL_DtreeSize 5
 


/*
  Dtree subroutines:
*/

/*
   newDtree is the dtree  constructor 
*/
int newDtree();

/*
isDtreeempty checks if a stack is empty or not
*/
int isDtreeempty();

/*
isDtreefull checks if a dtree is full of not based on the dtreesize
*/
int isDtreefull();

/*
Dtreepeek returns the top node of the dtree
*/
nodeType * Dtreepeek();

/*
extract the EV of an input node
*/
double DtreeEVnode(int index);

/*
extract the EV of the tree
*/
double DtreeEV();

/*
Expected Cleaning Up
*/
void ExpectCleanUp(int index);

/*
Expected Up
*/
void ExpectUp(int index);


/*
insert a new node to the dtree without changing the size of the  dtree
*/
int Dtreepush(nodeType *node);

/*
insert a new node to the dtree with dynamically adjucting the size of the dtree
*/
int DtreepushDP(nodeType *node);

/*
free Dtree memory
*/
void freeDtree();



#endif /* DTREE_H_ */