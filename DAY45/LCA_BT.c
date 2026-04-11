#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    if (val < root->val)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);

    struct TreeNode* p = findNode(root, p_val);
    struct TreeNode* q = findNode(root, q_val);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}