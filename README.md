## Cstruct
A C implementation of some useful doubly linked list-based abstract data types

-----------

## Author: Siavash Tabrizian - stabrizian@smu.edu

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

*All nodes will be added to the stack in a doubly linked-list format

Example:

```c
if (newStack() == 0)
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
double nodedat5[3] = { 1.1,3.01,6.2 };


nodeType* node1 = newNodeOrig(3, nodedat1);
StackpushOrig(node1);

nodeType* node2 = newNode(node1, nodedat2);
Stackpush(node2);

nodeType* node3 = newNode(node2, nodedat3);
Stackpush(node3);

nodeType* node4 = newNode(node3, nodedat4);
StackpushDP(node4);

nodeType* node5 = newNode(node4, nodedat5);
StackpushDP(node5);

printNode(Stackpop());
printNode(Stackpop());
printNode(Stackpop());
printNode(Stackpop());

freeStack();

```
Output:

```
done!
data size: 3
node data is:
1.2000, 3.2000, 6.2000,
```

-------

## 2- Binary Heap

Binary Heap is a collection of data sorted in a binary tree format. 
It has two main functions:

- Push: for adding a new node to the collection and heapify the heap from down to up

- Pop: removes and returns the top node from the collection and heapify the heap from up to down

*All nodes will be added to the binary heap in a doubly linked-list format (linked to neighbor nodes in the same level of the heap)

Example:

```c
if (!newHeap())
{
	printf("error!\n");
}
else
{
	printf("done!\n");
}

double nodedat1[3] = { 1.0,3.0,6.0 };
double nodedat2[3] = { 1.5,3.2,6.4 };
double nodedat3[3] = { 1.3,3.3,5.3 };
double nodedat4[3] = { 1.2,3.2,3.2 };
double nodedat5[3] = { 1.1,3.01,10.2 };


nodeType* node1 = newNodeOrig(3, nodedat1);
HeappushOrig(node1);

nodeType* node2 = newNode(node1, nodedat2);
Heappush(node2);

nodeType* node3 = newNode(node2, nodedat3);
Heappush(node3);

nodeType* node4 = newNode(node3, nodedat4);
Heappush(node4);

HeapPrint();

```
Output:

```
done!
the asked child is the root node(doesn't have parent)!
the asked child is the root node(doesn't have parent)!
the asked child is the root node(doesn't have parent)!
idx:0 - Norm:7.600000l - Left: 1 Right:2 - Parent:-1
there is no right child!
idx:1 - Norm:9.900000l - Left: 3 Right:-1 - Parent:0
there is no right child!
there is no left child!
idx:2 - Norm:10.000000l - Left: -1 Right:-1 - Parent:0
there is no right child!
there is no left child!
idx:3 - Norm:11.100000l - Left: -1 Right:-1 - Parent:1
```
