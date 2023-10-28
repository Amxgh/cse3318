#include <stdio.h>

typedef struct TreeNode *TreeNodePT;

struct TreeNode {
    int data;
    TreeNodePT left;
    TreeNodePT right;
};

int count(TreeNodePT h)
{
    if (h == NULL)
        return 0; 
          
    int c1 = count(h->left);
    int c2 = count(h->right);
    return c1 + c2 + 1;
}