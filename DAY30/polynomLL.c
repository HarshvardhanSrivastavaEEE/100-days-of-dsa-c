#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(struct Node** head, int coeff, int exp)
{
    struct Node* newNode = createNode(coeff, exp);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printPolynomial(struct Node* head)
{
    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->exp > 1)
        {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        else if (temp->exp == 1)
        {
            printf("%dx", temp->coeff);
        }
        else
        {
            printf("%d", temp->coeff);
        }

        if (temp->next != NULL)
        {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");
}

void freeList(struct Node* head)
{
    struct Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&head, coeff, exp);
    }

    printPolynomial(head);
    freeList(head);

    return 0;
}