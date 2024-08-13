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


int main(){


    return 0;
}