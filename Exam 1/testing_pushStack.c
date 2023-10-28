#include <stdio.h>
#include <stdlib.h>


struct stack_array{
    int * items;
    int top; //index AFTER last item
    int capacity;
};

typedef struct stack_array Stack;

void push(Stack * myStack, int newItem) {
    if ((myStack == NULL) || (myStack->top == myStack->capacity))
    {
        printf("The stack is either null or is full.");
    }
    else
    {
        myStack->items[myStack->top] = newItem;
        myStack->top++;
    }

}