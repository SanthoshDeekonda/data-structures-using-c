#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct block{
    int data;
    struct block* next;
}Node;

typedef struct queue{
    Node* front;
    Node* rear;
}Queue;

Queue* init_queue();
Node* create_node(int data);
bool enqueue(Queue** queue, int data);
bool isEmpty(Queue* queue);


int main(){

    Queue* myqueue = init_queue();
    
    

    return 0;
}

Queue* init_queue(){
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;

    return new_queue;
}

Node* create_node(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = data;

    return new_node;
}

bool isEmpty(Queue* queue){
    return queue->front == NULL;
}
