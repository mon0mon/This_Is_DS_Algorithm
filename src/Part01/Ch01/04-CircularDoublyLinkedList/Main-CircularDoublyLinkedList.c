//
// Created by ARA on 2023-09-23.
//

#include "CircularDoublyLinkedList.h"

int main()
{
	int count = 0;
	Node* list = NULL;
	Node* new_node = NULL;
	Node* current = NULL;

	for (int i = 0; i < 5; ++i)
	{
		new_node = CDLL_CreateNode(i);
		CDLL_AppendNode(&list, new_node);
	}

	count = CDLL_GetNodeCount(list);
	for (int i = 0; i < count; ++i)
	{
		current = CDLL_GetNodeAt(list, i);
		printf("List[%d] : %d\n", i, current->data);
	}

	printf("\nInserting 3000 After [2]...\n\n");

	current = CDLL_GetNodeAt(list, 2);
	new_node = CDLL_CreateNode(3000);
	CDLL_InsertAfter(current, new_node);

	for (int i = 0; i < count; ++i)
	{
		if (i == 0)
		{
			current = list;
		}
		else
		{
			current = current->next_node;
		}

		printf("List[%d] : %d\n", i, current->data);
	}

	printf("\nRemoving Node at 2...\n");
	current = CDLL_GetNodeAt(list, 2);
	CDLL_RemoveNode(&list, current);
	CDLL_DestroyNode(current);

	count = CDLL_GetNodeCount(list);
	for (int i = 0; i < count * 2; ++i)
	{
		if (i == 0)
		{
			current = list;
		}
		else
		{
			current = current->next_node;
		}

		printf("List[%d] : %d\n", i, current->data);
	}

	printf("\nDestroying List...\n");
	count = CDLL_GetNodeCount(list);

	for (int i = 0; i < count; ++i) {
		current = CDLL_GetNodeAt(list, 0);

		if (current != NULL) {
			CDLL_RemoveNode(&list, current);
			CDLL_DestroyNode(current);
		}
	}

	return 0;
}