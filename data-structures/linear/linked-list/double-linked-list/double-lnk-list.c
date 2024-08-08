#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Block{
    int data;
    struct Block* next;
    struct Block* prev;
}Node;

typedef struct DoubleLinkedList{
    Node* head;
}DoubleLinkedList;

int main(){


    return 0;
}
