#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Prime numbers in the array:\n");
    for (int i = 0; i < n; ++i) 
    {
        int is_prime = 1;
        for (int j = 2; j * j <= arr[i]; ++j) 
        {
            if (arr[i] % j == 0) 
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) 
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}