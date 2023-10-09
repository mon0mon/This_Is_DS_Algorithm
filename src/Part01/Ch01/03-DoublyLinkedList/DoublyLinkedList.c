//
// Created by ARA on 2023-09-22.
//

#include "DoublyLinkedList.h"


Node* DLL_CreateNode(ElementType newData)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = newData;
    new_node->next_node = NULL;
    new_node->prev_node = NULL;

    return new_node;
}

void DLL_DestroyNode(Node* node)
{
    free(node);
}

void DLL_AppendNode(Node** head, Node* new_node)
{
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node* pointer = *(head);

        while (pointer->next_node != NULL)
        {
            pointer = pointer->next_node;
        }

        pointer->next_node = new_node;
        new_node->prev_node = pointer;
    }
}

void DLL_InsertAfter(Node* current, Node* new_node)
{
    new_node->next_node = current->next_node;
    new_node->prev_node = current;

    if (current->next_node != NULL)
    {
        current->next_node->prev_node = new_node;
        current->next_node = new_node;
    }
}

void DLL_RemoveNode(Node** head, Node* remove)
{
    if (*head == remove)
    {
        if (*head == NULL)
        {
            return;
        }

        if (remove->next_node != NULL)
        {
            remove->next_node->prev_node = NULL;
        }

        *head = remove->next_node;

        remove->next_node = NULL;
//		DLL_DestroyNode(remove);
    }
    else
    {
        Node* pointer = *head;

        while (pointer->next_node != remove)
        {
            pointer = pointer->next_node;
        }

        remove->next_node->prev_node = pointer;
        pointer->next_node = remove->next_node;

        remove->prev_node = NULL;
        remove->next_node = NULL;

//		DLL_DestroyNode(remove);
    }
}

Node* DLL_GetNodeAt(Node* head, int location)
{
    Node* pointer = head;

    while (pointer != NULL && (location--) > 0)
    {
        pointer = pointer->next_node;
    }

    return pointer;
}

int DLL_GetNodeCount(Node* head)
{
    unsigned int count = 0;
    Node* pointer = head;

    while (pointer != NULL)
    {
        count++;
        pointer = pointer->next_node;
    }

    return count;
}

void PrintReverse(Node* head)
{
    Node* pointer = head;

    while (pointer->next_node != NULL)
    {
        pointer = pointer->next_node;
    }

    printf("Print Nodes Reverse\n");
    int count = DLL_GetNodeCount(head);
    do
    {
        printf("list[%d] : %d\n", --count, pointer->data);
        pointer = pointer->prev_node;
    } while (pointer != NULL);
}