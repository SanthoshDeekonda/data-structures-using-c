#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//node structure
typedef struct Block{
    int data;
    int pos;
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
bool add_at_position(int data, int pos, Singlelinkedlist** LinkedList);
int delete_end_node(Singlelinkedlist** LinkedList);
int delete_front_node(Singlelinkedlist** LinkedList);
int delete_at_position(int pos, Singlelinkedlist** LinkedList);
void arrange_position(Singlelinkedlist** LinkedList);
void display(Singlelinkedlist** LinkedList);




Singlelinkedlist* myList;

int main(){

    myList = init_single_LinkedList();
    add_at_end(1,&myList);
    add_at_end(2,&myList);
    add_at_end(3,&myList);
    add_at_front(0,&myList);
    add_at_front(-1,&myList);
    add_at_front(-2,&myList);
    add_at_front(-3,&myList);
    display(&myList);
    delete_end_node(&myList);
    delete_front_node(&myList);
    delete_at_position(3,&myList);
    printf("\n\n");
    display(&myList);
    
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
    new_node->pos = 0;
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
        arrange_position(LinkedList);
        return true;
    }else{
        Node* current = (*LinkedList)->head;
        while(current->next){
            current = current->next;
        }
        current->next = new_node;
        arrange_position(LinkedList);
        return true;
    }

    return false;
}

bool add_at_front(int data, Singlelinkedlist** LinkedList){
    Node* new_node = createNode(data);
    new_node->next = (*LinkedList)->head;
    (*LinkedList)->head = new_node;
    arrange_position(LinkedList);

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
        arrange_position(LinkedList);
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
        arrange_position(LinkedList);
        return data;
    }else{
        printf("\nList is empty");
        return -1;
    }
}

void arrange_position(Singlelinkedlist** LinkedList){
    int index_pos = 0;
    Node* current = (*LinkedList)->head;
    while(current){
        current->pos = index_pos++;
        current = current->next;
    }
}

int delete_at_position(int pos, Singlelinkedlist** LinkedList){
    if(!isEmpty(*LinkedList)){
        int data;
        Node* current = (*LinkedList)->head;
        Node* prev = NULL;
        Node* temp = NULL;

        if(pos == 0){
            temp = (*LinkedList)->head;
            (*LinkedList)->head = (*LinkedList)->head->next;
            data = temp->data;
            free(temp);
            
            return data;
        }

        while(current != NULL && current->pos != pos){
            prev = current;
            current = current->next;
        }

        if(current == NULL){
            printf("\n Check the index you enterd and try again");

            return -1;
        }

        temp = current;
        prev->next = current->next;
        data = temp->data;
        free(temp);
        arrange_position(LinkedList);
        return data;
    }else{
        printf("\nList is empty");

        return -1;
    }
    
}

bool add_at_position(int data, int pos, Singlelinkedlist** LinkedList){
    Node* current = (*LinkedList)->head;
    Node* prev = NULL;
    if(isEmpty(*LinkedList) || pos == 0){
        add_at_front(data, LinkedList);
        arrange_position(LinkedList);

        return true;
    }

    while(current != NULL && current->pos != pos){
        prev = current;
        current = current->next;
    }

    if(current == NULL){
        printf("\n Index out of List length adding data at end!");
        add_at_end(data,LinkedList);
        return true;
    }

    Node* new_node = createNode(data);
    prev->next = new_node;
    new_node->next = current;
    arrange_position(LinkedList);

    return true;

}


void display(Singlelinkedlist** LinkedList){
    if(!isEmpty(*LinkedList)){
        Node* current = (*LinkedList)->head;

        while(current){
            printf("___________________________\n");
            printf("| %p  |position:- %d  |",current,current->pos);
            printf("\n----------------------------");
            printf("\n|data:-(%d)|next:-(%p)|",current->data,current->next);
            printf("\n|__________________________|\n");

            current = current->next;
        }
    }
}