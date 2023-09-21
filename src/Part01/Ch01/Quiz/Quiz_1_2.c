//
// Created by ARA on 2023-09-21.
//
#include "../02-LinkedList/LinkedList.h"

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
		Pointer->NextNode = Current;
	}
}