#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos;

    printf("Enter size: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (!arr) return 0;

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter index to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid index\n");
        free(arr);
        return 0;
    }

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;

    int *temp = realloc(arr, n * sizeof(int));
    if (temp != NULL)
        arr = temp;

    printf("After deletion:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
