#include <stdio.h>

int main()
{
    int size, search;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    for (int i = 0; i < size; i++)
    {
        if (array[i] == search)
        {
            printf("Element found @ index %d. \n", i+1);
            return 1;
        }
    }

    printf("Element not found. \n");

    return 0;
}