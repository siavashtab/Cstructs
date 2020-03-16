
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

#define INITIAL_StackSize 8
int stacksize = INITIAL_StackSize;
nodeType * stack[INITIAL_StackSize];
int Stacktop = -1;    


/*
  Stack subroutines:
*/
int isStackempty();
int isStackfull();
nodeType * Stackpop();
int Stackpush(nodeType *node);
void Stacksizeadjust();



#endif /* stack_H_ */