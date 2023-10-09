//
// Created by ARA on 2023-09-20.
//

#include "LinkedList.h"

Node* SLL_CreateNode(ElementType new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next_node = NULL;

    return new_node;
}

void SLL_DestroyNode(Node* node)
{
    free(node);
}

void SLL_AppendNode(Node** head, Node* new_node)
{
    if ((*head) == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node* tail = (*head);
        while (tail->next_node != NULL)
        {
            tail = tail->next_node;
        }
        tail->next_node = new_node;
    }
}

void SLL_InsertAfter(Node* current, Node* new_node)
{
    new_node->next_node = current->next_node;
    current->next_node = new_node;
}

void SLL_InsertNewHead(Node** head, Node* new_head)
{
    if (*head == NULL)
    {
        (*head) = new_head;
    }
    else
    {
        new_head->next_node = (*head);
        (*head) = new_head;
    }
}

void SLL_RemoveNode(Node** head, Node* remove)
{
    if (*head == remove)
    {
        *head = remove->next_node;
    }
    else
    {
        Node* current = *head;
        while (current != NULL && current->next_node != remove)
        {
            current = current->next_node;
        }

        if (current != NULL)
        {
            current->next_node = remove->next_node;
        }
    }
}

Node* SLL_GetNodeAt(Node* head, int location)
{
    Node* current = head;

    while (current != NULL && (--location) >= 0)
    {
        current = current->next_node;
    }

    return current;
}

int SLL_GetNodeCount(Node* head)
{
    int count = 0;
    Node* current = head;

    while (current != NULL)
    {
        current = current->next_node;
        count++;
    }

    return count;
}

void SLL_InsertBefore(Node** head, Node* current, Node* new_head)
{
    if (*head == NULL)
    {
        *head = new_head;
    }
    else
    {
        Node* pointer = (*head);
        while (pointer->next_node != NULL && pointer->next_node != current)
        {
            pointer = pointer->next_node;
        }

        new_head->next_node = pointer->next_node;
        pointer->next_node = new_head;
    }
}

void SLL_DestroyAllNodes(Node** list)
{
    Node* head = *list;
    Node* prev = NULL;

    do
    {
        prev = head;
        head = head->next_node;
        free(prev);
    } while (head != NULL);

    *list = NULL;
}
