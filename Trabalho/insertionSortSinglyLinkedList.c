#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* head = NULL;
Node* sorted = NULL;

// Prototipação das funções
void push(int);
void sortedInsert(Node*);
void insertionSort();
void printlist(Node*);

// Função main com as chamadas das funções
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

	insertionSort(head);

	printf("Lista Ordenada com Insertion Sort:\n");
	printlist(head);
}

void push(int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = head;
	head = newNode;
}

void sortedInsert(Node* newNode)
{
	if (sorted == NULL || sorted->data >= newNode->data) {
		newNode->next = sorted;
		sorted = newNode;
	}
	else {
		Node* current = sorted;

		while (current->next != NULL
			&& current->next->data < newNode->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void insertionSort()
{
	Node* current = head;

	while (current != NULL) {
		Node* next = current->next;

		sortedInsert(current);
		current = next;
	}
	head = sorted;
}

void printlist(Node* head)
{
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
