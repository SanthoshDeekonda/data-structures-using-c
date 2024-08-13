#include <stdio.h>
#include <stdbool.h>
#define SIZE 5


int Queue[SIZE],front = 0,rear = -1;

bool isEmpty();
bool isFull();
bool enqueue(int data);
int dequeue();

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

        return true;
    }else{
        printf("\nqueue is Empty");

        return false;
    }
}

int dequeue(){
    if(!isEmpty()){
        int data = Queue[front];
        for(int i=0;i<rear; i++){
            Queue[i] = Queue[i+1];
        }
        rear--;

        return data;
    }

    printf("\nQueue is Empty");
    return false;
}