#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <assert.h>


List *ListCreate(void)
{
	List *list = malloc(sizeof(*list));
	assert(list != NULL);
	
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
	
	return list;
}

void ListAddLast(List *list, void *data)
{
	ListNode *nextNode = malloc(sizeof(*nextNode));
	nextNode->data = data;
	
	if(list->last == NULL || list->first == NULL)
	{
		assert(list->count == 0);
		list->first = nextNode;
		list->last = nextNode;
		nextNode->prev = NULL;
		nextNode->next = NULL;
	}
	else
	{
		assert(list->count != 0);
		nextNode->prev = list->last;
		nextNode->next = NULL;
	
		list->last->next = nextNode;
		list->first->prev = nextNode;
		list->last = nextNode;
	}
	list->count++;
}

ListNode *ListGetFirst(List *list)
{
	return list->first;
}

ListNode *ListGetLast(List *list)
{
	return list->last;
}

ListNode *ListGetNext(ListNode *node)
{
	return node->next;
}

ListNode *ListGetPrev(ListNode *node)
{
	return node->prev;
}

void *ListGetData(ListNode *node)
{
	return node->data;
}

