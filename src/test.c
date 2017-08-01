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

	List *l1 = ListCreate();
	assert(ListGetCount(l1) == 0);
	char * t1[] = {"a", "b", "c", "d"};
	const int t1_size = sizeof(t1)/sizeof(t1[0]);
	for(int i=0; i<t1_size; i++)
	{
		ListAddLast(l1, t1[i]);
		assert(ListGetCount(l1) == i+1);
	}

	ListNode *node = ListGetFirst(l1);
	for(int i=0; node != NULL; i++)
	{
		printf("%s\n", (char*)ListGetData(node));
		assert(strcmp(t1[i], ListGetData(node)) == 0);
		node = ListGetNext(node);
	}
	
	assert(strcmp(t1[t1_size-1], ListGetData(ListGetLast(l1))) == 0);
	assert(ListFindNode(l1, &compareData, "a") != NULL);
	assert(ListFindNode(l1, &compareData, "1") == NULL);
	
	// TODO:(glc) add tests for each function
	
	printf("Success!\n");
	return 0;
}
