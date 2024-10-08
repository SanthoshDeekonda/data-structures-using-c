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
bool add_at_position(int data, int pos, DoubleLinkedList** list);
int delete_at_postion(DoubleLinkedList** list, int pos);
void display(DoubleLinkedList* list);





DoubleLinkedList* mylist;

int main(){

    mylist = init_double_list();
    add_at_end(1,&mylist);
    add_at_end(2,&mylist);
    add_at_end(3,&mylist);
    add_at_end(4,&mylist);
    add_at_end(5,&mylist);
    add_at_front(0,&mylist);
    add_at_front(-1,&mylist);
   // delete_at_end(&mylist);
   // delete_at_end(&mylist);
   // delete_at_front(&mylist);
   // delete_at_front(&mylist);
   //add_at_position(9,10,&mylist);
   //delete_at_postion(&mylist,10);
   display(mylist);

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

        free(current);

        return data;
    }

    return -1;
}

int delete_at_front(DoubleLinkedList** list){
    if(!isEmpty(*list)){
        int data;
        Node* temp = (*list)->head;
        (*list)->head->next->prev = NULL;
        (*list)->head = (*list)->head->next;

        data = temp->data;
        free(temp);

        return data;
    }

    return -1;
}


bool add_at_position(int data, int pos, DoubleLinkedList** list){
    Node* new_node = createNode(data);
    if(isEmpty(*list) || pos == 0){
        add_at_front(data,list);

        return true;
    }

    Node* current = (*list)->head;

    while(current != NULL && current->pos != pos){
        current = current->next;
    }

    if(current == NULL){
        printf("\nIndex out of range adding element at end!");
        add_at_end(data,list);

        return true;
    }else{
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;

        arrange_index(&mylist);

        return true;
    }
    return false;
}

int delete_at_postion(DoubleLinkedList** list, int pos){
    if(!isEmpty(*list) && pos == 0){
        return delete_at_front(list);
    }

    Node* current = (*list)->head;
    while(current != NULL && current->pos != pos){
        current = current->next;
    }

    if(current == NULL){
        printf("\nEnter a valid index");

        return -1;
    }else{
        int data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        data = current->data;
        free(current);
        arrange_index(list);
        return data;
    }

    return -1;
}

void display(DoubleLinkedList* list){
    Node* current = list->head;

    while(current){
            printf("___________________________\n");
            printf("| %p  |position:- %d  |",current,current->pos);
            printf("\n----------------------------");
            printf("\n|data:-(%d)|prev:-(%p)|",current->data,current->prev);
            printf("\n|next:-(%p)           |",current->next);
            printf("\n|__________________________|\n");

            current = current->next;
    }
}