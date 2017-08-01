#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void)
{
	printf("Start testing DoubleLinkedList...\n");
	
	List *l1 = ListCreate();
	char * t1[] = {"a", "b", "c", "d"};
	for(int i=0; i<sizeof(t1)/sizeof(t1[0]); i++)
	{
		ListAddLast(l1, t1[i]);
	}
	
	ListNode *node = ListGetFirst(l1);
	for(int i=0; node != NULL; i++)
	{
		printf("%s\n", (char*)ListGetData(node));
		assert(strcmp(t1[i], ListGetData(node)) == 0);
		node = ListGetNext(node);
	}
	// TODO: add tests
	return 0;
}
