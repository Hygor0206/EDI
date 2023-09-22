#include "lista.c"

void insertQueue(List*, int);
int removeQueue(List*);
Node* findMaxQueue(List*);
Node* findMinQueue(List*);

void insertQueue(List* queue, int data){
    insertNode(queue, queue->tail, data);
}

int removeQueue(List* queue){
    int removed = removeNode(queue, queue->head->prev);
    return removed;
}

Node* findMaxQueue(List* queue){
    Node* max;
    Node* node;
    
    if(emptyList(queue))
        return -1;

    node = queue->head;
    while(node!=NULL){
        if(node->next->data>node->data)
            max=node->next;
        node = node->next;
    }
    return max;
}

Node* findMaxQueue(List* queue){
    Node* max;
    Node* node;
    
    if(emptyList(queue))
        return -1;

    node = queue->head;
    while(node!=NULL){
        if(node->next->data<node->data)
            max=node->next;
        node = node->next;
    }
    return max;
}