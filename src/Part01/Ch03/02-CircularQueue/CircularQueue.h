//
// Created by ARA on 2023-10-09.
//

#ifndef THIS_IS_DS_ALGORITHM_CIRCULARQUEUE_H
#define THIS_IS_DS_ALGORITHM_CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType data;
} Node;

typedef struct tagCircularQueue {
    int capacity;
    int front;
    int rear;

    Node* nodes;
} CircularQueue;

void CQ_CreateQueue(CircularQueue** queue, int capacity);
void CQ_DestroyQueue(CircularQueue* queue);
void CQ_Enqueue(CircularQueue* queue, ElementType data);
ElementType CQ_Dequeue(CircularQueue* queue);
int CQ_GetSize(CircularQueue* queue);
int CQ_IsEmpty(CircularQueue* queue);
int CQ_IsFull(CircularQueue* queue);

#endif //THIS_IS_DS_ALGORITHM_CIRCULARQUEUE_H
