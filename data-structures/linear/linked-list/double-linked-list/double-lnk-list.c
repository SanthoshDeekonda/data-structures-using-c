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
bool add_at_end(int data, DoubleLinkedList** list);
bool add_at_front(int data, DoubleLinkedList** list);
bool isEmpty(DoubleLinkedList* list);
void arrange_index(DoubleLinkedList** list);
int delete_at_end(DoubleLinkedList** list);
int delete_at_front(DoubleLinkedList** list);




DoubleLinkedList* mylist;

int main(){

    mylist = init_double_list();
   


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

bool isEmpty(DoubleLinkedList *list){
    return list->head == NULL;
}

bool add_at_end(int data, DoubleLinkedList** list){
    Node* new_node = createNode(data);
    if(isEmpty(*list)){
        (*list)->head = new_node;
        arrange_index(list);

        return true;
    }else{
        Node* current = (*list)->head;
        while(current->next){
            current = current->next;
        }

        new_node->prev = current;
        current->next = new_node;
        arrange_index(list);
        return true;
    }

    return false;
}

bool add_at_front(int data, DoubleLinkedList** list){
    Node* new_node = createNode(data);
    if(isEmpty(*list)){
        (*list)->head = new_node;
        arrange_index(list);
        return true;
    }else{
        new_node->next = (*list)->head;
        (*list)->head->prev = new_node;
        (*list)->head = new_node;
        arrange_index(list);
        return true;
        
    }

    return false;
}

void arrange_index(DoubleLinkedList** list){
    if(!isEmpty(*list)){
        Node* current = (*list)->head;
        int i=0;
        while(current){
            current->pos = i;
            current = current->next;
            i++;
        }
    }
}

int delete_at_end(DoubleLinkedList** list){
    Node* current = (*list)->head;
    int data;
    if(!isEmpty(*list)){
        while(current->next){
            current = current->next;
        }

        current->prev->next = NULL;
        current->prev = NULL;
        data = current->data;

        return data;
    }

    return -1;
}