#include <stdio.h>

typedef struct TreeNode *TreeNodePT;

struct TreeNode {
    int data;
    TreeNodePT left;
    TreeNodePT right;
};

void postorder(TreeNodePT h)
{
    if (h == NULL)
        return;

    postorder(h->left);
    postorder(h->right);
    do_something(h);

}