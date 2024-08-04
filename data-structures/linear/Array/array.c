#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//declaring a static integer array
int int_arr[SIZE];

int display();//declaring display function
int* dynamic_array(int size);//declaring dynamic array function
void display_array(int length, int* array);//declaring function to display array

int main(){

    

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

