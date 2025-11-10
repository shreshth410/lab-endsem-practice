#include <stdio.h>

int main(void)
{
    char string[100], *ptr;
    printf("Enter string: ");
    scanf("%s", &string);

    ptr = &string[0];
    int length = 0;
    while (*ptr != '\0')
    {
        ptr++;
        length++;
    }
    int vowel = 0, cons = 0;

    for (int i = 0; i < length; i++)
    {
        if (string[i] == 'a'||string[i] == 'A'|| string[i] == 'e'|| string[i] == 'E'|| string[i] == 'i'|| string[i] == 'I'|| string[i] == 'o'|| string[i] == 'O'|| string[i] == 'u'|| string[i] == 'U')
        {
            vowel++;
        }
        else 
        {
            cons++;
        }
    }

    printf("Vowels: %d\nConsonants: %d", vowel, cons);
}