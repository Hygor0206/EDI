#include "../filas/lista.c"

typedef List Stack;

void push(Stack*, int);
int pop(Stack*);
int emptyStack(Stack*);
int stackTop(Stack*);
Stack* newStack();
void readStack(Stack*);

int main()
{
    Stack* expressionStack = newStack();
    char expression1[]="7 - ((x * ((x + y) / (j - 3)) + y) / (4 - 2.5))";
    char expression2[]="( a + b], [(a + b]), {a - (b]}";

    int length = *(&expression1+1)-expression1;
    printf("%d\n", length);
    for(int i=0;i<=length;i++){
        if(expression1[i]=='('){
            push(expressionStack, expression1[i]);
        }
    }
    readStack(expressionStack);
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

void readStack(Stack* s){
    List* listStack = s;
    readList(listStack);
}