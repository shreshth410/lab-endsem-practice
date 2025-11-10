#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

typedef struct {
    int rows;
    int cols;
    int numTerms;
    Term terms[MAX_TERMS];
} SparseMatrix;

void fastTranspose(SparseMatrix *a, SparseMatrix *b) {
    int rowSize[MAX_TERMS] = {0};
    int rowStart[MAX_TERMS] = {0};
    int i, j;

    b->rows = a->cols;
    b->cols = a->rows;
    b->numTerms = a->numTerms;

    if (a->numTerms > 0) {
        for (i = 0; i < a->numTerms; i++)
            rowSize[a->terms[i].col]++;

        rowStart[0] = 0;
        for (i = 1; i < a->cols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

        for (i = 0; i < a->numTerms; i++) {
            j = rowStart[a->terms[i].col]++;
            b->terms[j].row = a->terms[i].col;
            b->terms[j].col = a->terms[i].row;
            b->terms[j].value = a->terms[i].value;
        }
    }
}

void printSparseMatrix(SparseMatrix *m) {
    printf("Row Col Value\n");
    for (int i = 0; i < m->numTerms; i++)
        printf("%3d %3d %5d\n", m->terms[i].row, m->terms[i].col, m->terms[i].value);
}

int main() {
    SparseMatrix a = {4, 5, 6, {
        {0, 2, 3},
        {0, 4, 4},
        {1, 2, 5},
        {1, 3, 7},
        {3, 1, 2}, 
        {3, 2, 6}
    }};
    SparseMatrix b;

    printf("Original Matrix (Sparse Representation):\n");
    printSparseMatrix(&a);

    fastTranspose(&a, &b);

    printf("\nTransposed Matrix (Sparse Representation):\n");
    printSparseMatrix(&b);

    return 0;
}