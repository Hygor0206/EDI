#include <stdlib.h>
#include <stdio.h>
#include "fila.c"

void parking(Queue*, Queue*, int);
int freeParking(Queue*, Queue*, int);
void rotateQueue(Queue*, Node*);

int main(){
    Queue* parkingQueue=createQueue();
    Queue* waitingQueue=createQueue();

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
                if(!(emptyQueue(waitingQueue))){
                    printf("Parking is full, car is waiting in the queue\n");
                    readQueue(waitingQueue);
                }else{
                    printf("Parked Cars\n");
                    readQueue(parkingQueue);
                }
                break;
            case 'p':
            case 'P':
                printf("What's the license plate of the car?\n");
                scanf(" %d", &plate);

                freeParking(parkingQueue, waitingQueue, plate);
                printf("Current cars parked\n");
                readQueue(parkingQueue);
                break;
            default:
                printf("Invalid Option\n");
                break;
        }
    }
}

void parking(Queue* mainParking, Queue* waitParking, int plate){
    if(mainParking->size<10)
        insertQueue(mainParking, plate);
    else
        insertQueue(waitParking, plate);
}

int freeParking(Queue* mainParking, Queue* waitParking, int plate){
    int mainRemoved, waitRemoved;

    if(emptyQueue(mainParking))
        return -1;

    Node* nodeRemove = search(mainParking, plate);
    Node* head;
    if(plate==mainParking->head->data){
        head = mainParking->head->next;
    }else{
        head = mainParking->head;
    }
    
    rotateQueue(mainParking, nodeRemove);
    mainRemoved = removeQueue(mainParking);
    rotateQueue(mainParking, head); 
    if(!emptyQueue(waitParking)){
        waitRemoved = removeQueue(waitParking);
        insertQueue(mainParking, waitRemoved);
    }
    return mainRemoved;
}

void rotateQueue(Queue* queue, Node* first){
    Node* node;
    int removed;
    node = queue->head;

    while(node!=first){
        removed = removeQueue(queue);
        insertQueue(queue, removed);
        if(node->prev==NULL){
            node = node->next;
        }else{
            node = node->prev;
        }
    };
}