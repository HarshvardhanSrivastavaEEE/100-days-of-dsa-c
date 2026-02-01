#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, position, value;

    printf("Enter number of elements you want in your array: ");
    scanf("%d", &n);

    
    int *arr = (int *)malloc((n + 1) * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation has failed \n");
        return 0;
    }

    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &position);

    if (position < 1 || position > n + 1)
    {
        printf("Invalid position\n");
        free(arr);
        return 0;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    
    for (int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);   
    return 0;
}
