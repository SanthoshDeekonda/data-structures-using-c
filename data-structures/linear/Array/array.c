#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int* allocate_memory(int size, int* arr);
void display_array(int* arr, int start, int size);


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