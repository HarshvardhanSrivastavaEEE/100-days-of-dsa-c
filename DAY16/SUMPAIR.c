#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int minSum = abs(arr[0] + arr[1]);
    int num1 = arr[0];
    int num2 = arr[1];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int currentSum = arr[i] + arr[j];

            if (abs(currentSum) < minSum)
            {
                minSum = abs(currentSum);
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("%d %d", num1, num2);

    return 0;
}
