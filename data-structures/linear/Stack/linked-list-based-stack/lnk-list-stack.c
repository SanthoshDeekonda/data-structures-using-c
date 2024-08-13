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
bool push(Stack** stack, int data);
int pop(Stack** stack);


int main(){

    Stack* mystack = init_stack();
    push(&mystack, 1);
    push(&mystack, 2);
   

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

bool push(Stack** stack, int data){
    Node* new_node = create_node(data);
    new_node->prev = (*stack)->top;
    (*stack)->top = new_node;

    return true;
}

int pop(Stack** stack){
    if(!isEmpty((*stack))){
        Node* temp = (*stack)->top;
        (*stack)->top = (*stack)->top->prev;
        (*stack)->top->next = NULL;

        int data = temp->data;
        free(temp);
        return data;
    }else{
        printf("\nStack is Empty");
    }
}