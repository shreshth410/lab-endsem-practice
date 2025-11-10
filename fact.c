#include <stdio.h>

long int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n*fact(n-1));
    }
}


int main(void)
{
    int n;
    printf("Enter number for factorial: ");
    scanf("%d", &n);

    printf("Factorial of %d is %li. \n", n, fact(n));
}