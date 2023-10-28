#include <stdio.h>

typedef struct TreeNode *TreeNodePT;

struct TreeNode {
    int data;
    TreeNodePT left;
    TreeNodePT right;
};

int search(TreeNodePT tree, int s_data)
{
    if (tree == NULL)
        return NULL;   

    else if (s_data == tree->data)
        return tree;

    else if (s_data < tree->data)
        return search(tree->left, s_data);
        
    else 
        return search(tree->right, s_data);

}