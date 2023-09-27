#include <stdlib.h>
#include <stdio.h>

typedef struct sNode{
    struct sNode *prev;
    struct sNode *next;
    int data;
} Node;

typedef struct sList{
    struct sNode* head;
    struct sNode* tail;
    int size;
} List;

Node* createNode(int);
List* createList();
int emptyList(List*);
void errors(int);
void insertNode(List*, Node*, int);
int removeNode(List*, Node*);
Node* search(List*, int);
void readList(List*);

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
    if(list->size==0)
        return 1;
    return 0;
}

void errors(int error){
    if(error == -1)
        printf("List Underflow");
    else if(error == -2){
        printf("End of list");
    }
}

void insertNode(List* list, Node* node, int data){
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

int removeNode(List* list, Node* node){
    int removed;
    if ((node != NULL) && (!emptyList(list))){
        if (node == list->head){
            list->head = node->next;
            if (list->head == NULL)
                list->tail = NULL;
            else
                node->next->prev = NULL;
        } else {
            node->prev->next = node->next;
            if (node->next == NULL)
                list->tail = node->prev;
            else
                node->next->prev = node->prev;
        }
        removed = node->data;
        free(node);
        list->size--;
        return removed;
    } else
        return -1;
}

void readList(List* list){
    Node* node;

    if(emptyList(list))
        errors(-1);
    else{
        node = list->head;
        while(node!=NULL){
            printf("%i, ", node->data);
            node = node->next;
        }
    }
}

Node* search(List* list, int data){
    Node* node;
    if(emptyList(list)){
        errors(-1);
    }else{
        node=list->head;
        while(node!=NULL){
            if(node->data==data){
                return node;
            }
            node=node->next;
        }
        return NULL;
    }
}