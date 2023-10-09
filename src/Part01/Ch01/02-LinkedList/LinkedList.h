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
    ElementType data;
    struct tagNode* next_node;
} Node;

Node* SLL_CreateNode(ElementType new_data);

void SLL_DestroyNode(Node* node);

void SLL_AppendNode(Node** head, Node* new_node);

void SLL_InsertAfter(Node* current, Node* new_node);

void SLL_InsertNewHead(Node** head, Node* new_head);

void SLL_RemoveNode(Node** head, Node* remove);

Node* SLL_GetNodeAt(Node* head, int location);

int SLL_GetNodeCount(Node* head);

void SLL_InsertBefore(Node** head, Node* current, Node* new_head);

void SLL_DestroyAllNodes(Node** list);

#endif //THIS_IS_DS_ALGORITHM_LINKEDLIST_H
