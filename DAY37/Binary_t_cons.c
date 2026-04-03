#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* build_tree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
    {
        return NULL;
    }

    struct Node* root = create_node(arr[0]);

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n)
    {
        struct Node* current = queue[front++];

        // LEFT CHILD
        if (i < n && arr[i] != -1)
        {
            current->left = create_node(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // RIGHT CHILD
        if (i < n && arr[i] != -1)
        {
            current->right = create_node(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

void inorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node* root = build_tree(arr, n);

    inorder(root);

    return 0;
}