
/*=====================================================\
 * stack.c
 *
 *   C implementation of the sack abstract data type
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
 
 
 #include <stdio.h>
 #include <node_data.h>


const int StackMaxSize = 8;   
nodeType * stack[StackMaxSize];        
int Stacktop = -1;    


/*
  Stack subroutines:
*/
int isStackempty();
int isStackfull();
nodeType * Stackpop();
int Stackpush(nodeType *node);
void Stacksizeadjust();