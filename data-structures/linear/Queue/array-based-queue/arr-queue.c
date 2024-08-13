#include <stdio.h>
#include <stdbool.h>
#define SIZE 5


int Queue[SIZE],front = -1,top = -1;

bool isEmpty();
bool isFull();


int main(){

    printf("%d", isEmpty());
    printf("%d", isFull());


    return 0;
}

bool isEmpty(){
    return front == -1 && top == -1;
}

bool isFull(){
    return top == (SIZE - 1);
}