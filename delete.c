#include <stdio.h>

int main()
{
    int size, delete, del_index;

    printf("Enter size of array: ");
    scanf("%d", &size);
    int array[sizeof(int)*size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &array[i]);
    }

    printf("Enter element to delete: ");
    scanf("%d", &delete);
    del_index = (-1);

    for (int j = 0; j < size; j++)
    {
        if (array[j] == delete)
        {
            del_index = j;
            break;
        }
    }
    if (del_index == -1)
    {
        printf("Element not found.");
        return 1;
    }
    printf("Remaining elements are: \n");

    for (int k = 0; k < del_index; k++)
    printf("%d\n", array[k]);

    for (int l = del_index + 1;l < size; l++)
    printf("%d\n", array[l]);
    return 0;
}