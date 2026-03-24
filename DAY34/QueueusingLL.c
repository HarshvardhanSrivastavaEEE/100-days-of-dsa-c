#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return val;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') { // enqueue
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else { // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}