#include <stdio.h>
#include <stdbool.h>
#define SIZE 5




int STACK[SIZE],top = -1;
bool push(int* stack, int data);
bool isEmpty(int top);
bool isFull(int top);
int pop(int* stack);
int peek(int* stack);


int main(){

   
    return 0;
}

bool isEmpty(int top){
    return top == -1;
}

bool isFull(int top){
    return top == SIZE - 1;
}

bool push(int* stack, int data){
    if(!isFull(top)){
        stack[++top] = data;
        return true;
    }else{
        printf("\nStack overflow");
        return false;
    }
}

int pop(int* stack){
    if(!isEmpty(top)){
        return stack[top--];
    }else{
        printf("\nStack is Empty");

        return -1;
    }
}

int peek(int* stack){
    return stack[top];
}