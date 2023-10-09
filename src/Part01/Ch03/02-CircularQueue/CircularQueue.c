//
// Created by ARA on 2023-10-09.
//

#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue** queue, int capacity)
{
    (*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

    (*queue)->capacity = capacity;
    (*queue)->front = 0;
    (*queue)->rear = 0;

    (*queue)->nodes = (Node*)malloc(sizeof(Node) * (capacity + 1));
}

void CQ_DestroyQueue(CircularQueue* queue)
{
    free(queue->nodes);
    free(queue);
}

void CQ_Enqueue(CircularQueue* queue, ElementType data)
{
    int position = 0;
    if (queue->rear == queue->capacity)
    {
        position = queue->rear;
        queue->rear = 0;
    }
    else
    {
        position = queue->rear++;
    }

    queue->nodes[position].data = data;
}

ElementType CQ_Dequeue(CircularQueue* queue)
{
    int position = queue->front;

    if (queue->front == queue->capacity)
    {
        queue->front = 0;
    } else {
        queue->front++;
    }

    return queue->nodes[position].data;
}

int CQ_GetSize(CircularQueue* queue)
{
    if (queue->front <= queue->rear) {
        return queue->rear - queue->front;
    } else {
        return queue->rear + (queue->capacity - queue->front) + 1;
    }
}

int CQ_IsEmpty(CircularQueue* queue)
{
    return (queue->front == queue->rear);
}

int CQ_IsFull(CircularQueue* queue)
{
    if (queue->front < queue->rear) {
        return (queue->rear - queue->front) == queue->capacity;
    } else {
        return (queue->rear + 1) == queue->front;
    }
}
