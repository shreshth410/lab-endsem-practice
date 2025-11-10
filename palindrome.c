#include <stdio.h>
#include <string.h>

int main()
{
    char string[50];

    printf("Enter string: ");
    scanf("%s", &string);

    int size = strlen(string);
    char rev[size];

    for (int i = 0; i < size; i++)
    {
        rev[i] = string[size-i-1];
    }

    for (int i = 0; i < size; i++)
    {
        if (rev[i] != string[i])
        {
            printf("Not a palindrome.");
            return 1;
        }
    }
    printf("String is a palindrome. ");
    return 0;
}