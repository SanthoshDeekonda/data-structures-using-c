#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int* allocate_memory(int size, int* arr);
void display_array(int* arr, int start, int size);
int display_home();
int array_selection();

int selection,d_size,n_ele,user_choice,proceed = 1;

int main(){
    int Static_Array[SIZE];
    int* dynamic_array = NULL;
    while(proceed){
        selection = display_home();
        switch(selection){
            case 1:
                if(dynamic_array == NULL){
                    printf("\nEnter the size of the array: ");
                    scanf("%d",&d_size);
                    dynamic_array = allocate_memory(d_size,dynamic_array);
                    n_ele = 0;
                    printf("\nMemory Allocation successful Array of size %d created", d_size);
                }else{
                    printf("\ndynamic array of size %d already created do you want to reallocate memory?(0/1) ", d_size);
                    scanf("%d",&user_choice);
                    if(user_choice == 1){
                        printf("\nEnter size grater then the previous size %d: ",d_size);
                        scanf("%d",&d_size);
                        dynamic_array = allocate_memory(d_size,dynamic_array);
                        printf("\nrellocation successful");
                    }
                }
                break;
            case 2:
                
                
        }
    }
    

    return 0;
}



int* allocate_memory(int size, int* arr){
    if(arr == NULL){
        arr = (int*)malloc(size*sizeof(int));
        return arr;
    }else{
        arr = (int*)realloc(arr,size);
        return arr;
    }
}

void display_array(int* arr, int start, int size){
    for(int i = start; i<size; i++){
        printf("[%d] at index-> %d\n",arr[i],i);
    }
}

int display_home(){
    int user_selection;
    printf("\n1.create dynamic array");
    printf("\n2.insert elements");
    printf("\n3.access with index");
    printf("\n4.display");
    printf("\n5.exit");
    printf("\nSelect option: ");
    scanf("%d",&user_selection);
    system('cls');

    return user_selection;
}

int array_selection(){
    int arr;
    printf("\n1.static Array\n2.Dynamic array\nChoice: ");
    scanf("%d", &arr);
}