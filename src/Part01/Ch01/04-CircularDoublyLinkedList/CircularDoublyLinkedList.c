//
// Created by ARA on 2023-09-23.
//

#include "CircularDoublyLinkedList.h"


Node* CDLL_CreateNode(ElementType new_data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node->data = new_data;
	new_node->prev_node = NULL;
	new_node->next_node = NULL;

	return new_node;
}

void CDLL_DestroyNode(Node* node)
{
	free(node);
}

void CDLL_AppendNode(Node** head, Node* new_node)
{
	if ((*head) == NULL)
	{
		*head = new_node;
		new_node->next_node = *head;
		new_node->prev_node = *head;
	}
	else
	{
		Node* tail = (*head)->prev_node;

		(*head)->prev_node = new_node;
		tail->next_node = new_node;

		new_node->next_node = (*head);
		new_node->prev_node = tail;
	}
}

void CDLL_InsertAfter(Node* current, Node* new_node)
{
	Node* current_next_node = current->next_node;

	new_node->next_node = current_next_node;
	new_node->prev_node = current;

	current->next_node = new_node;
	if (current_next_node != NULL)
	{
		current_next_node->prev_node = new_node;
	}
}

void CDLL_RemoveNode(Node** head, Node* remove)
{
	if ((*head) == remove)
	{
		Node* tail = (*head)->prev_node;
		Node* remove_next_node = remove->next_node;

		tail->next_node = remove->next_node;
		remove_next_node->prev_node = remove->prev_node;

		*head = remove_next_node;

		remove->next_node = NULL;
		remove->prev_node = NULL;
	}
	else
	{
		remove->next_node->prev_node = remove->prev_node;
		remove->prev_node->next_node = remove->next_node;

		remove->next_node = NULL;
		remove->prev_node = NULL;
	}
}

Node* CDLL_GetNodeAt(Node* head, int location)
{
	Node* current = head;

	while (current != NULL && (location--) > 0) {
		current = current->next_node;
	}

	return current;
}

int CDLL_GetNodeCount(Node* head)
{
	unsigned int count = 0;
	Node* current = head;

	if (head == NULL) {
		return 0;
	}

	do
	{
		current = current->next_node;
		count++;
	} while(current != head);

	return count;
}

void PrintNode(Node* node)
{
	if (node == NULL) {
		return;
	}

	if (node->prev_node == NULL) {
		printf("Prev: NULL\t");
	} else {
		printf("Prev: %d\t", node->prev_node->data);
	}

	printf("Current: %d\t", node->data);

	if (node->next_node == NULL) {
		printf("Next: NULL\n");
	} else {
		printf("Next: %d\n", node->next_node->data);
	}
}

