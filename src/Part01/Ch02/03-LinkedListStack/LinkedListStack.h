//
// Created by ARA on 2023-10-04.
//

#ifndef THIS_IS_DS_ALGORITHM_LINKEDLISTSTACK_H
#define THIS_IS_DS_ALGORITHM_LINKEDLISTSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
    char* data;
    struct tagNode* next_node;
} Node;

typedef struct tagLinkedListStack {
    Node* list;
    Node* top;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** stack);
void LLS_DestroyStack(LinkedListStack* stack);

Node* LLS_CreateNode(char* data);
void LLS_DestroyNode(Node* _node);

void LLS_Push(LinkedListStack* stack, Node* new_node);
Node* LLS_Pop(LinkedListStack* stack);

Node* LLS_Top(LinkedListStack* stack);
int LLS_GetSize(LinkedListStack* stack);
int LLS_IsEmpty(LinkedListStack* stack);

#endif //THIS_IS_DS_ALGORITHM_LINKEDLISTSTACK_H

