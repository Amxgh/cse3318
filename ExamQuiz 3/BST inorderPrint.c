#include <stdio.h>

typedef struct TreeNode *TreeNodePT;

struct TreeNode {
    int data;
    TreeNodePT left;
    TreeNodePT right;
};

void inorder(TreeNodePT h)
{
    if (h == NULL)
        return;

    inorder(h->left);
    do_something(h);
    inorder(h->right);

}