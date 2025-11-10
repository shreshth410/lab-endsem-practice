#include <stdio.h>

int main(void)
{
    int size, tester;

    printf("Enter size of array: ");
    scanf("%d", &size);
    int array[sizeof(int)*size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &array[i]);
    }

    tester = array[0];

    for (int j = 0; j < size; j++)
    {
         if (array[j] < tester)
         {
            tester = array[j];
         }

    }
    printf("Smallest element is: %d\n", tester);

    tester = array[0];

    for (int k = 0; k < size; k++)
    {
        if (array[k] > tester)
        {
            tester = array[k];
        }
    }
    printf("Largest element is: %d\n", tester);
}