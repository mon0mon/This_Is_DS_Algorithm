//
// Created by ARA on 2023-09-22.
//

#ifndef THIS_IS_DS_ALGORITHM_DOUBLYLINKEDLIST_H
#define THIS_IS_DS_ALGORITHM_DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* DLL_CreateNode(ElementType NewData);

void DLL_DestroyNode(Node* Node);

void DLL_AppendNode(Node** Head, Node* NewNode);

void DLL_InsertAfter(Node* Current, Node* NewNode);

void DLL_RemoveNode(Node** Head, Node* Remove);

Node* DLL_GetNodeAt(Node* Head, int Location);

int DLL_GetNodeCount(Node* Head);

void PrintReverse(Node* Head);

#endif //THIS_IS_DS_ALGORITHM_DOUBLYLINKEDLIST_H
