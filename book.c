/*#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

void recursiveInsertionSort(struct Book books[], int n) {
    if (n <= 1)
        return;

    recursiveInsertionSort(books, n - 1);

    struct Book last = books[n - 1];
    int j = n - 2;
    while (j >= 0 && books[j].price > last.price) {
        books[j + 1] = books[j];
        j--;
    }
    books[j + 1] = last;
}

int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book books[n];

    // Clear newline after scanf before taking string input
    getchar();

    for (int i = 0; i < n; i++) {
        printf("\nEnter title of book %d: ", i + 1);
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0'; // Remove trailing newline

        printf("Enter author of book %d: ", i + 1);
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Enter price of book %d: ", i + 1);
        scanf("%f", &books[i].price);
        getchar(); // Clear newline before next string input
    }

    recursiveInsertionSort(books, n);

    printf("\nBooks sorted by price:\n");
    for (int i = 0; i < n; i++) {
        printf("Title: %s, Author: %s, Price: %.2f\n",
               books[i].title, books[i].author, books[i].price);
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

void recursiveInsertionSort(struct Book **books, int n) {
    if (n <= 1)
        return;

    recursiveInsertionSort(books, n - 1);

    struct Book *last = books[n - 1];
    int j = n - 2;
    while (j >= 0 && books[j]->price > last->price) {
        books[j + 1] = books[j];
        j--;
    }
    books[j + 1] = last;
}

int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book **books = malloc(n * sizeof(struct Book *));
    if (!books) {
        printf("Memory allocation error\n");
        return 1;
    }

    getchar(); // Clear newline after scanf

    for (int i = 0; i < n; i++) {
        books[i] = malloc(sizeof(struct Book));
        if (!books[i]) {
            printf("Memory allocation error\n");
            return 1;
        }
        printf("\nEnter title of book %d: ", i + 1);
        fgets(books[i]->title, sizeof(books[i]->title), stdin);
        //books[i]->title[strcspn(books[i]->title, "\n")] = '\0';

        printf("Enter author of book %d: ", i + 1);
        fgets(books[i]->author, sizeof(books[i]->author), stdin);
        //books[i]->author[strcspn(books[i]->author, "\n")] = '\0';

        printf("Enter price of book %d: ", i + 1);
        scanf("%f", &books[i]->price);
        getchar(); // Clear newline before next string
    }

    recursiveInsertionSort(books, n);

    printf("\nSorted Books: \n");
    for (int i = 0; i < n; i++) {
        printf("Title: %s, Author: %s, Price: %.2f\n",
               books[i]->title, books[i]->author, books[i]->price);
    }
}