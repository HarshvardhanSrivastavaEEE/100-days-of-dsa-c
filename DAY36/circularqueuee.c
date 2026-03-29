#include <stdio.h>

#define MAX 1000

int main()
{
    int queue[MAX];
    int n, m;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    // perform m dequeue operations
    for (int i = 0; i < m; i++)
    {
        if (front != -1)
        {
            front = (front + 1) % n;
        }
    }

    // print queue from front to rear
    int count = n;
    int i = front;

    while (count--)
    {
        printf("%d", queue[i]);
        if (count > 0)
        {
            printf(" ");
        }
        i = (i + 1) % n;
    }

    return 0;
}