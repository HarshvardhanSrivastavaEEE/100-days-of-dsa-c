#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;
}

void display()
{
    if (front == -1)
    {
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);
        if (i < rear)
        {
            printf(" ");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}