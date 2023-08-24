#include <stdlib.h>
#include <stdio.h>

typedef struct sNode{
    struct sNodo* prev;
    struct sNodo* next;
    int data;
} Node;

typedef struct sList{
    struct sNodo* head;
    struct sNodo* tail;
    int size;
} List;

Node* createNode(int);
List* createList();
int emptyList(List*);
void insert(List*, Node*, int);
void remove(List*, Node*);
void search(List*, Node*);

int main(){
    return 0;
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

List* createList(){
    List* list;
    list=(List*)malloc(sizeof(List));
    if(list!=NULL){
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
}

int emptyList(List* list){
    if(list->size=0)
        return 1;
    return 0;
}

void insert(List* list, Node* node, int data){
    Node* new_element;
    Node* element;
    new_element = createNode(data);

    if(node==NULL){
        if(emptyList(list)){
            list->tail=new_element;
        }else{
            element = list->head;
            element->prev = new_element;
        }
    
        new_element->next=list->head;
        list->head=new_element;
    }else{
        if(node->next==NULL){
            list->tail=new_element;
        }else{
            element=node->next;
            element->prev=new_element;
        }
            
        new_element->next=node->next;
        new_element->prev=node;
        node->next=new_element;
    }
    list->size++;
}