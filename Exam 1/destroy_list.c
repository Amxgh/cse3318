#include <stdlib.h>
#include <stdio.h>

struct node 
{
    int data;
    struct node * next;
};

typedef struct node * nodePT ;

nodePT destroy_list(nodePT currNode)
{
    nodePT tempPtr = currNode;
    
    while (tempPtr != NULL)
    {
        currNode = tempPtr->next;
        free(tempPtr);
        tempPtr = currNode;
    }

    return NULL;
}


// EVERYTHING BELOW THIS LINE IS ADDED FOR TESTING PURPOSES. IGNORE.

nodePT array_2_list(int arr[], int N) {
    int j;
    nodePT lastPtr = NULL, newPtr=NULL;
    
    nodePT head = malloc(sizeof(struct node));

    head->data = arr[0];
    head->next = NULL;

    lastPtr = head;

    for (j = 1; j<N; j++) {
        newPtr = malloc(sizeof(struct node));

        newPtr->data = arr[j];
        newPtr->next = NULL;
        
        lastPtr->next = newPtr;
        lastPtr = newPtr;
    }
    return head;  // line 13
}

// EVERYTHING BELOW THIS LINE IS NOT REQUIRED. ADDED TO THIS PROGRAM FOR TESTING PURPOSES.

int main()
{
    int array[] = {1,2,3,4,5,6,7,8};

    nodePT head = array_2_list(array, 8);
    nodePT tempPtr = head;

    while (tempPtr != NULL)
    {
        printf("%d\n", tempPtr->data);

        tempPtr = tempPtr ->next;
    }
    destroy_list(head);
    return 0;

}