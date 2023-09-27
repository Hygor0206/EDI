#include <stdlib.h>
#include <stdio.h>
#include "fila.c"

void parking(List*, List*, int);
int freeParking(List*, List*, int);
void rotateQueue(List*, Node*);

int main(){
    List* parkingQueue=createList();
    List* waitingQueue=createList();

    char resposta;
    int plate;

    for(;;){
        printf("\nEstacionamento\n"
        "C - Chegada\n"
        "P - Partida\n"
        "S - Sair\n");
        scanf(" %c", &resposta);
        if((resposta=='S')||(resposta=='s')){
            printf("Closing program\n");
            return 0;
        }

        switch (resposta)
        {
            case 'c':    
            case 'C':
                printf("What's the license plate of the car?\n");
                scanf(" %d", &plate);

                parking(parkingQueue, waitingQueue, plate);
                if(!(emptyList(waitingQueue))){
                    printf("Parking is full, car is waiting in the queue\n");
                    readList(waitingQueue);
                }else{
                    printf("Parked Cars\n");
                    readList(parkingQueue);
                }
                break;
            case 'p':
            case 'P':
                printf("What's the license plate of the car?\n");
                scanf(" %d", &plate);

                freeParking(parkingQueue, waitingQueue, plate);
                printf("Current cars parked\n");
                readList(parkingQueue);
                break;
            default:
                printf("Invalid Option\n");
                break;
        }
    }
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

    while(node!=first){
        removed = removeQueue(queue);
        insertQueue(queue, removed);
        node = node->prev;
    };
}