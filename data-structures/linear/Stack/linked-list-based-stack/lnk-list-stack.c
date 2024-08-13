#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct block{
    int data;
    struct block* next;
    struct block* prev;
}Node;

typedef struct stack{
    Node* top;
}Stack;

Stack* init_stack();


int main(){

    Stack* mystack = init_stack();
   

    return 0;
}

Stack* init_stack(){
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->top = NULL;

    return new_stack;
}