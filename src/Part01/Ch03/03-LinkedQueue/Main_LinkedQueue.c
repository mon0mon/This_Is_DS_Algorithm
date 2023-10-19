//
// Created by ARA on 2023-10-19.
//
#include "LinkedQueue.h"

int main() {
    Node* popped;
    LinkedQueue* queue;

    LQ_CreateQueue(&queue);

    LQ_Enqueue(queue, LQ_CreateNode("abc"));
    LQ_Enqueue(queue, LQ_CreateNode("def"));
    LQ_Enqueue(queue, LQ_CreateNode("efg"));
    LQ_Enqueue(queue, LQ_CreateNode("hij"));

    printf("Queue Size : %d\n", queue->count);

    while (!LQ_IsEmpty(queue)) {
        Node* popped = LQ_Dequeue(queue);
        printf("Dequeue : %s \n", popped->data);
        LQ_DestroyNode(popped);
    }

    LQ_DestroyQueue(queue);

    return 0;
}