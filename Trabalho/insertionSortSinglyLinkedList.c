#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* head = NULL;
Node* sorted = NULL;

void push(int);
void sortedInsert(Node*);
void insertionsort();
void printlist(Node*);

// Driver program to test above functions
int main()
{
	push(12);
	push(11);
	push(13);
	push(5);
	push(6);

	printf("Lista Desordenada:\n");
	printlist(head);
	printf("\n");

	insertionsort(head);

	printf("Lista Ordenada com Insertion Sort:\n");
	printlist(head);
}

void push(int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	/* link the old list of the new node */
	newNode->next = head;
	/* move the head to point to the new node */
	head = newNode;
}

/*
* function to insert a new_node in a list. Note that
* this function expects a pointer to head_ref as this
* can modify the head of the input linked list
* (similar to push())
*/
void sortedInsert(Node* newNode)
{
	/* Special case for the head end */
	if (sorted == NULL || sorted->data >= newNode->data) {
		newNode->next = sorted;
		sorted = newNode;
	}
	else {
		Node* current = sorted;
		/* Locate the node before the point of insertion
		*/
		while (current->next != NULL
			&& current->next->data < newNode->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

// function to sort a singly linked list
// using insertion sort
void insertionsort()
{
	Node* current = head;

	// Traverse the given linked list and insert every
	// node to sorted
	while (current != NULL) {

		// Store next for next iteration
		Node* next = current->next;

		// insert current in sorted linked list
		sortedInsert(current);

		// Update current
		current = next;
	}
	// Update head to point to sorted linked list
	head = sorted;
}

/* Function to print linked list */
void printlist(Node* head)
{
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
