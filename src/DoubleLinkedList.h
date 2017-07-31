// TODO: add documentation
#ifndef __DOUBLE_LINKED_LIST__H__ 
#define __DOUBLE_LINKED_LIST__H__

#include <stdint.h>

typedef struct ListNode
{
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct
{
	int32_t count;
	ListNode first;
} List;

List *ListCreate(void);

ListNode *ListGetFirst(List *list);
ListNode *ListGetLast(List *list);
ListNode *ListGetNext(ListNode *node);
ListNode *ListGetPrev(ListNode *node);

void *ListGetValue(ListNode *node);


void ListAddNext(List *list, void *value);
void ListAddPrev(List *list, void *value);

void *ListRemove(ListNode *node);

ListNode *ListFindNode(List *list, int (*compare)(void *v1, void *v2), void *value);

void ListErase(List *list);

#endif // __DOUBLE_LINKED_LIST__H__
