/*#include <stdio.h>

int main(void)
{
    int m, n, largest, smallest;
    printf("Enter order of matrix(axb): ");
    scanf("%dx%d", &m, &n);

    int A[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter an element: ");
            scanf("%d", &A[i][j]);
        }
    }

    printf("Matrix input: \n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t");
        }
        printf("\n");
    }

    largest = smallest = A[0][0];

    for (int i = 0; i < n; i++)
    {
        
    }
}*/

#include <stdio.h>

#define MAX 100

void readMatrix(int matrix[MAX][MAX], int m, int n) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int m, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX][MAX];
    int m, n;

    // Input matrix size
    printf("Enter the number of rows (M): ");
    scanf("%d", &m);
    printf("Enter the number of columns (N): ");
    scanf("%d", &n);

    // Read the matrix
    readMatrix(matrix, m, n);
    
    // Display the original matrix
    displayMatrix(matrix, m, n);

    int found = 0; // Flag to track if any element is modified

    // Process the matrix to find and replace elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isLargestInCol = 1;
            int isSmallestInRow = 1;

            // Check if the element is the largest in its column
            for (int k = 0; k < m; k++) {
                if (matrix[k][j] > matrix[i][j]) {
                    isLargestInCol = 0;
                    break;
                }
            }

            // Check if the element is the smallest in its row
            for (int k = 0; k < n; k++) {
                if (matrix[i][k] < matrix[i][j]) {
                    isSmallestInRow = 0;
                    break;
                }
            }

            // If the element is both largest in column and smallest in row
            if (isLargestInCol && isSmallestInRow) {
                found = 1;

                // Calculate the row average
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += matrix[i][k];
                }
                int average = sum / n;

                // Replace the element with the row average
                matrix[i][j] = average;
            }
        }
    }

    // Display the modified matrix
    if (found) {
        printf("Modified matrix:\n");
        displayMatrix(matrix, m, n);
    } else {
        printf("No elements found that are both the largest in their column and the smallest in their row.\n");
    }

    return 0;
}