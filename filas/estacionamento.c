#include <stdlib.h>
#include <stdio.h>
#include "fila.c"

void parking(Queue*, Queue*, int);
int freeParking(Queue*, Queue*, int);
int rotateQueue(Queue*, Node*, int);

int main(){
    Queue* parkingQueue=createQueue();
    Queue* waitingQueue=createQueue();

    char resposta;
    int plate;
    int turnTimes = 0;

    for(;;){
        printf("\n=====================================\n");
        printf("==============Parking================\n");
        printf("=====================================\n");
        if(!emptyList(parkingQueue)){
            printf("\nCurrent Cars Parked:\n");
            readList(parkingQueue);
        }else{
            printf("\nParking lot is empty");
        }
        if(!emptyList(waitingQueue)){
            printf("\n");
            printf("\nCars Waiting\n");
            readList(waitingQueue);
        }
        printf("\n");
        printf("\nChoose an option:");
        printf("\nC - Arrive\n"
        "P - Leaving\n"
        "E - Exit Program\n");
        scanf(" %c", &resposta);
        if((resposta=='E')||(resposta=='e')){
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
                    printf("The parking lot is full, the car is waiting in the queue\n");
                }else{
                    printf("The car has been successfully parked\n");
                }
                break;
            case 'p':
            case 'P':
                printf("What's the license plate of the car?\n");
                scanf(" %d", &plate);

                turnTimes = freeParking(waitingQueue, waitingQueue, plate);
                if (turnTimes <= 0){
                    turnTimes = freeParking(parkingQueue, waitingQueue, plate);
                    if(turnTimes <= 0){
                        printf("The car was not found\n");
                    }else{
                        printf("The car was moved %d times and has left the parking lot\n", turnTimes);
                    }
                }else{
                    printf("The car has left the waiting queue");
                }
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
    int waitRemoved, turnTimes=0;

    if(emptyList(mainParking))
        return -1;

    Node* nodeRemove = search(mainParking, plate);

    if(nodeRemove==NULL){
        nodeRemove = search(waitParking, plate);
        if(nodeRemove==NULL) return 0;
    }

    Node* head;
    if(plate==mainParking->head->data){
        head = mainParking->head->next;
    }else{
        head = mainParking->head;
    }
    
    turnTimes = rotateQueue(mainParking, nodeRemove, turnTimes);
    removeQueue(mainParking);
    rotateQueue(mainParking, head, turnTimes);
    if(!emptyList(waitParking)){
        waitRemoved = removeQueue(waitParking);
        insertQueue(mainParking, waitRemoved);
    }
    return turnTimes;
}

int rotateQueue(Queue* queue, Node* first, int turnTimes){
    turnTimes++;
    while(queue->head != first){
        int frontValue = removeQueue(queue);
        insertQueue(queue, frontValue);
        turnTimes++;
    }
    return turnTimes;
}