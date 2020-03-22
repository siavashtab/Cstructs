## Cstruct
A C implementation of some useful doubly linked list-based abstract data types

-----------

##Author: Siavash Tabrizian - stabrizian@smu.edu

-----------

In all data structures there is a node object 
which contains the main data that have to be stored.
For different purposes you can modify this  - based on the data that you want to store - 
in order to use these data structures.

-----------

List of data structures (I am completing this list gradually):

## 1- Stack

Stack is a collection of data in a LIFO (last in, first serve) format. 
It has two main functions:

- Push: for adding a new node to the collection

- Pop: removes and returns the top node from the collection

Example:

```c
if (!newStack())
{
printf("error!\n");
}
else
{
printf("done!\n");
}

double nodedat1[3] = { 1.0,3.0,6.0 };
double nodedat2[3] = { 1.5,3.2,6.4 };
double nodedat3[3] = { 1.3,3.3,6.3 };
double nodedat4[3] = { 1.2,3.2,6.2 };


dVector nodedat = &nodedat1;
nodeType* node1 = newNodeOrig(3, nodedat);
Stackpush(node1);

nodedat = &nodedat2;
nodeType* node2 = newNode(node1, nodedat);
Stackpush(node2);

nodedat = &nodedat3;
nodeType* node3 = newNode(node2, nodedat);
Stackpush(node3);

nodedat = &nodedat4;
nodeType* node4 = newNode(node3, nodedat);
StackpushDP(node4);

printNode(Stackpeek());
```
Output:

```
done!
Warning: Adjusting stack size!
data size: 3
node data is:
1.2000, 3.2000, 6.2000,
```
