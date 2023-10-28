#include <stdio.h>

typedef struct TreeNode *TreeNodePT;

struct TreeNode {
    int data;
    TreeNodePT left;
    TreeNodePT right;
};

void preorder(TreeNodePT h)
{
    if (h == NULL)
        return;

    do_something(h);
    preorder(h->left);
    preorder(h->right);

}
