#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int* allocate_memory(int size, int* arr);
void display_array(int* arr, int start, int size);
int display_home();


int main(){
    int Static_Array[SIZE];
    int* dynamic_array = NULL;
    

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

    return user_selection;
}