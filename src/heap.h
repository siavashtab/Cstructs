
/*=====================================================\
* heap.h
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
 
#ifndef HEAP_H_
#define HEAP_H_
 
#include <stdio.h>
#include <node_data.h>

#define INITIAL_HeapSize 3
 


/*
  Stack subroutines:
*/

/*
   newStack is the stack  constructor 
*/
int newHeap();

/*
isStackempty checks if a stack is empty or not
*/
int isHeapempty();

/*
isStackfull checks if a stack is full of not based on the stacksize
*/
int isHeapfull();

/*
Stackpeek returns the top node of the stack
*/
nodeType * Heappeek();

/*
Stackpop returns the top node of the stack and remove it from the stack
*/
nodeType * Heappop();

/*
insert a new node to the stack without changing the size of the stack
*/
int Heappush(nodeType *node);

/*
insert a new node to the stack with dynamically adjucting the size of the stack
*/
int HeappushDP(nodeType *node);



#endif /* heap_H_ */