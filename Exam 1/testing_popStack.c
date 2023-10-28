#include <stdio.h>
#include <stdlib.h>


struct stack_array{
    int * items;
    int top; //index AFTER last item
    int capacity;
};

typedef struct stack_array Stack;

int pop(Stack * myStack ) {
    int returnValue = 0;

    if ((myStack == NULL) || (myStack->top == 0))
    {
        printf("Stack is empty\n");
    }
    else
    {
        myStack->top = myStack->top--;
        returnValue = myStack->items[myStack->top];
    }
    return returnValue;

}