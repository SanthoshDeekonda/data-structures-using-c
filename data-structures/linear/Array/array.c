#include <stdio.h>
#include <stdlib.h>
#define SIZE 10




int display();//declaring display function
int* dynamic_array(int size);//declaring dynamic array function
void display_array(int length, int* array);//declaring function to display array

void add_elements(int* array, int size);

int main(){
    //declaring a static integer array
    int int_arr[SIZE];
    //size of dynamic array
    int dynamic_size;
    //declaring null pointer for dynamic array
    int* int_dynamic_arr = NULL;


    int proceed = 1;
    printf("\n\n----basic array demonstration----\n");
    while(proceed){
        int user_selection = display();
        switch(user_selection){
            case 1:
                add_elements(int_arr,SIZE);
                printf("\n 10 elemnts added to the static array");

                break;
            case 2:
                if(int_dynamic_arr == NULL){
                    printf("\nEnter the size of the array: ");
                    scanf("%d",&dynamic_size);
                    int_dynamic_arr = (int*)malloc(dynamic_size*sizeof(int));
                    printf("memory allocation successful");
                }else{
                    int reallocate;
                    printf("\ndynamic array already created do you want to reallocate memory?(0/1): ");
                    scanf("%d",&reallocate);
                    printf("\nEnter the size of the array: ");
                    scanf("%d",&dynamic_size);
                    if(reallocate == 1){
                        int_dynamic_arr = (int*)realloc(int_dynamic_arr,dynamic_size*sizeof(int));
                        printf("\nreallocated memory");
                    }else if(reallocate == 0){
                        printf("reallocation terminated");
                    }else{
                        printf("something went wrong!");
                    }
                }
                break;
        }
    }


    return 0;
}

int display(){
    int selection;
    printf("\n1.add elements to static array");
    printf("\n2.create dynamic array");
    printf("\n3.display static array");
    printf("\n4.display dynamic array");
    printf("\n5.retrieve elements using index");
    printf("\n6.exit");
    printf("\n\nselect: ");
    scanf("%d",&selection);
    system("cls");

    return selection;
}

void add_elements(int* array, int size){
    int input_data;
    for(int i=0; i<size; i++){
        printf("Enter integer: ");
        scanf("%d", &input_data);
        array[i] = input_data;
    }
}
