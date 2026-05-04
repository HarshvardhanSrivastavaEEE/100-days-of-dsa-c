#include <stdio.h>

int maxLenZeroSum(int arr[], int n)
{
    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum = sum + arr[j];

            if(sum == 0)
            {
                int len = j - i + 1;

                if(len > maxLen)
                {
                    maxLen = len;
                }
            }
        }
    }

    return maxLen;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = maxLenZeroSum(arr, n);

    printf("%d", ans);

    return 0;
}