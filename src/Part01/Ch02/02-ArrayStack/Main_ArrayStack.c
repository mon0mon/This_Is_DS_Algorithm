//
// Created by ARA on 2023-09-26.
//

#include "ArrayStack.h"

int main()
{
    ArrayStack* stack = NULL;

    AS_CreateStack(&stack, 2);

    AS_Push(stack, 3);
    AS_Push(stack, 37);
    AS_Push(stack, 11);
    AS_Push(stack, 12);

    printf("Capacity: %d, Size: %d, Top: %d\n\n",
            stack->capacity, AS_GetSize(stack), AS_Top(stack));

    for (int i = 0; i < 4; ++i)
    {
        if (AS_IsEmpty(stack)) {
            break;
        }

        printf("Popped: %d, ", AS_Pop(stack));

        if (!AS_IsEmpty(stack)) {
            printf("Current Top: %d\n", AS_Top(stack));
        } else {
            printf("Stack Is Empty.\n");
        }
    }

    AS_DestroyStack(stack);

    return 0;
}