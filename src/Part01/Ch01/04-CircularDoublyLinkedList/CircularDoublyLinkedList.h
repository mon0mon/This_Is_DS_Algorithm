//
// Created by ARA on 2023-09-23.
//

#ifndef THIS_IS_DS_ALGORITHM_CIRCULARDOUBLYLINKEDLIST_H
#define THIS_IS_DS_ALGORITHM_CIRCULARDOUBLYLINKEDLIST_H

#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct TagNode
{
	ElementType data;
	struct TagNode* prev_node;
	struct TagNode* next_node;
} Node;

Node* CDLL_CreateNode(ElementType new_data);

void CDLL_DestroyNode(Node* node);

void CDLL_AppendNode(Node** head, Node* new_node);

void CDLL_InsertAfter(Node* current, Node* new_node);

void CDLL_RemoveNode(Node** head, Node* remove);

Node* CDLL_GetNodeAt(Node* head, int location);

int CDLL_GetNodeCount(Node* head);

void PrintNode(Node* node);

#endif //THIS_IS_DS_ALGORITHM_CIRCULARDOUBLYLINKEDLIST_H
