#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int low = 0, high = n;
    int lower = n;

    while(low < high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] >= x)
        {
            lower = mid;
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    low = 0;
    high = n;
    int upper = n;

    while(low < high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > x)
        {
            upper = mid;
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%d %d", lower, upper);

    return 0;
}