//
// Created by ARA on 2023-09-26.
//

#ifndef THIS_IS_DS_ALGORITHM_ARRAYSTACK_H
#define THIS_IS_DS_ALGORITHM_ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
} Node;

typedef struct tagArrayStack
{
    int capacity;
    int top;
    Node* nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** stack, int capacity);

void AS_DestroyStack(ArrayStack* stack);

void AS_Push(ArrayStack* stack, ElementType data);

ElementType AS_Pop(ArrayStack* stack);

ElementType AS_Top(ArrayStack* stack);

int AS_GetSize(ArrayStack* stack);

bool AS_IsEmpty(ArrayStack* stack);

bool AS_IsFull(ArrayStack* stack);

#endif //THIS_IS_DS_ALGORITHM_ARRAYSTACK_H
