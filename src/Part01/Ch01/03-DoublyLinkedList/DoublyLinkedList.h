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
    ElementType data;
    struct tagNode* prev_node;
    struct tagNode* next_node;
} Node;

Node* DLL_CreateNode(ElementType new_data);

void DLL_DestroyNode(Node* node);

void DLL_AppendNode(Node** head, Node* new_node);

void DLL_InsertAfter(Node* current, Node* new_node);

void DLL_RemoveNode(Node** head, Node* remove);

Node* DLL_GetNodeAt(Node* head, int location);

int DLL_GetNodeCount(Node* head);

void PrintReverse(Node* head);

#endif //THIS_IS_DS_ALGORITHM_DOUBLYLINKEDLIST_H
