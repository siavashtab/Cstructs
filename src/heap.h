
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
  HEAP subroutines:
*/

/*
   newStack is the heap  constructor 
*/
int newHeap();

/*
isStackempty checks if a heap is empty or not
*/
int isHeapempty();

/*
isStackfull checks if a heap is full of not based on the stacksize
*/
int isHeapfull();

/*
Stackpeek returns the top node of the heap
*/
nodeType * Heappeek();

/*
Stackpop returns the top node of the heap and remove it from the heap
*/
nodeType * Heappop();

/*
insert a new node to the heap without changing the size of the heap
*/
int Heappush(nodeType *node);

/*
return the left child
*/
int HeapLeft(int parent);

/*
return the right child
*/
int HeapRight(int parent);

/*
return the parent
*/
int HeapParent(int child);

/*
return the left child node
*/
int HeapLeftNode(int parent);

/*
return the right child
*/
int HeapRightNode(int parent);

/*
return the parent
*/
int HeapParentNode(int child);

/*
Heapify the heap from down to top (when new index inserted)
*/
void HeapifyUp(int index);

/*
Heapify the heap from up to down (when an index removed)
*/
void HeapifyDown(int index);



/*
insert a new node to the heap in a predefined posititon (int pos)
*/
int Heapinsert(nodeType *node, int pos);

/*
insert a new node to the heap with dynamically adjucting the size of the heap
*/
int HeappushDP(nodeType *node);

/*
free the memory of the heap
*/
void freeHeap();

#endif /* heap_H_ */