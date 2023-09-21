//
// Created by ARA on 2023-09-20.
//

#ifndef THIS_IS_DS_ALGORITHM_LINKEDLIST_H
#define THIS_IS_DS_ALGORITHM_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode(ElementType NewData);

void SLL_DestroyNode(Node* Node);

void SLL_AppendNode(Node** Head, Node* NewNode);

void SLL_InsertAfter(Node* Current, Node* NewNode);

void SLL_InsertNewHead(Node** Head, Node* NewHead);

void SLL_RemoveNode(Node** Head, Node* Remove);

Node* SLL_GetNodeAt(Node* Head, int Location);

int SLL_GetNodeCount(Node* Head);

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead);

void SLL_DestroyAllNodes(Node** List);

#endif //THIS_IS_DS_ALGORITHM_LINKEDLIST_H
