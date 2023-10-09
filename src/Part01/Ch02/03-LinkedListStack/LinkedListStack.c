//
// Created by ARA on 2023-10-04.
//

#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** stack)
{
    (*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*stack)->list = NULL;
    (*stack)->top = NULL;
}

void LLS_DestroyStack(LinkedListStack* stack)
{
    while (!LLS_IsEmpty(stack))
    {
        Node* node = LLS_Pop(stack);
        LLS_DestroyNode(node);
    }

    free(stack);
}

Node* LLS_CreateNode(char* data)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = (char*)malloc(strlen(data) + 1);
    node->next_node = NULL;

    strcpy(node->data, data);

    return node;
}

void LLS_DestroyNode(Node* _node)
{
    free(_node->data);
    if (_node->next_node != NULL)
    {
        LLS_DestroyNode(_node->next_node);
        _node->next_node = NULL;
    }
    free(_node);
}

void LLS_Push(LinkedListStack* stack, Node* new_node)
{
    if (stack->list == NULL)
    {
        stack->list = new_node;
    }
    else
    {
        stack->top->next_node = new_node;
    }

    stack->top = new_node;
}

Node* LLS_Pop(LinkedListStack* stack)
{
    Node* top_node = stack->top;

    if (stack->list == top_node)
    {
        stack->list = NULL;
        stack->top = NULL;
    }
    else
    {
        Node* current_top = stack->list;
        while (current_top != NULL && current_top->next_node != stack->top)
        {
            current_top = current_top->next_node;
        }

        stack->top = current_top;
        stack->top->next_node = NULL;
    }

    return top_node;
}

Node* LLS_Top(LinkedListStack* stack)
{
    return stack->top;
}

int LLS_GetSize(LinkedListStack* stack)
{
    int count = 0;
    Node* current = stack->list;

    while (current != NULL) {
        current = current->next_node;
        count++;
    }

    return count;
}

int LLS_IsEmpty(LinkedListStack* stack)
{
    return (stack->list == NULL);
}
