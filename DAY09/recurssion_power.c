#include <stdio.h>

double recurssive(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    double result = recurssive(a, b);
    printf("%lf", result);

    return 0;
}

double recurssive(int a, int b)
{
    if (b == 0)
        return 1;

    if (b < 0)
        return 1.0 / recurssive(a, -b);

    return a * recurssive(a, b - 1);
}
