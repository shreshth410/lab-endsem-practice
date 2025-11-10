#include <stdio.h>

int main()
{
    int size, search, largest, temp; 
    printf("Enter size of array: ");
    scanf("%d", &size);

    int array[sizeof(int)*size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &array[i]); 
    }

    largest = array[0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    printf("Enter element to be searched: ");
    scanf("%d", &search);

    int low, high, mid;
    low = 0;
    high = (size-1);
    mid = (high + low)/2;

    /*if (search == array[size-1])
    {
        printf("Element found @ index %d", size-1);
        return 0;
    }*/

    do
    {
        if (search > array[mid])
        {
            low = mid+1;
            mid = (high + low) / 2;
        }
        else if (search < array[mid])
        {
            high = mid - 1;
            mid = (high + low) / 2;
        }
        
    } while (search != array[mid] && low <= high);

    if (search == array[mid])
    {
        printf("Element found @ position %d\n", ++mid);
    }
    else
    {
        printf("ERROR 404:\tElement not found. \n");
    }
}