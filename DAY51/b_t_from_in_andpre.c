#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value)
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
        {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex)
{
    if(inStart > inEnd)
    {
        return NULL;
    }

    int rootValue = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = createNode(rootValue);

    if(inStart == inEnd)
    {
        return root;
    }

    int inIndex = findIndex(inorder, inStart, inEnd, rootValue);

    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void postorder(struct TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main()
{
    int n;
    scanf("%d", &n);

    int preorder[n];
    int inorder[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;
    struct TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}