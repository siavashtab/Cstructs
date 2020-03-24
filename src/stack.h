
/*=====================================================\
* stack.h
*
*   C implementation of the sack abstract data type
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
 
#ifndef STACK_H_
#define STACK_H_
 
#include <stdio.h>
#include <node_data.h>

#define INITIAL_StackSize 3
 


/*
  Stack subroutines:
*/

/*
   newStack is the stack  constructor 
*/
int newStack();

/*
isStackempty checks if a stack is empty or not
*/
int isStackempty();

/*
isStackfull checks if a stack is full of not based on the stacksize
*/
int isStackfull();

/*
Stackpeek returns the top node of the stack
*/
nodeType * Stackpeek();

/*
Stackpop returns the top node of the stack and remove it from the stack
*/
nodeType * Stackpop();

/*
insert a new node to the stack without changing the size of the stack
*/
int Stackpush(nodeType *node);

/*
insert a new node to the stack with dynamically adjucting the size of the stack
*/
int StackpushDP(nodeType *node);

/*
free Stack memory
*/
void freeStack();



#endif /* stack_H_ */