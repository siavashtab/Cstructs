

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

int Stackpop() {
	nodeType * node;

   if(!isStackempty()) {
	  node = newNode(nodeType *prev, dVector nodedat);
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
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


 