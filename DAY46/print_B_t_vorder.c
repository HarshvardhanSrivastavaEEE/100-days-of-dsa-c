#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int val;
    struct Tree* l;
    struct Tree* r;
};

struct Tree* makeNode(int x) {
    struct Tree* t = (struct Tree*)malloc(sizeof(struct Tree));
    t->val = x;
    t->l = NULL;
    t->r = NULL;
    return t;
}

struct Tree* q1[1000];
int s = 0, e = 0;

void add(struct Tree* t) {
    q1[e++] = t;
}

struct Tree* removeQ() {
    return q1[s++];
}

void printVertical(struct Tree* root) {
    struct Tree* q2[1000];
    int pos[1000];
    int f = 0, b = 0;

    int store[2000][100];
    int cnt[2000] = {0};

    int left = 0, right = 0;

    q2[b] = root;
    pos[b++] = 0;

    while (f < b) {
        struct Tree* cur = q2[f];
        int p = pos[f++];
        
        if (p < left) left = p;
        if (p > right) right = p;

        store[p + 1000][cnt[p + 1000]++] = cur->val;

        if (cur->l) {
            q2[b] = cur->l;
            pos[b++] = p - 1;
        }
        if (cur->r) {
            q2[b] = cur->r;
            pos[b++] = p + 1;
        }
    }

    for (int i = left; i <= right; i++) {
        for (int j = 0; j < cnt[i + 1000]; j++) {
            printf("%d ", store[i + 1000][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 0 || a[0] == -1) return 0;

    struct Tree* root = makeNode(a[0]);
    add(root);

    int i = 1;

    while (i < n) {
        struct Tree* temp = removeQ();

        if (i < n && a[i] != -1) {
            temp->l = makeNode(a[i]);
            add(temp->l);
        }
        i++;

        if (i < n && a[i] != -1) {
            temp->r = makeNode(a[i]);
            add(temp->r);
        }
        i++;
    }

    printVertical(root);
    return 0;
}