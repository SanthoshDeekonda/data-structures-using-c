#include <stdio.h>
#include <stdbool.h>
#define SIZE 5


int Queue[SIZE],front = 0,rear = -1;

bool isEmpty();
bool isFull();
bool enqueue(int data);


int main(){

    
    


    return 0;
}

bool isEmpty(){
    return rear == -1;
}

bool isFull(){
    return rear == (SIZE - 1);
}

bool enqueue(int data){
    if(!isFull()){
        Queue[++rear] = data;
    }else{
        printf("\nqueue is Empty");
    }
}