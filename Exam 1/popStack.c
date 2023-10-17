#include <stdio.h>
#include <stdlib.h>


struct stack_array{
    int * items;
    int top; //index AFTER last item
    int capacity;
};

typedef struct stack_array Stack;

int pop(Stack * myStack ) {
    int temp = 0;  // or some other default item value, e.g. -1
    if ((myStack==NULL) || (myStack->top==0)) {
        printf("The stack is empty. Exit");
    }
    else {
        myStack->top--;  // top becomes 1
        temp = myStack->items[myStack->top]; // temp has value 8
    }
    return temp;
}
