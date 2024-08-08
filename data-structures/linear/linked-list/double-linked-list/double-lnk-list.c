#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Block{
    int data;
    struct Block* next;
    struct Block* prev;
}node;

