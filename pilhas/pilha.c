#include "filas/lista.c"

typedef List Stack;

void push(Stack*, int);
int pop(Stack*);
int emptyStack(Stack*);
int stackTop(Stack*);
Stack* newStack();

int main()
{
    
}

Stack* newStack(){
    return createList();
}

void push(Stack* s, int data){
    insertNode(s, s->tail, data);
}

int pop(Stack* s){
    int removed = removeNode(s, s->tail);
    return removed;
}

int emptyStack(Stack* s){
    return emptyList(s);
}

int stackTop(Stack* s){
    return s->tail->data;
}