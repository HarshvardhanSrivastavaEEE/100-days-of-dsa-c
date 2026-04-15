#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isMirror(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    if (a->data != b->data) return 0;

    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) {
        printf("YES\n");
        return 0;
    }

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct Node* root = nodes[0];

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}