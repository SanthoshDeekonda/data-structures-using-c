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
bool add_at_front(int data, Singlelinkedlist** LinkedList);
int delete_end_node(Singlelinkedlist** LinkedList);
int delete_front_node(Singlelinkedlist** LinkedList);



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

bool add_at_front(int data, Singlelinkedlist** LinkedList){
    Node* new_node = createNode(data);
    new_node->next = (*LinkedList)->head;
    (*LinkedList)->head = new_node;

    return true;
}

int delete_end_node(Singlelinkedlist** LinkedList){
    if(!isEmpty(*LinkedList)){
        Node* current = (*LinkedList)->head;
        Node* prev = NULL;
        int data;

        while(current->next){
            prev = current;
            current = current->next;
        }
        
        if(prev != NULL){
            prev->next = NULL;
            data = current->data;
            free(current);
            return data;
        }

        data = current->data;
        free(current);
        (*LinkedList)->head = NULL;

        return data;

    }else{
        printf("\nList is empty");

        return -1;
    }
}

int delete_front_node(Singlelinkedlist** LinkedList){
    if(!isEmpty(*LinkedList)){
        int data;
        Node* temp = (*LinkedList)->head;
        (*LinkedList)->head = (*LinkedList)->head->next;
        data = temp->data;
        free(temp);

        return data;
    }else{
        printf("\nList is empty");
        return -1;
    }
}