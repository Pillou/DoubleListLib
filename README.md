# DoubleListLib
Simple double linked list implementation in C.

# Architecture

List 	FIRST						  LAST
         \/ 						   \/
NULL <- NODE-1 <-> NODE-2 <-> ... <-> NODE-n <-> NULL



# How to use

Create a list with

List *ListCreate(void);

Then add node with 

void ListAddFirst(List *list, void *data);
void ListAddLast(List *list, void *data);
void ListAddNext(List *list, ListNode *node, void *data);
void ListAddPrev(List *list, ListNode *node, void *data);

The user is responsible to handle the memory of the data contained in 
the nodes.
