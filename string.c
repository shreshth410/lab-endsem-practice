#include <stdio.h>

int main(void)
{
    char string[100];
    printf("Enter a string: ");
    scanf("%s", &string);

    char* ptr = &string[0];
    int len=0;
    while (*ptr != '\0')
    {
        len++;
        ptr++;
    }
    char string_new[len];

    for (int i = 0, j = len-1; i < len; i++, j--)
    {
        string_new[i] = string[j];
    }

    for (int i = 0;i < len; i++)
    {
        printf("%c", string_new[i]);
    }
}
