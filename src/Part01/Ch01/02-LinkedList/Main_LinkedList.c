//
// Created by ARA on 2023-09-20.
//
#include "LinkedList.h"

int main()
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

//	printf("sizeof(ElementType) : %llu\n", sizeof(ElementType));
//	printf("sizeof(tagNode*) : %llu\n", sizeof(struct tagNode*));
//	printf("sizeof(Node) : %llu\n", sizeof(Node));
//	printf("sizeof(Node*) : %llu\n", sizeof(Node*));

    for (i = 0; i < 5; ++i)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; ++i)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("list[%d] : %d\n", i, Current->data);
    }

//	printf("\nInserting 3000 After [2]...\n\n");
//
//	Current = SLL_GetNodeAt(list, 2);
//	NewNode = SLL_CreateNode(3000);
//
//	SLL_InsertAfter(Current, NewNode);

    printf("\nInserting 3000 Before [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    SLL_InsertBefore(&List, Current, NewNode);

    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; ++i)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("list[%d] : %d\n", i, Current->data);
    }

    printf("\nDestroying list...\n");

    SLL_DestroyAllNodes(&List);
    printf("list Count : %d\n", SLL_GetNodeCount(List));

//	for (i = 0; i < Count; ++i)
//	{
//		Current = SLL_GetNodeAt(list, 0);
//
//		if (Current != NULL)
//		{
//			SLL_RemoveNode(&list, Current);
//			SLL_DestroyNode(Current);
//		}
//	}

    return 0;
}