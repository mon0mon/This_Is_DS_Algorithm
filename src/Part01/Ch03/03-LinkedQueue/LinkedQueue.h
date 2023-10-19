//
// Created by ARA on 2023-10-19.
//

#ifndef THIS_IS_DS_ALGORITHM_LINKEDQUEUE_H
#define THIS_IS_DS_ALGORITHM_LINKEDQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tagNode
{
    char* data;
    struct tagNode* next_node;
} Node;

typedef struct tagLinkedQueue
{
    Node* front;
    Node* rear;
    int count;
} LinkedQueue;

void LQ_CreateQueue(LinkedQueue** queue);
void LQ_DestroyQueue(LinkedQueue* queue);

Node* LQ_CreateNode(char* new_data);
void LQ_DestroyNode(Node* node);

void LQ_Enqueue(LinkedQueue* queue, Node* new_node);
Node* LQ_Dequeue(LinkedQueue* queue);

bool LQ_IsEmpty(LinkedQueue* queue);

#endif //THIS_IS_DS_ALGORITHM_LINKEDQUEUE_H
