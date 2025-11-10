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
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    char order;
    printf("Enter 'a' for ascending or 'd' for descending: ");
    scanf(" %c", &order);

    switch (order) 
    {
        case 'a':
        case 'A':
            // Bubble sort in ascending order
            for (int i = 0; i < n; ++i) 
            {
                for (int j = 0; j < n - i - 1; ++j) 
                {
                    if (arr[j] > arr[j + 1]) 
                    {
                        // Swap elements
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            break;

        case 'd':
        case 'D':
            // Bubble sort in descending order
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n - i - 1; ++j) 
                {
                    if (arr[j] < arr[j + 1]) 
                    {
                        // Swap elements
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            break;

        default:
            printf("Invalid input. Please enter 'a' or 'd'.\n");
            return 1;
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
