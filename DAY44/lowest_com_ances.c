#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int findLCA(struct Node* root, int a, int b) {
    while (root != NULL) {
        if (a < root->data && b < root->data) {
            root = root->left;
        } else if (a > root->data && b > root->data) {
            root = root->right;
        } else {
            return root->data;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    int x, y;
    scanf("%d %d", &x, &y);

    int lca = findLCA(root, x, y);
    printf("%d\n", lca);

    return 0;
}