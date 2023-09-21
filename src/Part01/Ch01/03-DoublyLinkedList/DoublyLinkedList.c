//
// Created by ARA on 2023-09-22.
//

#include "DoublyLinkedList.h"


Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Pointer = *(Head);

		while (Pointer->NextNode != NULL)
		{
			Pointer = Pointer->NextNode;
		}

		Pointer->NextNode = NewNode;
		NewNode->PrevNode = Pointer;
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		if (*Head == NULL)
		{
			return;
		}

		if (Remove->NextNode != NULL) {
			Remove->NextNode->PrevNode = NULL;
		}

		*Head = Remove->NextNode;

		Remove->NextNode = NULL;
//		DLL_DestroyNode(Remove);
	}
	else
	{
		Node* Pointer = *Head;

		while (Pointer->NextNode != Remove)
		{
			Pointer = Pointer->NextNode;
		}

		Remove->NextNode->PrevNode = Pointer;
		Pointer->NextNode = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;

//		DLL_DestroyNode(Remove);
	}
}

Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Pointer = Head;

	while (Pointer != NULL && (Location--) > 0)
	{
		Pointer = Pointer->NextNode;
	}

	return Pointer;
}

int DLL_GetNodeCount(Node* Head)
{
	unsigned int count = 0;
	Node* Pointer = Head;

	while (Pointer != NULL) {
		count++;
		Pointer = Pointer->NextNode;
	}

	return count;
}

void PrintReverse(Node* Head)
{
	Node* Pointer = Head;

	while (Pointer->NextNode != NULL)
	{
		Pointer = Pointer->NextNode;
	}

	printf("Print Nodes Reverse\n");
	int Count = DLL_GetNodeCount(Head);
	do {
		printf("List[%d] : %d\n", --Count, Pointer->Data);
		Pointer = Pointer->PrevNode;
	} while (Pointer != NULL);
}