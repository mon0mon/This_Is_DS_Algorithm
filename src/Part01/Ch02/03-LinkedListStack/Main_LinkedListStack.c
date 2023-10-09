//
// Created by ARA on 2023-10-04.
//

#include "LinkedListStack.h"

int main() {
    int count = 0;

    Node* popped;
    LinkedListStack* stack;

    LLS_CreateStack(&stack);

    LLS_Push(stack, LLS_CreateNode("abc"));
    LLS_Push(stack, LLS_CreateNode("def"));
    LLS_Push(stack, LLS_CreateNode("efg"));
    LLS_Push(stack, LLS_CreateNode("hij"));

    count = LLS_GetSize(stack);
    printf("Size : %d, Top : %s\n\n", count, LLS_Top(stack)->data);

    for (int i = 0; i < count; ++i)
    {
        if (LLS_IsEmpty(stack)) {
            break;
        }

        popped = LLS_Pop(stack);

        printf("Popped : %s", popped->data);

        LLS_DestroyNode(popped);

        if (!LLS_IsEmpty(stack)) {
            printf("  Current Top : %s\n", LLS_Top(stack)->data);
        } else {
            printf("  Stack Is Empty.\n");
        }
    }

    LLS_DestroyStack(stack);

    return 0;
}