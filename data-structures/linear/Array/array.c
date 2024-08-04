#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int* allocate_memory(int size, int* arr);
void display_array(int* arr, int start, int size);
int display_home();
int array_selection();
void insert_elements(int* arr, int size, int start);
void inspect_element(int index, int* arr);

int selection,d_size,n_ele,user_choice,proceed = 1;
int indx;

int main(){
    int Static_Array[SIZE];
    int* dynamic_array = NULL;
    while(selection != 5){
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
                user_choice = array_selection();
                if(user_choice == 1){
                    insert_elements(Static_Array,SIZE,0);
                }else if(user_choice == 2){
                    if(dynamic_array == NULL){
                        printf("\ndynamic array is not created or not allocated memory!");
                        break;
                    }else{
                        insert_elements(dynamic_array,d_size,n_ele);
                        n_ele = d_size;
                    }
                }else{
                    printf("\nSomthng went wrong");
                    break;
                }
                printf("\nInsertion successful");
                break;
            case 3:
                user_choice = array_selection();
                if(user_choice == 1){
                    display_array(Static_Array,0,SIZE);
                }else if(user_choice == 2){
                    if(dynamic_array != NULL){
                        display_array(dynamic_array,0,d_size);
                    }else{
                        printf("\narray is empty");
                        break;
                    }
                }else{
                    printf("\nsomething went wrong");
                }
                break;
            
            case 4:
                user_choice = array_selection();
                if(user_choice == 1){
                    display_array(Static_Array,0,SIZE);
                    printf("\nEnter the index of the element: ");
                    scanf("%d",&indx);
                    inspect_element(indx,Static_Array);
                    display_array(Static_Array,0,SIZE);
                }else if(user_choice == 2){
                    if(dynamic_array != NULL){
                        display_array(dynamic_array,0,d_size);
                        printf("\nEnter the index of the element: ");
                        scanf("%d",&indx);
                        inspect_element(indx,dynamic_array);
                        printf("\n");
                        display_array(dynamic_array,0,d_size);
                    }else{
                       printf("\ndynamic array is not created or not allocated memory!");
                    }
                    
                }else{
                    printf("\nsomething went wrong");
                }
                break;
            case 5:
                system("cls");
                printf("\nterminated");
                break;

            default:
                printf("\ncheck the option");
                break;
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
        printf("[%d] at index-> %d address:- %p\n",arr[i],i,&arr[i]);

    }
}

int display_home(){
    int user_selection;
    printf("\n1.create dynamic array");
    printf("\n2.insert elements");
    printf("\n3.display");
    printf("\n4.access with index");
    printf("\n5.exit");
    printf("\nSelect option: ");
    scanf("%d",&user_selection);
    system("cls");

    return user_selection;
}

int array_selection(){
    int arr;
    printf("\n1.static Array\n2.Dynamic array\nChoice: ");
    scanf("%d", &arr);

    return arr;
}

void insert_elements(int* arr, int size, int start){
    int ele;
    for(int i=start; i<size; i++){
        printf("Enter the Element at index %d: ",i);
        scanf("%d",&ele);
        arr[i] = ele;
    }
}

void inspect_element(int index, int* arr){
    int mode_selection,new_ele;
    printf("Element:- %d\nIndex:- %d\n Address:- %p",arr[index],index,&arr[index]);
    printf("\nDo you want to modify the element(0/1): ");
    scanf("%d",&mode_selection);
    if(mode_selection == 1){
        printf("Enter the new element: ");
        scanf("%d",&new_ele);
        arr[index] = new_ele;
    }
}