#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    struct TreeNode* curr = root;

    while (1) {
        if (val < curr->val) {
            if (curr->left == NULL) {
                curr->left = createNode(val);
                break;
            }
            curr = curr->left;
        } else {
            if (curr->right == NULL) {
                curr->right = createNode(val);
                break;
            }
            curr = curr->right;
        }
    }

    return root;
}

// inorder traversal (to check BST)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insertIntoBST(root, arr[i]);
    }

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}