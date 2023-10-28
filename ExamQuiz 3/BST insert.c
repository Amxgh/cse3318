#include <stdio.h>

typedef struct TreeNode *TreeNodePT;

struct TreeNode {
    int data;
    TreeNodePT left;
    TreeNodePT right;
};

TreeNodePT new_tree_node(int data_in)
{
    TreeNodePT ndp = malloc(sizeof(struct TreeNode));
    ndp->data = data_in;
    ndp->left = NULL;
    ndp->right = NULL;
    return ndp;
}

TreeNodePT insert(TreeNodePT h, int n_data)
{
    if (h == NULL)
        return new_tree_node(n_data);

    else if (n_data < h->data)
        h->left = insert(h->left, n_data);

    else if (n_data > h->data)
        h->right = insert(h->right, n_data);
        
    return h;
}