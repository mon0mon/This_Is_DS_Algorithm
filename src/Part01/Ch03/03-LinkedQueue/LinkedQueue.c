//
// Created by ARA on 2023-10-19.
//

#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** queue)
{
    (*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    (*queue)->count = 0;
}

void LQ_DestroyQueue(LinkedQueue* queue)
{
    while (!LQ_IsEmpty(queue))
    {
        Node* popped = LQ_Dequeue(queue);
        LQ_DestroyNode(popped);
    }

    free(queue);
}

Node* LQ_CreateNode(char* new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (char*)malloc(strlen(new_data) + 1);

    strcpy(new_node->data, new_data);

    new_node->next_node = NULL;

    return new_node;
}

void LQ_DestroyNode(Node* node)
{
    free(node->data);
    free(node);
}

void LQ_Enqueue(LinkedQueue* queue, Node* new_node)
{
    if (queue->front == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
        queue->count++;
    }
    else
    {
        queue->rear->next_node = new_node;
        queue->rear = new_node;
        queue->count++;
    }
}

Node* LQ_Dequeue(LinkedQueue* queue)
{
    Node* front = queue->front;

    if (queue->front->next_node == NULL)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next_node;
    }

    queue->count--;

    return front;
}

bool LQ_IsEmpty(LinkedQueue* queue)
{
    return (queue->front == NULL);
}
