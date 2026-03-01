#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void createAndTraverse(int n) {
    if (n <= 0) return;

    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    if (tail != NULL) {
        tail->next = head;
    }

    
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head); 
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        createAndTraverse(n);
    }
    return 0;
}