#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* make(int v)
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->val = v;
    t->left = t->right = NULL;
    return t;
}

struct Node* build(int a[], int n)
{
    if (n == 0 || a[0] == -1) return NULL;

    struct Node* root = make(a[0]);
    struct Node* q[100];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n)
    {
        struct Node* cur = q[f++];

        if (a[i] != -1)
        {
            cur->left = make(a[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && a[i] != -1)
        {
            cur->right = make(a[i]);
            q[r++] = cur->right;
        }
        i++;
    }

    return root;
}

void level(struct Node* root)
{
    if (!root) return;

    struct Node* q[100];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r)
    {
        int k = r - f;

        for (int i = 0; i < k; i++)
        {
            struct Node* t = q[f++];
            printf("%d ", t->val);

            if (t->left) q[r++] = t->left;
            if (t->right) q[r++] = t->right;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct Node* root = build(a, n);

    level(root);

    return 0;
}