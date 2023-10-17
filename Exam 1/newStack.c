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
    Stack res;
    //Item temp[cap];  res.items = temp; // BAD
    res.items = malloc(cap*sizeof(int));
    res.capacity = cap;
    res.top = 0;
    return res;
}

