

/*=====================================================\
 * stack.c
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
 
 
#include <stack.h>
 
int stacksize;
stacksize = INITIAL_StackSize;
nodeType** stack;
nodeType*  stackfirst;
int Stacktop = -1;

int newStack()
{
	if (!(stack = (nodeType**)arr_alloc(stacksize, nodeType*)))
	{
		errMsg("newStack()", "stack", "data allocation", 0);
		return 0;
	}
	else
	{
		return 1;
	}
}
 
 int isStackempty() {

   if(Stacktop == -1)
      return 1;
   else
      return 0;
}
   
int isStackfull() {

   if(Stacktop == stacksize)
      return 1;
   else
      return 0;
}

nodeType * Stackpeek() {
   return stack[Stacktop];
}

nodeType * Stackpop() {
	nodeType * node;

   if(!isStackempty()) {
	  free(stack[Stacktop]);
	  Stacktop = Stacktop - 1;
      return stack[Stacktop];
   } else {
	   errMsg("Stack", "Stackpop", "stack is empty", 0);
   }
}

int Stackpush(nodeType * node) {

   if(!isStackfull()) {
	   Stacktop = Stacktop + 1;
	   stack[Stacktop] = node;
	   return 1;
   } else {
	   errMsg("Stack", "Stackpush", "stack is empty", 0);
	   return 0;
   }
}

int StackpushOrig(nodeType * node) {

	if (!isStackfull()) {
		Stacktop = Stacktop + 1;
		stack[Stacktop] = node;
		stackfirst = node;
		return 1;
	}
	else {
		errMsg("Stack", "Stackpush", "stack is empty", 0);
		return 0;
	}
}

int StackpushDP(nodeType * node) {

	if (!isStackfull()) {
		Stackpush(node);
		return 1;
	}
	else {
		printf("Warning: Adjusting stack size!\n");
		realloc(stack, sizeof(stack) + 1);
		stacksize = stacksize + 1;
		Stacktop = Stacktop + 1;
		stack[Stacktop] = node;
		return 1;
	}
}


void freeStack()
{
	if (stack)
	{
		nodeType *next = stackfirst;
		int counter = 0;
		while (next)
		{
			nodeType *node = next;
			next = node->nextnode;
			if (node && counter <= Stacktop)
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

 
