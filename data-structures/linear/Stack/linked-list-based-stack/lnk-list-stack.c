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
Node* create_node(int data);
bool isEmpty(Stack* stack);
bool push(Stack* stack, int data);


int main(){

    Stack* mystack = init_stack();
   

    return 0;
}

Stack* init_stack(){
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->top = NULL;

    return new_stack;
}

Node* create_node(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

bool isEmpty(Stack* stack){
    return stack->top == NULL;
}