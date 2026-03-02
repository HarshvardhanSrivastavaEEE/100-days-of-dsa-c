#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

static struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Malloc failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

static void append(struct Node** head, int value) {
    struct Node* new_node = create_node(value);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

static int length_and_tail(struct Node* head, struct Node** tail_out) {
    int len = 0;
    struct Node* temp = head;
    struct Node* tail = NULL;

    while (temp != NULL) {
        len++;
        tail = temp;
        temp = temp->next;
    }

    if (tail_out != NULL) {
        *tail_out = tail;
    }
    return len;
}

static struct Node* rotate_right(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    struct Node* tail = NULL;
    int n = length_and_tail(head, &tail);

    k = k % n;
    if (k == 0) {
        return head;
    }

    tail->next = head;

    int steps = n - k;
    struct Node* new_tail = head;
    for (int i = 1; i < steps; i++) {
        new_tail = new_tail->next;
    }

    struct Node* new_head = new_tail->next;
    new_tail->next = NULL;

    return new_head;
}

static void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
}

static void free_list(struct Node* head) {
    while (head != NULL) {
        struct Node* next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        append(&head, x);
    }

    int k;
    scanf("%d", &k);

    head = rotate_right(head, k);

    print_list(head);
    free_list(head);

    return 0;
}