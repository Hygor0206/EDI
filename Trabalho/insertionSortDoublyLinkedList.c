#include <stdlib.h>
#include <stdio.h>
#include "node.h"

// Prototipação das funções
Node *getNode(int);
void sortedInsert(Node**, Node*);
void printList(Node*);

// Função main com as chamadas das funções
int main(){
    Node* list = NULL;
    Node* newNode = getNode(12);

    sortedInsert(&list, newNode);
    newNode=getNode(11);
    sortedInsert(&list, newNode);
    newNode=getNode(13);
    sortedInsert(&list, newNode);
    newNode=getNode(5);
    sortedInsert(&list, newNode);
    newNode=getNode(6);
    sortedInsert(&list, newNode);

    printf("Lista Duplamente Encadeada\n");
    printList(list);
    return 0;
}

Node *getNode(int data){
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->data=data;
    newNode->prev=newNode->next=NULL;
    return newNode;
}

void sortedInsert(Node** list_ref, Node* newNode){
    Node *current;

    if(*list_ref==NULL)
        *list_ref=newNode;
    else if((*list_ref)->data>=newNode->data){
        newNode->next=*list_ref;
        newNode->next->prev=newNode;
        *list_ref=newNode;
    }else{
        current=*list_ref;

        while(current->next!=NULL&&current->next->data<newNode->data)
            current=current->next;

        newNode->next=current->next;
        
        if(current->next!=NULL)
            newNode->next->prev=newNode;
        
        current->next=newNode;
        newNode->prev=current;
    }
}

void printList(Node* list){
    while (list!=NULL){
        printf("%d ", list->data);
        list=list->next;
    }
    printf("\n");
}
