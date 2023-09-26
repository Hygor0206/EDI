#include <stdlib.h>
#include <stdio.h>
#include "fila.c"

void parking(List*, List*, int);
int freeParking(List*, List*, int);
void rotateQueue(List*, Node*);

int main(){
    List* myList=createList();

    insertQueue(myList, 25);
    readList(myList);
}

void parking(List* mainParking, List* waitParking, int plate){
    if(mainParking->size<10)
        insertQueue(mainParking, plate);
    else
        insertQueue(waitParking, plate);
}

int freeParking(List* mainParking, List* waitParking, int plate){
    int mainRemoved, waitRemoved;

    if(emptyList(mainParking))
        return -1;

    Node* nodeRemove = search(mainParking, plate);
    Node* head = mainParking->head;
    
    rotateQueue(mainParking, nodeRemove);
    mainRemoved = removeQueue(mainParking);
    rotateQueue(mainParking, head); 
    if(!emptyList(waitParking)){
        waitRemoved = removeQueue(waitParking);
        insertQueue(mainParking, waitRemoved);
    }
    return mainRemoved;
}

void rotateQueue(List* queue, Node* first){
    Node* node;
    int removed;
    node = queue->head;

    do{
        removed = removeQueue(queue);
        insertQueue(queue, removed);
        node=node->next;
    }while(removed!=first->data);
}
