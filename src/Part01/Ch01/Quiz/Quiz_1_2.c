//
// Created by ARA on 2023-09-21.
//
#include "../02-LinkedList/LinkedList.h"

/*
 * VITAMIN QUIZ 1-2
 * void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead) 구현
 * void SLL_DestroyAllNodes(Node** List); 구현
 */

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
	if (*Head == NULL)
	{
		*Head = NewHead;
	}
	else
	{
		Node* Pointer = (*Head);
		while (Pointer->NextNode != NULL && Pointer->NextNode != Current) {
			Pointer = Pointer->NextNode;
		}

		NewHead->NextNode = Pointer->NextNode;
		Pointer->NextNode = NewHead;
	}
}

void SLL_DestroyAllNodes(Node** List) {
	Node* Head = *List;
	Node* Prev = NULL;

	do {
		Prev = Head;
		Head = Head->NextNode;
		free(Prev);
	}
	while (Head != NULL);

	*List = NULL;
}