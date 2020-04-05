

/*=====================================================\
 * heap.c
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
 
 
#include <heap.h>
 
int heapsize;
heapsize = INITIAL_HeapSize;
nodeType** heap;
nodeType*  heapfirst;
int Heaptop = -1;

int newHeap()
{
	if (!(heap = (nodeType**)arr_alloc(heapsize, nodeType*)))
	{
		errMsg("newStack()", "stack", "data allocation", 0);
		return 0;
	}
	else
	{
		return 1;
	}
}
 
 int isHeapempty() {

   if(Heaptop == -1)
      return 1;
   else
      return 0;
}
   
int isHeapfull() {

   if(Heaptop == heapsize)
      return 1;
   else
      return 0;
}

nodeType * Heappeek() {
   return heap[Heaptop];
}

nodeType * Heappop() {
	nodeType * node;

   if(!isStackempty()) {
	  node = newNode(heap[Heaptop], heap[Heaptop]->data);
	  Heaptop = Heaptop - 1;
      return node;
   } else {
	   errMsg("Stack", "Stackpop", "stack is empty", 0);
   }
}

int Heappush(nodeType * node) {

   if(!isHeapfull()) {
	   for (int i = 0; i < heapsize; i++)
	   {
		   if (OneGreater2(heap[i],node))
		   {
			   // shift elements forward 
			   for (int j = heapsize; j >= i; j--)
				   heap[j] = heap[j - 1];
			   Heaptop = Heaptop + 1;
			   heap[i] = node;
			   if (i == 0)
				   heapfirst = node;
			   break;
		   }
	   }
	   return 1;
   } else {
	   errMsg("Stack", "Stackpush", "stack is empty", 0);
	   return 0;
   }
}

int HeappushDP(nodeType * node) {

	if (!isHeapfull()) {
		Heappush(node);
		return 1;
	}
	else {
		printf("Warning: Adjusting stack size!\n");
		realloc(heap, sizeof(heap) + 1);
		heapsize = heapsize + 1;
		Heaptop = Heaptop + 1;
		heap[Heaptop] = node;
		return 1;
	}
}




 
