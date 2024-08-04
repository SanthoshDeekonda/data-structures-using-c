#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//node structure
typedef struct Block{
    int data;
    struct Block* next;
}Node;

//linked list structured 
typedef struct LinkedList{
    Node* head;
}Singlelinkedlist;

Singlelinkedlist* init_single_LinkedList();
Node* createNode(int data);
bool isEmpty(Singlelinkedlist* LinkedList);
bool add_at_end(int data, Singlelinkedlist** LinkedList);


Singlelinkedlist* myList;

int main(){

    myList = init_single_LinkedList();


    


    return 0;
}

Singlelinkedlist* init_single_LinkedList(){
    Singlelinkedlist* new_list = (Singlelinkedlist*)malloc(sizeof(Singlelinkedlist));
    new_list->head = NULL;

    return new_list;
}

Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

bool isEmpty(Singlelinkedlist* LinkedList){
    return LinkedList->head == NULL;
}

bool add_at_end(int data, Singlelinkedlist** LinkedList){
    Node* new_node = createNode(data);
    if(isEmpty(*LinkedList)){
        (*LinkedList)->head = new_node;

        return true;
    }else{
        Node* current = (*LinkedList)->head;
        while(current->next){
            current = current->next;
        }
        current->next = new_node;

        return true;
    }

    return false;
}