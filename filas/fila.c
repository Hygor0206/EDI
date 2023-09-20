#include <stdlib.h>
#include <stdio.h>

typedef struct sNode{
    struct sNode *prev;
    struct sNode *next;
    int data;
} Node;

typedef struct sQueue{
    struct sNode* head;
    struct sNode* tail;
    int size;
} Queue;

Node* createNode(int);
Queue* createQueue();
int emptyQueue(Queue*);
void insertNode(Queue*, int);
void removeNode(Queue*);
void errors(int);
int readQueue(Queue*);

int main(){
    Queue* myQueue;
    myQueue = createQueue();

    insertNode(myQueue, 10);
    errors(readQueue(myQueue));
    insertNode(myQueue, 15);
    errors(readQueue(myQueue));
    insertNode(myQueue, 20);
    errors(readQueue(myQueue));
    removeNode(myQueue);
    errors(readQueue(myQueue));
    removeNode(myQueue);
    errors(readQueue(myQueue));
    removeNode(myQueue);
    removeNode(myQueue);
}

Node* createNode(int data){
    Node* new;
    new = (Node*) malloc(sizeof(Node));
    if(new!=NULL){
        new->data = data;
        new->prev = NULL;
        new->next = NULL;
    }
}

Queue* createQueue(){
    Queue* queue;
    queue = (Queue*)malloc(sizeof(Queue));
    if(queue!=NULL){
        queue->head = NULL;
        queue->tail = NULL;
        queue->size = 0;
    }
}

int emptyQueue(Queue* queue){
    if(queue->size==0)
        return 1;
    return 0;
}

void errors(int error){
    if(error == -1)
        printf("\nQueue Underflow");
    else if(error == -2){
        printf("\nEnd of the Queue");
    }
}

void insertNode(Queue* queue, int data){
    Node* oldTail;
    Node* newElement = createNode(data);
    
    if(!(emptyQueue(queue))){
        oldTail = queue->tail;
        queue->tail=newElement;
        oldTail->next=queue->tail;
        queue->tail->prev=oldTail;
        if(oldTail->prev==NULL){
            queue->head=oldTail;
        }
    }else{
        queue->tail=newElement;
    }
    queue->size++;
}

void removeNode(Queue* queue){
    Node* elementDelete;
    
    if(emptyQueue(queue))
        errors(-1);
    else{
        elementDelete=queue->head;
        queue->head=elementDelete->next;
        if(queue->head==NULL)
            queue->tail=NULL;
        else
            queue->head->prev=NULL;
            free(elementDelete);
    }
    queue->size--;
}

int readQueue(Queue* queue){
    Node* node;

    if(emptyQueue(queue))
        errors(-1);
    else{
        printf("\n Queue: \n");
        node = queue->head;
        while(node!=NULL){
            printf("%i, ", node->data);
            node = node->next;
        }
        return -2;
    }
}