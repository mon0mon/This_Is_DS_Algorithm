//
// Created by ARA on 2023-09-22.
//

#include "../03-DoublyLinkedList/DoublyLinkedList.h"

/*
 * VITAMIN QUIZ 1-3
 * void PrintReverse(Node* Head) 구현
 */

void PrintReverse(Node* Head)
{
    Node* Pointer = Head;

    while (Pointer->NextNode != NULL)
    {
        Pointer = Pointer->NextNode;
    }

    printf("Print Nodes Reverse\n");
    int Count = DLL_GetNodeCount(Head);
    do
    {
        printf("List[%d] : %d\n", --Count, Pointer->Data);
        Pointer = Pointer->PrevNode;
    } while (Pointer != NULL);
}