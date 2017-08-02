/*
 * test.c
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
#include <stdio.h>
#include <string.h>
#include <assert.h>

static int compareData(void *d1, void *d2)
{
	return strcmp(d1, d2);
}

int main(void)
{
	printf("Start testing DoubleLinkedList...\n");

	printf("Create list.\n");
	List *l1 = ListCreate();
	
	printf("Check list has 0 element.\n");
	assert(ListGetCount(l1) == 0);
	
	char * t1[] = {"a", "b", "c", "d","element1", "element2"};
	const int t1_size = sizeof(t1)/sizeof(t1[0]);
	
	
	for(int i=0; i<t1_size; i++)
	{
		printf("Add as last node : %s.\n", t1[i]);
		ListAddLast(l1, t1[i]);
		assert(ListGetCount(l1) == i+1);
	}

	printf("Check nb node %d == nb elements %d.\n", ListGetCount(l1), t1_size);
	assert(ListGetCount(l1) == t1_size);

	printf("\nCheck list parsing from first to last:\n");
	ListNode *node = ListGetFirst(l1);
	for(int i=0; node != NULL; i++)
	{
		printf("Check element %d data : %s.\n", i, (char*)ListGetData(node));
		assert(strcmp(t1[i], ListGetData(node)) == 0);
		node = ListGetNext(node);
	}
	
	printf("\nCheck list parsing from last to first:\n");
	node = ListGetLast(l1);
	for(int i=t1_size-1; node != NULL; i--)
	{
		printf("Check element %d data : %s.\n", i, (char*)ListGetData(node));
		assert(strcmp(t1[i], ListGetData(node)) == 0);
		node = ListGetPrev(node);
	}
	
	printf("\nCheck seach functionality...\n");
	for(int i=0; i<t1_size; i++)
	{
		assert(ListFindNode(l1, &compareData, t1[i]) != NULL);
	}
	assert(ListFindNode(l1, &compareData, "1") == NULL);
	
	int32_t count = ListGetCount(l1);
	
	char * new_first_elt = "elementFirst";
	printf("\nAdd new element as first: %s\n", new_first_elt);
	ListAddFirst(l1, new_first_elt);
	assert(strcmp(ListGetData(ListGetFirst(l1)), new_first_elt) == 0);
	assert(ListGetCount(l1) == ++count);
	
	char * new_second_elt = "elementSecond";
	printf("Add new element as second: %s\n", new_second_elt);
	node = ListGetFirst(l1);
	ListAddNext(l1, node, new_second_elt);
	node = ListGetNext(node);
	assert(strcmp(ListGetData(node), new_second_elt) == 0);
	assert(ListGetCount(l1) == ++count);
	
	char * new_before_last = "elementBeforeLast";
	printf("Add new element before last: %s\n", new_before_last);
	node = ListGetLast(l1);
	ListAddPrev(l1, node, new_before_last);
	node = ListGetPrev(node);
	assert(strcmp(ListGetData(node), new_before_last) == 0);
	assert(ListGetCount(l1) == ++count);
	
	printf("\nPrint list from first to last:\n");
	node = ListGetFirst(l1);
	for(int i=0; node != NULL; i++)
	{
		printf("Check element %d data : %s.\n", i, (char*)ListGetData(node));
		node = ListGetNext(node);
	}
	
	printf("\nPrint list from last to fist:\n");
	node = ListGetLast(l1);
	for(int i=ListGetCount(l1)-1; node != NULL; i--)
	{
		printf("Check element %d data : %s.\n", i, (char*)ListGetData(node));
		node = ListGetPrev(node);
	}
	
	printf("\nDelete list.\n");
	ListDelete(l1);
	
	printf("Check with Valgrind that there is no memory leak.\n");
	
	printf("Success!\n");
	return 0;
}
