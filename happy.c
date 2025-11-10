#include <stdio.h>

int main(void)
{
    int n, rem = 0, dig, new; 
    printf("Enter number: ");
    scanf("%d", &n);
    new = n;

    do
    {
        rem = 0;
        while(new > 0)
        {
            dig = new%10;
            int x = dig*dig;
            rem+=x;
            new=new/10;
        }
        if (rem < 10)
        {
            break;
        }
        else
        {
            new = rem;
        }
    } while (new >= 10);
    
    if (rem == 1)
    printf("Happy number");
    else
    printf("Not a happy number");
    
}