#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

#endif