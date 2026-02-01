#include <stdio.h>

int main()
{
    int n, position, value;
    int arr[100];

    printf("Enter number of elements you want in your array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position you want to insert at: ");
    scanf("%d", &position);

    printf("Enter the value to be inserted: ");
    scanf("%d", &value);

    for(int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    n++;

    printf("Array after insertion:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
