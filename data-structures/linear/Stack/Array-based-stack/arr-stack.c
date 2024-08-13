#include <stdio.h>
#include <stdbool.h>
#define SIZE 5




int STACK[SIZE],top = -1;
bool push(int* stack, int data);
bool isEmpty(int top);
bool isFull(int top);
int pop(int* stack);
int peek(int* stack);
void display();


int main(){

    push(STACK, 1);
    push(STACK, 2);
    push(STACK, 3);
    push(STACK, 4);
    push(STACK, 5);
    pop(STACK);

    display();
   
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

void display(){
    if(!isEmpty(top)){
        for(int i=top; i>=0; i--){
            printf("\n|%d|", STACK[i]);
        }
    }
}