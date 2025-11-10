#include <stdio.h>

int main()
{
    int A[3][3];
    printf("Enter elements of a 3x3 matrix: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter element %d-%d: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }  
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", A[i][j]);
        }  
        printf("\n");
    }

    int c1sum=0, c2sum=0, c3sum=0,r1sum=0,r2sum=0,r3sum=0,pdiag=0, sdiag=0;

    for (int i = 0, j = 2; i < 3; i++, j--)
    {
        c1sum+=A[i][0];
        c2sum+=A[i][1];
        c3sum+=A[i][2];
        r1sum+=A[0][i];
        r2sum+=A[1][i];
        r3sum+=A[2][i];
        pdiag+=A[i][i];
        sdiag+=A[i][j];

    }

    int sum = c1sum;

    if ((c2sum==sum) && (c3sum==sum) && (r1sum==sum) && (r2sum==sum) && (r3sum==sum) && (pdiag==sum) && (sdiag==sum))
    {
        printf("Metrix is a magic square. \n");
        return 0;
    }

    printf("Matrix is not a magic square. \n");
    return 1;
}
