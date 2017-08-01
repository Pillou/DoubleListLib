/*
 * DoubleLinkedList.c
 * 
 * Copyright 2017 glc <guillaume.lecam@zoho.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <assert.h>



static void ListAddFirstNode(List *list, ListNode *node);
static ListNode* ListCreateNode(void *data);

/*
 * name: 	ListCreate
 * 			Create the list
 * @param	void
 * @return	List *		return pointer to the new List
 */
List *ListCreate(void)
{
	List *list = malloc(sizeof(*list));
	assert(list != NULL);
	
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
	
	return list;
}

/*
 * name: 	ListAddFirstNode
 * 			Add the first node to an empty list
 * @param	List *list		
 * @param	ListNode *node		
 * @return	void
 */
static void ListAddFirstNode(List *list, ListNode *node)
{
	assert(list->first == NULL);
	assert(list->last == NULL);
	assert(list->count == 0);
	
	list->first = node;
	list->last = node;
	node->prev = NULL;
	node->next = NULL;
	
	list->count++;
}

/*
 * name: ListCreateNode
 * Create a node with the value.
 * @param	void *data
 * @return	ListNode *
 * 
 */
static ListNode* ListCreateNode(void *data)
{
	ListNode *newNode = malloc(sizeof(*newNode));
	assert(newNode != NULL);
	newNode->data = data;
	return newNode;
}

/*
 * name: ListAddLast
 * Create a node with the value and add it a the last node of the list.
 * @param	List *list
 * @param	void *data
 * @return	void
 * 
 */
void ListAddLast(List *list, void *data)
{
	ListNode *nextNode = ListCreateNode(data);
	
	if(list->count == 0)
	{
		ListAddFirstNode(list, nextNode);
	}
	else
	{
		assert(list->count != 0);
		nextNode->prev = list->last;
		nextNode->next = NULL;
	
		list->last->next = nextNode;
		list->last = nextNode;
		list->count++;
	}
}

/*
 * name: ListAddFirst
 * Create a node with the value and add it a the first node of the list.
 * @param	ListNode *node
 * @param	void *value	
 * @return	void
 */
void ListAddFirst(List *list, void *data)
{
	ListNode *nextNode = ListCreateNode(data);
	
	if(list->count == 0)
	{
		ListAddFirstNode(list, nextNode);
	}
	else
	{
		assert(list->count != 0);
		nextNode->prev = NULL;
		nextNode->next = list->first;
	
		list->first->prev = nextNode;
		list->first = nextNode;
		
		list->count++;	//TODO: (glc) add check max number
	}
}

/*
 * name: ListAddNext
 * Create a node with the value and add it a the next node.
 * @param	List *list
 * @param	ListNode *node
 * @param	void *data	
 * @return	void
 */
void ListAddNext(List *list, ListNode *node, void *data)
{
	if(node == list->last)
	{
		assert(node->next == NULL);
		ListAddLast(list, data);
	}
	else
	{
		ListNode *nextNode = ListCreateNode(data);
		nextNode->next = node->next;
		nextNode->prev = node;
		node->next = nextNode;
		list->count++;
	}
}

/*
 * name: ListAddPrev
 * Create a node with the value and add it a the previous node.
 * @param	List *list
 * @param	ListNode *node
 * @param	void *data	
 * @return	void
 */
void ListAddPrev(List *list, ListNode *node, void *data)
{
	if(node == list->first)
	{
		assert(node->prev == NULL);
		ListAddFirst(list, data);
	}
	else
	{
		ListNode *nextNode = ListCreateNode(data);
		nextNode->prev = node->prev;
		nextNode->next = node;
		node->prev = nextNode;
		list->count++;
	}
}

/*
 * name: ListGetFirst
 * @param	List *list
 * @return	ListNode *	return a pointer to the first node of the list
 */
ListNode *ListGetFirst(List *list)
{
	return list->first;
}

/*
 * name: ListGetLast
 * @param	List *list
 * @return	ListNode *	return a pointer to the last node of the list
 */
ListNode *ListGetLast(List *list)
{
	return list->last;
}

/*
 * name: ListGetNext
 * @param	ListNode *node
 * @return	ListNode *		return a pointer to the next node
 */
ListNode *ListGetNext(ListNode *node)
{
	return node->next;
}

/*
 * name: ListGetPrev
 * @param	ListNode *node
 * @return	ListNode *		return a pointer to the previous node
 */
ListNode *ListGetPrev(ListNode *node)
{
	return node->prev;
}

/*
 * name: ListGetData
 * @param	ListNode *node
 * @return	void *				pointer to the data of the node
 */
void *ListGetData(ListNode *node)
{
	return node->data;
}

/*
 * name: ListGetCount
 * @param	List *list
 * @return	uint32_t	number of element in the list
 */
uint32_t ListGetCount(List *list)
{
	return list->count;
}

/*
 * name: ListFindNode
 * @param	List *list
 * @param	int (*compare)(void *d1, void *d2)		function return 0 if equal
 * @param	void *data	data used for comparison
 * @return	ListNode *	return NULL if not found, else pointer on the node
 */
ListNode *ListFindNode(List *list, int (*compare)(void *d1, void *d2), void *data)
{
	ListNode *node = ListGetFirst(list);
	while(node != NULL)
	{
		if((*compare)(data, ListGetData(node)) == 0)
		{
			break;
		}
		node = ListGetNext(node);
	}
	return node;
}
