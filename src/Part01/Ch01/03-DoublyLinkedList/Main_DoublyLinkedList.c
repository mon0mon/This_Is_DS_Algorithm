//
// Created by ARA on 2023-09-22.
//

#include "DoublyLinkedList.h"

int main()
{
    int count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* current = NULL;

    for (int i = 0; i < 5; ++i)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    count = DLL_GetNodeCount(List);

    for (int i = 0; i < count; ++i)
    {
        current = DLL_GetNodeAt(List, i);
        printf("list[%d] : %d\n", i, current->data);
    }

    printf("\nInserting 3000 After [2]...\n");

    current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(current, NewNode);

    count = DLL_GetNodeCount(List);
    for (int i = 0; i < count; ++i)
    {
        current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, current->data);
    }

    printf("\n");
    PrintReverse(List);

    printf("\nDestroying list...\n");
    count = DLL_GetNodeCount(List);

    for (int i = 0; i < count; ++i)
    {
        current = DLL_GetNodeAt(List, 0);

        if (current != NULL)
        {
            DLL_RemoveNode(&List, current);
            DLL_DestroyNode(current);
        }
    }

    return 0;
}