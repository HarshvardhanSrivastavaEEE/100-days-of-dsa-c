#include <stdio.h>

int main()
{
    char a[100];
    scanf("%s", a);

    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }

    for (int k = 0; k < i; k++)
    {
        if (a[k] >= 65 && a[k] <= 90)
        {
            a[k] = a[k] + 32;
        }
    }

    int low = 0;
    int high = i - 1;

    while (low < high)
    {
        if (a[low] != a[high])
        {
            printf("NO");
            return 0;
        }
        low++;
        high--;
    }

    printf("YES");
    return 0;
}
