

/*=====================================================\
 * heap.c
 *
 *   C implementation of the binary heap abstract data type
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
		errMsg("newHeap()", "heap", "data allocation", 0);
		return 0;
	}
	else
	{
		return 1;
	}
}
 
int HeapLeft(int parent)
{
	int left = 2 * parent + 1;
	if (left < heapsize)
	{
		return left;
	}
	else
	{
		errMsg("HeapLeft", "heap", "Return left child", 0);
		return -1;
	}
}


int HeapRight(int parent)
{
	int right = 2 * parent + 2;
	if (right < heapsize)
	{
		return right;
	}
	else
	{
		errMsg("HeapRight", "heap", "Return right child", 0);
		return -1;
	}
}

int HeapParent(int child)
{
	if (child == 0)
	{
		errMsg("HeapParent", "heap", "the asked child is the root node (doesn't have parent)!", 0);
		return -1;
	}
	else
	{
		int parent = (child - 1) / 2;
		return parent;
	}
}

int HeapLeftNode(int parent)
{
	return heap[HeapLeft(parent)];
}

int HeapRightNode(int parent)
{
	return heap[HeapRight(parent)];
}

int HeapParentNode(int child)
{
	return heap[HeapParent(child)];
}

int isHeapempty() 
{

   if(Heaptop == -1)
      return 1;
   else
      return 0;
}
   
int isHeapfull() 
{

   if(Heaptop == heapsize)
      return 1;
   else
      return 0;
}

nodeType * Heappeek() 
{
   return heap[Heaptop];
}

nodeType * Heappop() 
{
	nodeType * node;

   if(!isStackempty()) {
	  node = newNode(heap[Heaptop], heap[Heaptop]->data);
	  Heaptop = Heaptop - 1;
      return node;
   } else {
	   errMsg("Heap", "Heappop", "heap is empty", 0);
   }
}

void HeapifyUp(int index)
{
	if (index >= 0 && HeapParent(index) >=0 &&
		OneGreater2(heap[HeapParent(index)], heap[index]))
	{
		nodeType * temp = heap[index];
		heap[index] = heap[HeapParent(index)];
		heap[HeapParent(index)] = temp;
		if (index > 0) heap[index]->prevnode = heap[index - 1];
		if(index < heapsize) heap[index]->nextnode = heap[index + 1];
		if (HeapParent(index) > 0) heap[HeapParent(index)]->prevnode = heap[HeapParent(index) - 1];
		if (HeapParent(index) < heapsize) heap[HeapParent(index)]->nextnode = heap[HeapParent(index) + 1];
		HeapifyUp(HeapParent(index));
	}
}

void HeapifyDown(int index)
{
	int left = HeapLeft(index);
	int right = HeapRight(index);

	if (left >= 0 && right >= 0 && OneGreater2(heap[left],heap[right]))
	{
		left = right;
	}

	if (left >=0 && OneGreater2(index, heap[left]))
	{
		nodeType * temp = heap[index];
		heap[index] = heap[left];
		heap[left] = temp;
		if (index > 0) heap[index]->prevnode = heap[index - 1];
		if (index < heapsize) heap[index]->nextnode = heap[index + 1];
		if (left > 0) heap[left]->prevnode = heap[left - 1];
		if (left < heapsize) heap[left]->nextnode = heap[left + 1];
		HeapifyUp(left);
	}
}

int Heappush(nodeType * node) 
{

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
	   errMsg("Heap", "Heappush", "heap is empty", 0);
	   return 0;
   }
}

int HeappushDP(nodeType * node) 
{

	if (!isHeapfull()) 
	{
		Heappush(node);
		return 1;
	}
	else 
	{
		printf("Warning: Adjusting stack size!\n");
		realloc(heap, sizeof(heap) + 1);
		Heappush(node);
		return 1;
	}
}

void HeapPrint()
{
	for (int h = 0; h < heapsize; h++)
	{
		printf("idx:%i - Norm:%d - Left: %i Right:%i - Parent:%i \n", h, NodeNorm(heap[h]),
			HeapLeft(h), HeapRight(h), HeapParent(h));
	}
}

void freeHeap()
{
	if (heap)
	{
		nodeType *next = heapfirst;
		int counter = 0;
		while (next)
		{
			nodeType *node = next;
			next = node->nextnode;
			if (node && counter <= Heaptop)
			{
				free(node->data);
				free(node);
			}
			else
			{
				break;
			}
			counter += 1;
		}

	}
}

 
