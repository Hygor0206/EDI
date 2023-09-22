#include <stdlib.h>
#include <stdio.h>
#include "fila.c"

void parking(List*, List*, int);
int freeParking(List*, List*, int);
void rotateQueue(List*, Node*);

int main(){
    
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
    mainRemoved = removeNode(mainParking);
    rotateQueue(mainParking, head); 
    if(!emptyList(waitParking)){
        waitRemoved = removeQueue(waitParking);
        insertQueue(mainParking, waitRemoved);
    }
    return mainRemoved;
}

// PROJETO DE GIRAR A FILA
void rotateQueue(List* queue, Node* first){
    Node* node;
    int removed;
    node = queue->head;

    do{
        removed = removeQueue(node);
        insertQueue(queue, removed);
        node=node->next;
    }while(removed!=first);
}
// Nodo* nodo;
// int removido;
// nodo = fila->head;

// do{
//     removeFila(nodo);
//     insereFila(fila, removido);
//     nodo = nodo->next;
// }while(nodo != primeiro)