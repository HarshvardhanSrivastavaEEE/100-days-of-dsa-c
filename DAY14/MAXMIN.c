#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = INT_MIN;   // smallest possible integer
    int min = INT_MAX;   // largest possible integer

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
