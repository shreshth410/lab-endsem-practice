#include <stdio.h>
int fibarr[1000] = {0};


int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        if (fibarr[n] != 0)
        return fibarr[n];

        else {
            fibarr[n] = fibonacci(n-1) + fibonacci(n-2);
            return fibarr[n];
        }
    }
}

int main(void)
{
    int n;
    printf("Enter number of terms of fibonacci: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", fibonacci(i));
    }
}