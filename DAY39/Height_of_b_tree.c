#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Height function
int height(Node* root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

// Build tree from level order
Node* build_tree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = create_node(arr[0]);

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n)
    {
        Node* current = queue[front++];

        // left child
        if (arr[i] != -1)
        {
            current->left = create_node(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // right child
        if (i < n && arr[i] != -1)
        {
            current->right = create_node(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = build_tree(arr, n);

    printf("%d", height(root));

    return 0;
}