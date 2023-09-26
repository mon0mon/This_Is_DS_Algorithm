//
// Created by ARA on 2023-09-26.
//

#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** stack, int capacity)
{
    (*stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    (*stack)->nodes = (Node*)malloc(sizeof(Node) * capacity);
    (*stack)->capacity = capacity;
    (*stack)->top = -1;
}

void AS_DestroyStack(ArrayStack* stack)
{
    free(stack->nodes);

    free(stack);
}

void AS_Push(ArrayStack* stack, ElementType data)
{
    stack->top++;

    if (AS_IsFull(stack))
    {
        //  내부에 realloc으로 메모리를 옮기고
        //  데이터를 추가하는 방식으로 구현하기
        stack->nodes = (Node*)realloc(stack->nodes, stack->capacity * 2);
        stack->capacity = stack->capacity * 2;
    }

    stack->nodes[stack->top].data = data;
}

bool AS_IsFull(ArrayStack* stack)
{
    return stack->top == stack->capacity;
}

ElementType AS_Pop(ArrayStack* stack)
{
    if (stack->top < -1) {
        return -100;
    }

    int position = stack->top--;
    int data = stack->nodes[position].data;

    return stack->nodes[position].data;
}

ElementType AS_Top(ArrayStack* stack)
{
    if (stack->top < -1) {
        return -100;
    }

    return stack->nodes[stack->top].data;
}

int AS_GetSize(ArrayStack* stack)
{
    return (stack->top) + 1;
}

bool AS_IsEmpty(ArrayStack* stack)
{
    return stack->top == -1;
}