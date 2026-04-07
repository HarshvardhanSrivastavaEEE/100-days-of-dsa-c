#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create(int value)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    if(l > r)
    {
        return l + 1;
    }
    return r + 1;
}

int main()
{
    struct TreeNode* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    int height = maxDepth(root);

    printf("Height of tree: %d", height);

    return 0;
}