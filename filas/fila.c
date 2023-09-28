#include "lista.c"

typedef List Queue;

Queue* createQueue();
void insertQueue(Queue*, int);
int removeQueue(Queue*);
Node* findMaxQueue(Queue*);
Node* findMinQueue(Queue*);

Queue* createQueue(){
    return createList();
}

void insertQueue(Queue* queue, int data){
    insertNode(queue, queue->tail, data);
}

int removeQueue(Queue* queue){
    int removed = removeNode(queue, queue->head);
    return removed;
}

Node* findMaxQueue(Queue* queue){
    Node* max;
    Node* node;
    
    if(emptyQueue(queue))
        errors(-1);

    node = queue->head;
    while(node!=NULL){
        if(node->next->data>node->data)
            max=node->next;
        node = node->next;
    }
    return max;
}

Node* findMinQueue(Queue* queue){
    Node* max;
    Node* node;
    
    if(emptyQueue(queue))
        errors(-1);

    node = queue->head;
    while(node!=NULL){
        if(node->next->data<node->data)
            max=node->next;
        node = node->next;
    }
    return max;
}