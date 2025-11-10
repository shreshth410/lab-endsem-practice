#include <stdio.h>

int main() {
    int n, num = 1;

    // Input the number of rows
    printf("Enter the number of rows for Floyd's triangle: ");
    scanf("%d", &n);

    // Generate Floyd's triangle
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}
