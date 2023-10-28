#include <stdlib.h>
#include <stdio.h>

struct node 
{
    int data;
    struct node * next;
};

typedef struct node * nodePT ;

nodePT reverseList(nodePT head){
    nodePT currNode = head;
    nodePT prevNode = NULL;
    nodePT next;

    while(currNode!=NULL)
    {
        next = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = next;
    }
    return prevNode;
}