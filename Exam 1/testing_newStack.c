#include <stdio.h>
#include <stdlib.h>


struct stack_array{
    int * items;
    int top; //index AFTER last item
    int capacity;
};

typedef struct stack_array Stack;

// struct stack_array S = newStack(9);  // in main
Stack newStack(int cap){
    Stack result;

    result.items = malloc(cap*sizeof(int));
    result.top = 0;
    result.capacity = cap;

    return result;
}