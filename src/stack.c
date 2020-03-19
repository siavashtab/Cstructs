

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
	  node = newNode(stack[Stacktop], stack[Stacktop]->data);
	  Stacktop = Stacktop - 1;
      return node;
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
	   errMsg("Stack", "Stackpop", "stack is empty", 0);
	   return 0;
   }
}


#define INITIAL_CAPACITY 3

void push(int *arr, int index, int value, int *size, int *capacity){
     if(*size > *capacity){
          realloc(arr, sizeof(arr) * 2);
          *capacity = sizeof(arr) * 2;
     }
     
     arr[index] = value;
     *size = *size + 1;
}


 