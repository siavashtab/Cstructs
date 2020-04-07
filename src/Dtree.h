
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
*  Created on: March 8, 2020
*      Author: Siavash Tabrizian
*=====================================================*/
 
#ifndef DTREE_H_
#define DTREE_H_
 
#include <stdio.h>
#include <node_data.h>

#define INITIAL_StackSize 3
 


/*
  Stack subroutines:
*/

/*
   newStack is the stack  constructor 
*/
int newDtree();

/*
isStackempty checks if a stack is empty or not
*/
int isDtreeempty();

/*
isStackfull checks if a stack is full of not based on the stacksize
*/
int isDtreefull();

/*
Stackpeek returns the top node of the stack
*/
nodeType * Dtreepeek();

/*
Stackpop returns the top node of the stack and remove it from the stack
*/
nodeType * Dtreepop();

/*
insert a new node to the stack without changing the size of the stack
*/
int Dtreepush(nodeType *node);

/*
insert a new node to the stack with dynamically adjucting the size of the stack
*/
int DtreepushDP(nodeType *node);

/*
free Stack memory
*/
void freeDtree();



#endif /* DTREE_H_ */