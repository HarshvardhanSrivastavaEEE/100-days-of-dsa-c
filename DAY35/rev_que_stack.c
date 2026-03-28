#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n, x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    for(int i = 0; i < n; i++)
    {
        push(dequeue());
    }

    for(int i = 0; i < n; i++)
    {
        enqueue(pop());
    }

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}