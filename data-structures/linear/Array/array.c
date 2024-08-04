#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int* allocate_memory(int size, int* arr);



int main(){
   

    return 0;
}



int* allocate_memory(int size, int* arr){
    if(arr == NULL){
        int* new_array = (int*)malloc(size*sizeof(int));
        return new_array;
    }else{
        arr = (int*)realloc(arr,size);
        return arr;
    }
}