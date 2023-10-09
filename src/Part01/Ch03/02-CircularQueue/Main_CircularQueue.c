//
// Created by ARA on 2023-10-09.
//
#include "CircularQueue.h"

int main()
{
    CircularQueue* queue;

    CQ_CreateQueue(&queue, 10);

    CQ_Enqueue(queue, 1);
    CQ_Enqueue(queue, 2);
    CQ_Enqueue(queue, 3);
    CQ_Enqueue(queue, 4);

    for (int i = 0; i < 3; ++i)
    {
        printf("Dequeue : %d, ", CQ_Dequeue(queue));
        printf("(Front:%d, Rear:%d)\n", queue->front, queue->rear);
    }

    int i = 100;
    while (CQ_IsFull(queue) == 0)
    {
        CQ_Enqueue(queue, i++);
    }

    printf("Capacity: %d, Size: %d\n\n", queue->capacity, CQ_GetSize(queue));

    while (CQ_IsEmpty(queue) == 0) {
        printf("Dequeue : %d, ", CQ_Dequeue(queue));
        printf("(Front: %d, Rear: %d)\n", queue->front, queue->rear);
    }

    CQ_DestroyQueue(queue);

    return 0;
}