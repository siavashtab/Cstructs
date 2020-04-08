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

## 2- Binary Min-Heap

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

freeHeap();

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

-------

## 2- Decision Tree

A simple implementation of desicion trees:

- Push: for adding a new node to the tree with a probability

- ExpectUp: Taking the expectation of the tree

Example:

```c
if (!newDtree())
{
	printf("error!\n");
}
else
{
	printf("done!\n");
}

double nodedat1[3] = { 0.0,0.0,0.0 };
double nodedat2[3] = { 0.0,0.0,0.0 };
double nodedat3[3] = { 1.3,3.3,5.3 };
double nodedat4[3] = { 1.2,3.2,3.2 };
double nodedat5[3] = { 1.1,3.01,10.2 };


nodeType* node1 = newNodeOrig(3, nodedat1);
node1->probability = 1.0;
DtreepushOrig(node1);
printf("Node%i: EV: %fl - Prob: %fl - Return: %fl \n", node1->index,DtreeEVnode(0),node1->probability,NodeReturn(node1));

nodeType* node2 = newNode(node1, nodedat2);
node2->probability = 0.4;
Dtreepush(node2);
printf("Node%i: EV: %fl - Prev: %i - Prob: %fl - Return: %fl \n", node2->index, DtreeEVnode(1), node2->prevnode->index, node2->probability, NodeReturn(node2));

nodeType* node3 = newNode(node1, nodedat3);
node3->probability = 0.6;
Dtreepush(node3);
printf("Node%i: EV: %fl - Prev: %i - Prob: %fl - Return: %fl \n", node3->index, DtreeEVnode(2), node3->prevnode->index, node3->probability, NodeReturn(node3));

nodeType* node4 = newNode(node2, nodedat4);
node4->probability = 0.3;
Dtreepush(node4);
printf("Node%i: EV: %fl - Prev: %i - Prob: %fl - Return: %fl \n", node4->index, DtreeEVnode(3), node4->prevnode->index, node4->probability, NodeReturn(node4));

nodeType* node5 = newNode(node2, nodedat5);
node5->probability = 0.7;
Dtreepush(node5);
printf("Node%i: EV: %fl - Prev: %i - Prob: %fl - Return: %fl \n", node5->index, DtreeEVnode(4), node5->prevnode->index, node5->probability, NodeReturn(node5));
ExpectUp(node5->index);
printf("Tree: EV: %fl \n", DtreeEV());

printf("finished! \n");

```
Output:

```
done!
Node0: EV: 0.000000l - Prob: 1.000000l - Return: 0.000000l
Node1: EV: 0.000000l - Prev: 0 - Prob: 0.400000l - Return: 0.000000l
Node2: EV: 5.940000l - Prev: 0 - Prob: 0.600000l - Return: 9.900000l
Node3: EV: 2.280000l - Prev: 1 - Prob: 0.300000l - Return: 7.600000l
Node4: EV: 10.017000l - Prev: 1 - Prob: 0.700000l - Return: 14.310000l
Tree: EV: 10.858800l
finished!
```

-------
## Useful References:
1 - C Programming: Advanced: https://faculty.washington.edu/jstraub/advc/index.html

2 - C Programming: Data Structures and Algorithms: https://faculty.washington.edu/jstraub/dsa/index.html

3 - Notes on Data Structures and Programming Techniques: http://cs.yale.edu/homes/aspnes/classes/223/notes.pdf

1 - A C++ implementation of heap with integer data types: https://www.tutorialspoint.com/cplusplus-program-to-implement-binary-heap
