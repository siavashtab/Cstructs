

/*=====================================================\
 * stack.c
 *
 *   C implementation of the decision tree data type
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
 
 
#include <Dtree.h>
 
int Dtreesize;
dtreesize = INITIAL_DtreeSize;
nodeType** dtree;
nodeType*  dtreefirst;
int Dtreetop = -1;

int newDtree()
{
	if (!(dtree = (nodeType**)arr_alloc(dtreesize, nodeType*)))
	{
		errMsg("newDtree()", "dtree", "data allocation", 0);
		return 0;
	}
	else
	{
		return 1;
	}
}
 
 int isDtreeempty() {

   if(Dtreetop == -1)
      return 1;
   else
      return 0;
}
   
int isDtreefull() {

   if(Dtreetop == dtreesize)
      return 1;
   else
      return 0;
}

nodeType * Dtreepeek() {
   return dtree[Dtreetop];
}

double DtreeEVnode(int index)
{
	return dtree[index]->EV;
}

double DtreeEV()
{
	return dtreefirst->EV;
}


void ExpectUp(int index)
{
	if (index > 0)
	{
		dtree[index]->prevnode->EV = dtree[index]->prevnode->EV + dtree[index]->prevnode->probability * dtree[index]->EV;
		ExpectUp(index - 1);
	}
}


int Dtreepush(nodeType * node) {

   if(!isDtreefull()) {
	   Dtreetop = Dtreetop + 1;
	   node->index = Dtreetop;
	   node->EV = node->probability * NodeReturn(node);
	   dtree[Dtreetop] = node;
	   return 1;
   } else {
	   errMsg("Dtree", "Dtreepush", "dtree is empty", 0);
	   return 0;
   }
}

int DtreepushOrig(nodeType * node) {

	if (!isDtreefull()) {
		Dtreetop = Dtreetop + 1;
		node->index = Dtreetop;
		node->EV = node->probability * NodeReturn(node);
		dtree[Dtreetop] = node;
		dtreefirst = node;
		return 1;
	}
	else {
		errMsg("Dtree", "Dtreepush", "dtree is empty", 0);
		return 0;
	}
}

int DtreepushDP(nodeType * node) {

	if (!isDtreefull()) {
		Dtreepush(node);
		return 1;
	}
	else {
		printf("Warning: Adjusting Dtree size!\n");
		realloc(dtree, sizeof(dtree) + 1);
		dtreesize = dtreesize + 1;
		Dtreetop = Dtreetop + 1;
		dtree[Dtreetop] = node;
		return 1;
	}
}


void freeDtree()
{
	if (dtree)
	{
		nodeType *next = dtreefirst;
		int counter = 0;
		while (next)
		{
			nodeType *node = next;
			next = node->nextnode;
			if (node && counter <= Dtreetop)
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

 
