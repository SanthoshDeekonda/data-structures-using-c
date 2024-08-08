#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Block{
    int data;
    int pos;
    struct Block* next;
    struct Block* prev;
}Node;

typedef struct DoubleLinkedList{
    Node* head;
}DoubleLinkedList;


DoubleLinkedList* init_double_list();
Node* createNode(int data);

int main(){


    return 0;
}

DoubleLinkedList* init_double_list(){
    DoubleLinkedList* new_list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    new_list->head = NULL;

    return new_list;
};

Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->pos = 0;

    return new_node;
}

