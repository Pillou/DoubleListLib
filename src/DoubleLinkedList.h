/*
 * DoubleLinkedList.h
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

#ifndef __DOUBLE_LINKED_LIST__H__ 
#define __DOUBLE_LINKED_LIST__H__

#include <stdint.h>

typedef struct ListNode
{
	struct ListNode *next;
	struct ListNode *prev;
	void *data;
} ListNode;

typedef struct
{
	uint32_t count;
	ListNode *first;
	ListNode *last;
} List;

List *ListCreate(void);

ListNode *ListGetFirst(List *list);
ListNode *ListGetLast(List *list);
ListNode *ListGetNext(ListNode *node);
ListNode *ListGetPrev(ListNode *node);

void *ListGetData(ListNode *node);
uint32_t ListGetCount(List *list);

void ListAddFirst(List *list, void *data);
void ListAddLast(List *list, void *data);
void ListAddNext(List *list, ListNode *node, void *data);
void ListAddPrev(List *list, ListNode *node, void *data);

ListNode *ListFindNode(List *list, int (*compare)(void *v1, void *v2), void *value);

void ListRemoveNode(List *list, ListNode *node);
void ListDelete(List *list);

#endif // __DOUBLE_LINKED_LIST__H__
