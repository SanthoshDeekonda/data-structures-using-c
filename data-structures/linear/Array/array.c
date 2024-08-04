#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//declaring a static integer array
int int_arr[SIZE];

int display();//declaring display function
int* dynamic_array(int size);//declaring dynamic array function
void display_array(int length, int* array);//declaring function to display array

void add_elements(int* array, int size);

int main(){
    int proceed = 1;
    while(proceed){
        int user_selection = display();
        switch(user_selection){
            case 1:
                add_elements(int_arr,SIZE);
                proceed = 0;
        }
    }


    return 0;
}

int display(){
    int selection;
    printf("----basic array demonstration----\n");
    printf("\n1.add elements to static array");
    printf("\n2.create dynamic array");
    printf("\n3.display static array");
    printf("\n4.display dynamic array");
    printf("\n5.retrieve elements using index");
    printf("\n6.exit");
    printf("\n\nselect: ");
    scanf("%d",&selection);
}

void add_elements(int* array, int size){
    int input_data;
    for(int i=0; i<size; i++){
        printf("Enter integer: ");
        scanf("%d", &input_data);
        array[i] = input_data;
    }
}
